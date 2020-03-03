/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "keymap_jp.h"
#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ortho_4x12( \
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_AT, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, JP_COLN, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT , \
    KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC,  KC_SPC,   RAISE,    JP_HENK, KC_RALT, KC_BSPACE,   KC_ENT \
    ),
[_LOWER] = LAYOUT_ortho_4x12(
    _______,   KC_F7,   KC_F8,    KC_F9, JP_SLSH, _______, _______, _______, KC_7, KC_8,   KC_9,    JP_SLSH,
    _______,   KC_F4,   KC_F5,    KC_F6, JP_ASTR, _______, _______, _______, KC_4, KC_5,   KC_6,    JP_ASTR,
    _______,   KC_F1,   KC_F2,    KC_F3, JP_MINS,KC_ENTER, _______, _______, KC_1, KC_2,   KC_3,    JP_MINS,
    _______, _______, _______,  _______, _______, _______, _______, _______, KC_0, KC_DOT, JP_PLUS,  KC_ENT
    ),
[_RAISE] = LAYOUT_ortho_4x12(
    _______,JP_EXLM,  JP_DQT, JP_HASH,  JP_DLR, JP_PERC,   JP_YEN, _______, _______, _______, _______, KC_BSPACE,
    _______,JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_CIRC,   _______, _______, _______,   KC_UP, _______, _______, 
    _______,JP_LBRC, JP_RBRC, JP_UNDS, JP_LCBR, JP_RCBR,   _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, 
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______
    ),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, BL_TOGG, BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

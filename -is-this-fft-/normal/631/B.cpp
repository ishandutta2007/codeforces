#include <iostream>

const int MAX_ROW = 5005;
const char newl = '\n';

using namespace std;

struct color {
  int val, age;

  color () {
    val = 0;
    age = -1;
  }
};

color rows [MAX_ROW];
color cols [MAX_ROW];

int main () {
  int height, width;
  cin >> height >> width;

  int queryc;
  cin >> queryc;

  for (int i = 0; i < queryc; i++) {
    int query, ind, val;
    cin >> query >> ind >> val;

    if (query == 1) {
      rows[ind].val = val;
      rows[ind].age = i;
    } else if (query == 2) {
      cols[ind].val = val;
      cols[ind].age = i;
    }
  }

  for (int r = 1; r <= height; r++) {
    for (int c = 1; c <= width; c++) {
      if (rows[r].age > cols[c].age) {
	cout << rows[r].val << (c == width ? '\n' : ' ');
      } else {
	cout << cols[c].val << (c == width ? '\n' : ' ');
      }
    }
  }
}
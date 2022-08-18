#include <iostream>

using namespace std;

const int rval [10] = {-1, 2, 3, -1, 5, 6, -1, 8, 9, -1};
const int lval [10] = {-1, -1, 1, 2, -1, 4, 5, -1, 7, 8};
const int uval [10] = {8, -1, -1, -1, 1, 2, 3, 4, 5, 6};
const int dval [10] = {-1, 4, 5, 6, 7, 8, 9, -1, 0, -1};

int main () {
  ios::sync_with_stdio(false);

  bool rsh = false, lsh = false, ush = false, dsh = false;
  
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    char cur;
    cin >> cur;

    int num = cur - '0';
    if (rval[num] == -1) {
      rsh = true;
    }

    if (lval[num] == -1) {
      lsh = true;
    }

    if (uval[num] == -1) {
      ush = true;
    }

    if (dval[num] == -1) {
      dsh = true;
    }
  }
  
  cout << (!(rsh & lsh & ush & dsh) ? "NO" : "YES") << endl;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve () {
  string s;
  cin >> s;

  reverse(s.begin(), s.end());

  int ac = 0, bc = 0;
  for (char c : s) {
    if (c == 'A') {
      if (bc == 0) {
        ac++;
      } else {
        bc--;
      }
    } else {
      bc++;
    }
  }

  bc %= 2;
  cout << ac + bc << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  
  for (int t = 0; t < testc; t++) {
    solve();
  }
}
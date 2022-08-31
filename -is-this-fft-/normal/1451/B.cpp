#include <iostream>

using namespace std;

bool find_lft (const string &s, int pos, char val) {
  for (int i = pos; i >= 0; i--) {
    if (s[i] == val) {
      return true;
    }
  }
  return false;
}

bool find_rgt (const string &s, int pos, char val) {
  for (int i = pos; i < (int) s.size(); i++) {
    if (s[i] == val) {
      return true;
    }
  }
  return false;
}

void solve () {
  int n, qc;
  cin >> n >> qc;

  string s;
  cin >> s;

  for (int i = 0; i < qc; i++) {
    int l, r;
    cin >> l >> r;
    l--; r--;

    bool can_left = find_lft(s, l - 1, s[l]);
    bool can_right = find_rgt(s, r + 1, s[r]);
    if (can_left || can_right) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}
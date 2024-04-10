#include <iostream>

using namespace std;

bool check (const string &s) {
  int bal = 0;
  for (char c : s) {
    if (c == '(') {
      bal++;
    } else {
      bal--;
    }
    if (bal < 0) {
      return false;
    }
  }
  return bal == 0;
}

void solve () {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int c1 = 0;
  for (char c : s) {
    if (c == '1') {
      c1++;
    }
  }

  if (c1 % 2 == 1) {
    cout << "NO" << '\n';
    return;
  }

  int ol = c1 / 2;
  bool turn = false;
  string a, b;
  for (char c : s) {
    if (c == '1') {
      if (ol > 0) {
        a.push_back('(');
        b.push_back('(');
        ol--;
      } else {
        a.push_back(')');
        b.push_back(')');
      }
    } else {
      if (turn) {
        a.push_back('(');
        b.push_back(')');
      } else {
        a.push_back(')');
        b.push_back('(');
      }
      turn = !turn;
    }
  }

  if (check(a) && check(b)) {
    cout << "YES" << '\n';
    cout << a << '\n';
    cout << b << '\n';
  } else {
    cout << "NO" << '\n';
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
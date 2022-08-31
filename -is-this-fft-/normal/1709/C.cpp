#include <iostream>

using namespace std;

bool is_ok (string s) {
  int bal = 0;
  for (char c : s) {
    if (c == '(') bal++;
    if (c == ')') bal--;
    if (bal < 0) return false;
  }
  return bal == 0;
}

void solve () {
  string s;
  cin >> s;

  int n = s.size(), numq = 0, bal = 0;
  for (char c : s) {
    if (c == '(') bal++;
    if (c == ')') bal--;
    if (c == '?') numq++;
  }

  if (numq - bal < 0 || (numq - bal) % 2 != 0) {
    cout << "NO" << '\n';
    return;
  }

  int opc = (numq - bal) / 2;
  if (opc > numq) {
    cout << "NO" << '\n';
    return;
  }

  int last_op = -1, first_cl = -1;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (c == '?') {
      if (opc > 0) {
        s[i] = '(';
        opc--;
        if (opc == 0) {
          last_op = i;
        }
      } else {
        s[i] = ')';
        if (first_cl == -1) {
          first_cl = i;
        }
      }
    }
  }

  if (!is_ok(s)) {
    cout << "NO" << '\n';
    return;
  }

  if (last_op == -1 || first_cl == -1) {
    cout << "YES" << '\n';
    return;
  }

  swap(s[last_op], s[first_cl]);
  if (is_ok(s)) {
    cout << "NO" << '\n';
    return;
  }

  cout << "YES" << '\n';
  return;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}
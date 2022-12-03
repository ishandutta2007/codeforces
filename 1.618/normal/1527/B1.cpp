/*


Q.E.D.

start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

void solve() {
  int n;
  string s;
  cin >> n >> s;
  int tot = 0, num0 = count(s.begin(), s.end(), '0');
  for (int i = 0; i < n - 1 - i; i++)
    tot += (s[i] != s[n - 1 - i]);
  if (tot == 0) {
    if (num0 >= 3 && (num0 & 1) && s[n / 2] == '0')
      puts("ALICE");
    else
      puts("BOB");
  } else if (tot >= 2) {
    puts("ALICE");
  } else if (num0 & 1) {
    puts("ALICE");
  } else {
    puts("DRAW");
  }
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
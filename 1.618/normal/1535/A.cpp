/*


Q.E.D.

start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

int s[5], t[5];
void solve() {
  for (int i = 1; i <= 4; i++) {
    scanf("%d", s + i);
    t[i] = s[i];
  }
  sort(t + 1, t + 5);
  int a = max(s[1], s[2]), b = max(s[3], s[4]);
  if (a > b)
    swap(a, b);
  puts(a == t[3] && b == t[4] ? "YES" : "NO");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
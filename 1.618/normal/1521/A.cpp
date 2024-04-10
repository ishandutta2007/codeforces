/*


Q.E.D.
*/
/*
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
  ll a, b;
  scanf("%lld%lld", &a, &b);
  if (b == 1) {
    puts("NO");
  } else {
    puts("YES");
    printf("%lld %lld %lld\n", a, (2 * b - 1) * a, 2 * b * a);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
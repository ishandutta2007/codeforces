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
  ll n;
  scanf("%lld", &n);
  if (n % 2050) {
    puts("-1");
    return;
  }
  n /= 2050;
  int ans = 0;
  while (n) {
    ans += n % 10;
    n /= 10;
  }
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve(); 
  return 0;
}
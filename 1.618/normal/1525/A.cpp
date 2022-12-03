/*


Q.E.D.

start thinking:
BULB:
result of thinking:

#vp

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
  scanf("%d", &n);
  printf("%d\n", 100 / __gcd(n, 100));
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve(); 
  return 0;
}
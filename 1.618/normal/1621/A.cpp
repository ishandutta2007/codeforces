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
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  if ((n + 1) / 2 < k) {
    puts("-1");
    return;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j && (i & 1) && i <= 2 * k) {
        printf("R");
      } else {
        printf(".");
      }
    }
    puts("");
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
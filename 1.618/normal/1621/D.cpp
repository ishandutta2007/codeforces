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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n;
ll c[505][505];

void solve() {
  ll ans1 = 0;
  scanf("%d", &n);
  for (int i = 1; i <= (n << 1); i++) {
    for (int j = 1; j <= (n << 1); j++) {
      scanf("%lld", &c[i][j]);
      if (i > n && j > n) {
        ans1 += c[i][j];
        c[i][j] = 0;
      }
    }
  }
  ll ans2 = min(min(min(c[1][n + 1], c[1][n * 2]), min(c[n][n + 1], c[n][n * 2])),
                min(min(c[n + 1][1], c[n + 1][n]), min(c[n * 2][1], c[n * 2][n])));
  printf("%lld\n", ans1 + ans2);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
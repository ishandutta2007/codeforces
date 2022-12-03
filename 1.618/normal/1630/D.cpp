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

#define maxn 1000005
int b, n, m, a[maxn], minAbs[maxn], negNum[maxn];

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  scanf("%d", &b);
  for (int i = 2; i <= m; i++) {
    int foo;
    scanf("%d", &foo);
    b = __gcd(b, foo);
  }
  for (int i = 0; i < b; i++) {
    negNum[i] = 0;
    minAbs[i] = inf;
  }
  for (int i = 1; i <= n; i++) {
    chmin(minAbs[i % b], abs(a[i]));
    negNum[i % b] ^= a[i] < 0;
  }
  ll odd = 0, even = 0;
  for (int i = 0; i < b; i++) {
    if (negNum[i] & 1) {
      odd += minAbs[i];
    } else {
      even += minAbs[i];
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    ans += abs(a[i]);
  printf("%lld\n", ans - 2 * min(odd, even));
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
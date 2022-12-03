/*
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
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 105
int n, a[maxn], b[maxn];
bool f[20005];

void solve() {
  scanf("%d", &n);
  int tot = 0;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    tot += a[i];
    ans += a[i] * a[i];
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
    tot += b[i];
    ans += b[i] * b[i];
  }
  memset(f, 0, sizeof(f));
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 20000; j >= 0; j--) {
      f[j] = 0;
      if (j >= a[i])
        f[j] |= f[j - a[i]];
      if (j >= b[i])
        f[j] |= f[j - b[i]];
    }
  }
  ans *= n - 2;
  for (int i = tot / 2; i >= 0; i--) {
    if (f[i]) {
      printf("%lld\n", ans + i * i + (tot - i) * (tot - i));
      return;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) 
    solve();
  return 0;
}
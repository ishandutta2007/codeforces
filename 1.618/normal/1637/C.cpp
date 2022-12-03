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

#define maxn 100005
int n, a[maxn];

void solve() {
  scanf("%d", &n);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (i > 1 && i < n)
      ans += (a[i] + 1) / 2;
  }
  if (*max_element(a + 2, a + n) == 1) {
    puts("-1");
    return;
  }
  if (n == 3 && a[2] & 1) {
    puts("-1");
    return;
  }
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) 
    solve();
  return 0;
}
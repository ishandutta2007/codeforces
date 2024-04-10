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

#define maxn 75
int n, a[maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  if (n == 1) {
    puts("0");
    return;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int res = 0;
      for (int k = 1; k <= n; k++) {
        res += (a[i] * (j - i) + (k - i) * (a[j] - a[i]) == a[k] * (j - i));
      }
      chmax(ans, res);
    }
  }
  printf("%d\n", n - ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
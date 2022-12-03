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
template <class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 5005
int n, a[maxn];

ll solve(int c) {
  ll foo = 0, ans = 0;
  for (int i = c + 1; i <= n; i++) {
    ans += foo / a[i] + 1;
    foo = (foo / a[i] + 1) * a[i];
  }
  foo = 0;
  for (int i = c - 1; i >= 1; i--) {
    ans += foo / a[i] + 1;
    foo = (foo / a[i] + 1) * a[i];
  }
  return ans;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  ll ans = infll;
  for (int i = 1; i <= n; i++)
    chmin(ans, solve(i));
  printf("%lld\n", ans);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}
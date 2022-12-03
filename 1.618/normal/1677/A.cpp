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
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 5005
int n, p[maxn], sum[maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", p + i);
  ll ans = 0;
  for (int c = 1; c <= n; c++) {
    memset(sum, 0, sizeof(sum));
    for (int i = c + 1; i <= n; i++)
      sum[p[i]] = 1;
    for (int i = 1; i <= n; i++)
      sum[i] += sum[i - 1];
    ll foo = 0;
    for (int a = c - 1; a >= 1; a--) {
      if (p[a] < p[c])
        ans += foo;
      foo += sum[p[a]];
    }
  }
  printf("%lld\n", ans);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}
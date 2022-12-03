/*
start thinking:
BULB:
result of thinking: Pure.

, .
 p[1], p[2], ..., p[n]  DecInc, ,
 edInc = 0, edDec = inf.
 edInc < edDec ,  (edInc, edDec)  p[i] ,
 sgn(p[i + 1] - p[i]) .
p[i] < edInc || p[i] > edDec ,  edInc > edDec .
two pointers, r  l  p[l, r]  edInc < edDec .
 l  r  polylog.

start coding: 17:53
AC:

official sol:
f(l, r): partition(p[l, r]), p[r] is edInc, max edDec?
g(l, r): partition(p[l, r]), p[r] is edDec, min edInc?
Apparently we have trans:
chmax(f(l, r + 1), f(l, r)) if p[r] < p[r + 1];
chmax(f(l, r + 1), p[r]) if g(l, r) < p[r + 1].
l from n downto 1
  recalc f(l, l...n) as f[l...n] (*)
  when f[i] doesn't change, break
  similarly to g[].
every iteration in (*) change something, while f[], g[] won't change too many
times during the whole algorithm.
Therefore, O(n).
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

#define maxn 200005
// f(l, r): partition(p[l, r]), p[r] is edInc, max edDec?
// g(l, r): partition(p[l, r]), p[r] is edDec, min edInc?
int n, p[maxn], f[maxn], g[maxn], cur;
ll ans;

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", p + i);
  for (int i = n; i >= 1; i--) {
    f[i] = n + 1, g[i] = 0;
    cur++;
    for (int j = i + 1; j <= n; j++) {
      cur -= f[j] || g[j] <= n;
      int _f = 0, _g = n + 1;
      if (p[j - 1] < p[j])
        chmax(_f, f[j - 1]);
      if (g[j - 1] < p[j])
        chmax(_f, p[j - 1]);
      if (p[j - 1] > p[j])
        chmin(_g, g[j - 1]);
      if (f[j - 1] > p[j])
        chmin(_g, p[j - 1]);
      cur += _f || _g <= n;
      if (_f == f[j] && _g == g[j])
        break;
      f[j] = _f, g[j] = _g;
    }
    ans += cur;
  }
  printf("%lld\n", ans);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}
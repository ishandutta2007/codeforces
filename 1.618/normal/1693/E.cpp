/*
start thinking:
BULB:
result of thinking: Lost.

 () .
.  v (v > 0) ,
\forall i, a[i] = v , .
 https://codeforces.com/blog/entry/103952?#comment-923531

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

#define maxn 200005
int n, a[maxn], bit[maxn];
vector<int> pos[maxn];

void add(int pos, int x) {
  for (int i = pos; i <= n; i += i & -i)
    bit[i] += x;
}
int qsum(int pos) {
  int res = 0;
  for (int i = pos; i; i -= i & -i)
    res += bit[i];
  return res;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    pos[a[i]].push_back(i);
  }
  ll ans = 0;
  for (int i = n, l = 1, r = n + 1; i; i--) {
    if (pos[i].empty())
      continue;
    tie(l, r) = mp(min(pos[i].front(), r), max(pos[i].back() + 1, l));
    for (auto j : pos[i])
      add(j, 1);
    ans += qsum(r - 1) - qsum(l - 1);
  }
  printf("%lld\n", ans);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}
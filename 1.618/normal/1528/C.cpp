/*


Q.E.D.

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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define mp make_pair
#define maxn 300005
typedef pair<int, int> P;

int n, dfn[maxn], siz[maxn], ind, ans;
vector<int> sor[maxn], kes[maxn];
set<P> S;

void dfs1(int u, int f) {
  dfn[u] = ++ind;
  siz[u] = 1;
  for (auto v : kes[u]) {
    if (v == f)
      continue;
    dfs1(v, u);
    siz[u] += siz[v];
  }
}

void dfs2(int u, int f, int res) {
  chmax(ans, res);
  for (auto v : sor[u]) {
    if (v == f)
      continue;
    int l = dfn[v], r = dfn[v] + siz[v] - 1;
    bool del = false;
    auto it = S.lower_bound(mp(l, r));
    if (it != S.begin()) {
      --it;
      if (it->second >= r)
        del = true;
    }
    if (del) {
      P tmp = *it;
      S.erase(tmp);
      S.insert(mp(l, r));
      dfs2(v, u, res);
      S.erase(mp(l, r));
      S.insert(tmp);
    } else {
      S.insert(mp(l, r));
      dfs2(v, u, res + 1);
      S.erase(mp(l, r));
    }
  }
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    sor[i].clear();
    kes[i].clear();
  }
  for (int i = 2; i <= n; i++) {
    int a;
    scanf("%d", &a);
    sor[a].push_back(i);
    sor[i].push_back(a);
  }
  for (int i = 2; i <= n; i++) {
    int b;
    scanf("%d", &b);
    kes[b].push_back(i);
    kes[i].push_back(b);
  }
  ind = 0;
  dfs1(1, 0);
  S.clear();
  S.insert(mp(1, n));
  ans = 0;
  dfs2(1, 0, 1);
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
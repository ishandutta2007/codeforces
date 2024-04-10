/*


Q.E.D.

result of thinking: -

swapstlO(1)

dpdp
.
.

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
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 1000005
int n;
vector<int> adj[maxn];

int hei[maxn], son[maxn];

void dfs1(int u, int p) {
  for (auto v : adj[u]) {
    if (v == p)
      continue;
    dfs1(v, u);
    if (chmax(hei[u], hei[v] + 1))
      son[u] = v;
  }
}

int ind, pool[maxn], *f[maxn];

void dfs2(int u, int t, int p) {
  f[u] = pool + (++ind);
  if (son[u]) {
    dfs2(son[u], t, u);
  }
  for (auto v : adj[u]) {
    if (v != p && v != son[u])
      dfs2(v, v, u);
  }
}

// (num, -dep)
P ans[maxn];

void dp(int u, int p) {
  f[u][0] = 1;
  ans[u] = mp(1, 0);
  if (son[u]) {
    dp(son[u], u);
    if (ans[son[u]].first > ans[u].first)
      ans[u] = mp(ans[son[u]].first, ans[son[u]].second - 1);
  }
  for (auto v : adj[u]) {
    if (v != p && v != son[u]) {
      dp(v, u);
      for (int i = 0; i <= hei[v]; i++) {
        f[u][i + 1] += f[v][i];
        chmax(ans[u], mp(f[u][i + 1], -i - 1));
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 1, 0);
  dp(1, 0);
  for (int i = 1; i <= n; i++) {
    printf("%d\n", -ans[i].second);
  }
  return 0;
}
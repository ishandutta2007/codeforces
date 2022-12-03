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

#define maxn 200005
int n, dfn[maxn], siz[maxn], ind;
vector<int> adj[maxn];
ll ans[maxn];

void dfs(int u, int f) {
  dfn[u] = ++ind;
  siz[u] = 1;
  for (auto v : adj[u]) {
    if (v == f)
      continue;
    dfs(v, u);
    siz[u] += siz[v];
  }
}

ll c2(int x) {
  return (ll)x * (x - 1) / 2;
}

bool have(int u, int v) { // uv? 
  return dfn[u] <= dfn[v] && dfn[v] < dfn[u] + siz[u];
}

int label[maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    adj[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ind = 0;
  dfs(0, n);
  
  ans[0] = ans[1] = c2(n);
  for (auto v : adj[0])
    ans[1] -= c2(siz[v]);
  int p = 0, q = 1, son;
  for (auto v : adj[0]) {
    if (have(v, 1))
      son = v;
    for (int i = dfn[v]; i < dfn[v] + siz[v]; i++)
      label[i] = v;
  }
  ans[2] = (ll)siz[1] * (n - siz[son]);
  for (int i = 2; i < n; i++) {
    if (p == 0) {
      if (have(i, q)) {
        ans[i + 1] = (ll)siz[q] * (n - siz[son]);
      } else if (have(q, i)) {
        q = i;
        ans[i + 1] = (ll)siz[q] * (n - siz[son]);
      } else if (label[dfn[i]] != son) {
        p = i;
        ans[i + 1] = (ll)siz[p] * siz[q];
      } else {
        break;
      }
    } else {
      if (have(i, p) || have(i, q)) {
        ans[i + 1] = (ll)siz[p] * siz[q];
      } else if (have(p, i)) {
        p = i;
        ans[i + 1] = (ll)siz[p] * siz[q];
      } else if (have(q, i)) {
        q = i;
        ans[i + 1] = (ll)siz[p] * siz[q];
      } else {
        break;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    printf("%lld%c", ans[i] - ans[i + 1], i == n ? '\n' : ' ');
  }
  for (int i = 0; i <= n; i++)
    ans[i] = 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}
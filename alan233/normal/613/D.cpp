// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 100005;

vector<int> adj[N], go[N];
int dfn[N], dtot, dep[N], jp[N][18], n, q;
int used[N], a[N], k1, m, stk[N], top;

void dfs1(int u, int fa) {
  dfn[u] = ++dtot;
  dep[u] = dep[fa] + 1;
  jp[u][0] = fa;
  for (int i = 1; i < 18; i++) jp[u][i] = jp[jp[u][i - 1]][i - 1];
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
  }
}
inline int LCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 17; i >= 0; i--) if (dep[jp[u][i]] >= dep[v]) u = jp[u][i];
  if (u == v) return u;
  for (int i = 17; i >= 0; i--) if (jp[u][i] != jp[v][i]) u = jp[u][i], v = jp[v][i];
  return jp[u][0];
}

vector<int> special;
void ins(int u) {
  special.pb(u);
  if (!top) { stk[++top] = u; return ; }
  int lca = LCA(u, stk[top]);
  special.pb(lca);
  while (top > 1 && dfn[lca] < dfn[stk[top - 1]]) {
    go[stk[top - 1]].pb(stk[top]);
    --top;
  }
  if (top && dfn[lca] < dfn[stk[top]]) {
    go[lca].pb(stk[top]);
    --top;
  }
  if (stk[top] != lca) stk[++top] = lca;
  stk[++top] = u;
}
void clr() {
  for (auto v: special) go[v].clear();
  rep(i, 1, k1) used[a[i]] = false;
  special.clear();
}

int ans;
int DP(int u) {
  int sum = 0;
  for (auto v: go[u]) sum += DP(v);
//  printf("DP u = %d, sum = %d, ans = %d, used = %d\n", u, sum, ans, used[u]);
  if (used[u]) {
    ans += sum;
    return 1;
  } else {
    if (sum > 1) {
      ans++;
      return 0;
    } else {
      return sum;
    }
  }
}

int main() {
  n = read();
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs1(1, 0);
//  for (int i = 1; i <= n; i++) {
//    for (int j = i + 1; j <= n; j++) {
//      printf("lca(%d, %d) = %d\n", i, j, LCA(i, j));
//    }
//  }
  q = read();
  while (q--) {
    k1 = read(), m = 0;
    rep(i, 1, k1) a[i] = read();
    sort(a + 1, a + k1 + 1, [&](int x, int y) { return dfn[x] < dfn[y]; });
    top = 0;
    rep(i, 1, k1) {
      ins(a[i]), used[a[i]] = true;
//      rep(j, 1, top) printf("%d ", stk[j]);
//      puts("");
    }
    bool ok = 1;
    rep(i, 1, k1) {
      if (used[jp[a[i]][0]]) {
        ok = 0;
        break;
      }
    }
    if (!ok) {
      puts("-1");
      clr();
      continue;
    }
    int root = stk[1];
//    printf("root = %d\n", root);
    while (top) {
      go[stk[top - 1]].pb(stk[top]);
      --top;
    }
//    for (int i = 1; i <= n; i++) {
//      printf("go[%d] = ", i);
//      for (auto v: go[i]) printf("%3d", v);
//      puts("");
//    }
    ans = 0, DP(root);
    print(ans, '\n');
    clr();
  }
  return 0;
}
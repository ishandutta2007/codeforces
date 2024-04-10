#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
inline void print(int x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int K = 17;
constexpr int N = 1e5 + 5;
constexpr int V = 1e7 + 5;
constexpr int P = 7e5 + 5;
constexpr int mod = 1e9 + 7;
inline int ksm(int a, int b) {
  int s = 1;
  while(b) {
    if(b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return s;
}
bool vis[V];
int cnt, pr[P], bel[V];
void sieve() {
  for(int i = 2; i < V; i++) {
    if(!vis[i]) pr[++cnt] = i, bel[i] = cnt;
    for(int j = 1; j <= cnt && i * pr[j] < V; j++) {
      vis[i * pr[j]] = 1;
      if(i % pr[j] == 0) break;
    }
  }
  assert(cnt < P);
}
vector<pii> buc[P], qu[P];
vector<int> e[N];
int n, q, lg[N], f[N][25], fa[N]; // K -> 25
int x[N], y[N], ans[N];
int dn, dfn[N], dep[N], mi[K][N];
int get(int x, int y) {return dep[x] < dep[y] ? x : y;}
void dfs(int id, int ff) {
  dep[id] = dep[ff] + 1;
  mi[0][dfn[id] = ++dn] = ff;
  for(int it : e[id]) if(it != ff) dfs(it, id);
}
int lca(int x, int y) {
  if(x == y) return x;
  if((x = dfn[x]) > (y = dfn[y])) swap(x, y);
  int d = lg[y - x++];
  return get(mi[d][x], mi[d][y - (1 << d) + 1]);
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  sieve();
  for(int i = 2; i < N; i++) lg[i] = lg[i >> 1] + 1;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  for(int i = 1; i <= lg[n]; i++)
    for(int j = 1; j + (1 << i) - 1 <= n; j++)
      mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
  for(int i = 1, v; i <= n; i++) {
    cin >> v;
    for(int j = 1; j <= cnt && pr[j] * pr[j] <= v; j++)
      if(v % pr[j] == 0) {
        int cnt = 0;
        while(v % pr[j] == 0) v /= pr[j], cnt++;
        buc[j].push_back({i, cnt});
      }
    if(v > 1) buc[bel[v]].push_back({i, 1});
  }
  cin >> q;
  for(int i = 1, v; i <= q; i++) {
    ans[i] = 1;
    cin >> x[i] >> y[i] >> v;
    for(int j = 1; j <= cnt && pr[j] * pr[j] <= v; j++)
      if(v % pr[j] == 0) {
        int cnt = 0;
        while(v % pr[j] == 0) v /= pr[j], cnt++;
        qu[j].push_back({i, cnt});
      }
    if(v > 1) qu[bel[v]].push_back({i, 1});
  }
  for(int _ = 1; _ <= cnt; _++) {
    static int p[N * 3], stc[N];
    int cnt = 0, mx = 0, top = 0;
    for(pii it : buc[_]) p[++cnt] = it.first, mx = max(mx, it.second);
    for(pii it : qu[_]) p[++cnt] = x[it.first], p[++cnt] = y[it.first];
    sort(p + 1, p + cnt + 1, [&](int x, int y) {return dfn[x] < dfn[y];});
    cnt = unique(p + 1, p + cnt + 1) - p - 1;
    stc[top = 1] = p[1];
    int ext = cnt;
    for(int i = 2; i <= cnt; i++) {
      int d = lca(stc[top], p[i]);
      while(top > 1 && dep[d] <= dep[stc[top - 1]]) fa[stc[top]] = stc[top - 1], top--;
      if(d != stc[top]) fa[stc[top]] = p[++ext] = d, stc[top] = d;
      stc[++top] = p[i];
    }
    fa[stc[1]] = 0;
    for(int i = 2; i <= top; i++) fa[stc[i]] = stc[i - 1];
    sort(p + 1, p + ext + 1, [&](int x, int y) {return dfn[x] < dfn[y];});
    for(int i = 1; i <= ext; i++) memset(f[p[i]], 0, sizeof(f[p[i]]));
    for(pii it : buc[_]) f[it.first][it.second] = 1;
    for(int i = 1; i <= ext; i++)
      for(int j = 1; j <= mx; j++)
        f[p[i]][j] += f[fa[p[i]]][j];
    for(pii it : qu[_]) {
      int pw = 0, id = it.first, d = lca(x[id], y[id]);
      for(int j = 1; j <= mx; j++)
        pw += min(it.second, j) * (f[x[id]][j] + f[y[id]][j] - f[d][j] - f[fa[d]][j]);
      ans[id] = 1ll * ans[id] * ksm(pr[_], pw) % mod;
    }
  }
  for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/9/1
author: Alex_Wei
start coding at 14:35
finish debugging at 14:57
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using pii = pair<int, int>;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
bool Mbe;
constexpr int K = 19;
constexpr int N = 3e5 + 5;
int n, m, q, R, bel[N], comp[N];
int rot(int x) {return (x + R - 1) % n + 1;}
struct E_BCC {
  vector<int> S;
  vector<pii> e[N];
  bool in[N];
  int cnt, dn, dfn[N], low[N], cn, col[N], top, stc[N];
  void add(int u, int v) {
    if(u == v) return;
    // cout << u << " " << v << "\n";
    if(!in[u]) S.push_back(u), in[u] = 1;
    if(!in[v]) S.push_back(v), in[v] = 1;
    e[u].push_back({v, ++cnt});
    e[v].push_back({u, cnt});
  }
  void clear() {
    cnt = dn = cn = 0;
    for(int it : S) e[it].clear(), dfn[it] = 0, in[it] = 0;
    S.clear();
  }
  void tarjan(int id, int eid) {
    if(!in[id]) S.push_back(id), in[id] = 1; //  S dfn 
    // cout << "tarjan " << id << " " << eid << "\n";
    dfn[id] = low[id] = ++dn, stc[++top] = id;
    for(pii _ : e[id]) {
      if(_.second == eid) continue;
      int it = _.first;
      if(!dfn[it]) {
        tarjan(it, _.second);
        low[id] = min(low[id], low[it]);
        if(low[it] > dfn[id]) {
          // cout << "got it\n";
          cn++;
          for(int x = 0; x != it; ) col[x = stc[top--]] = cn;
        }
      }
      else low[id] = min(low[id], dfn[it]);
    }
    if(!eid) {
      ++cn;
      while(top) col[stc[top--]] = cn;
    }
  }
} g, h;
vector<int> e[N];
int lg[N], dn, dfn[N], dep[N], mi[K][N];
int get(int x, int y) {return dep[x] < dep[y] ? x : y;}
int lca(int x, int y) {
  if(x == y) return x;
  if((x = dfn[x]) > (y = dfn[y])) swap(x, y);
  int d = lg[y - x++];
  return get(mi[d][x], mi[d][y - (1 << d) + 1]);
}
void dfs(int id, int ff) {
  dfn[id] = ++dn, dep[id] = dep[ff] + 1;
  mi[0][dn] = ff;
  for(int it : e[id]) if(it != ff) dfs(it, id);
}
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  n = read(), m = read(), q = read();
  for(int i = 1; i <= m; i++) g.add(read(), read());
  for(int i = 1, c = 0; i <= n; i++)
    if(!g.dfn[i]) {
      int lst = g.cn;
      g.tarjan(i, 0), c++;
      for(int j = lst + 1; j <= g.cn; j++) comp[j] = c;
    }
  memcpy(bel, g.col, sizeof(bel));
  // for(int i = 1; i <= n; i++) cout << i << " belongs to " << bel[i] << "\n";
  for(int i = 1; i <= n; i++)
    for(pii _ : g.e[i])
      if(bel[i] != bel[_.first])
        e[bel[i]].push_back(bel[_.first]);
  for(int i = 2; i <= g.cn; i++) lg[i] = lg[i >> 1] + 1;
  for(int i = 1; i <= g.cn; i++) if(!dfn[i]) dfs(i, 0);
  for(int i = 1; i <= lg[g.cn]; i++)
    for(int j = 1; j + (1 << i) - 1 <= g.cn; j++)
      mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
  for(int _ = 1; _ <= q; _++) {
    // cout << "----------------- query " << _ << endl;
    int n = read(), m = read(), cnt = 0;
    static int V[N], u[N], v[N], p[N * 3];
    for(int i = 1; i <= n; i++) {
      V[i] = p[++cnt] = bel[rot(read())];
      // cout << "V[i] " << V[i] << "\n";
    }
    for(int i = 1; i <= m; i++) {
      u[i] = p[++cnt] = bel[rot(read())];
      v[i] = p[++cnt] = bel[rot(read())];
      // cout << "u[i], v[i] " << u[i] << " " << v[i] << "\n";
    }
    sort(p + 1, p + cnt + 1);
    cnt = unique(p + 1, p + cnt + 1) - p - 1;
    sort(p + 1, p + cnt + 1, [&](int u, int v) {return comp[u] < comp[v];});
    h.clear();
    // cout << "cnt " << cnt << endl;
    for(int i = 1; i <= cnt; i++) {
      int r = i;
      while(r < cnt && comp[p[r + 1]] == comp[p[i]]) r++;
      sort(p + i, p + r + 1, [&](int u, int v) {return dfn[u] < dfn[v];}); //  dfn 
      // cout << "component " << i << " " << r << "\n";
      static int stc[N], top;
      stc[top = 1] = p[i];
      for(int j = i + 1; j <= r; j++) {
        int d = lca(stc[top], p[j]);
        // cout << "chk " << stc[top] << " " << p[j] << " " << d << "\n";
        assert(d);
        while(top >= 2 && dep[d] <= dep[stc[top - 1]]) {
          h.add(stc[top], stc[top - 1]);
          top--;
        }
        if(d != stc[top]) h.add(d, stc[top]), stc[top] = d;
        stc[++top] = p[j];
      }
      // cout << "top " << top << endl;
      for(int j = 1; j < top; j++) h.add(stc[j], stc[j + 1]);
      i = r;
    }
    for(int i = 1; i <= m; i++) h.add(u[i], v[i]);
    for(int i = 1; i <= n; i++) if(!h.dfn[V[i]]) h.tarjan(V[i], 0); // i -> V[i]
    bool ok = 1;
    for(int i = 2; i <= n; i++) ok &= h.col[V[i]] == h.col[V[1]];
    if(ok) puts("YES"), R = (R + _) % ::n; // n -> ::n
    else puts("NO");
  }
  return cerr << "Time: " << clock() << "\n", 0;
}
/*
2022/7/7
start thinking at 13:49



 LCA


start coding at 14:08
finish debugging at 15:42
*/
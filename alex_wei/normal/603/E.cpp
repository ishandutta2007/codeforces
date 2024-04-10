#include <bits/stdc++.h>
using namespace std;
bool Mbe;
constexpr int N = 3e5 + 5;
constexpr int inf = 0x3f3f3f3f;
int n, m, odd, stc[N], top;
int fa[N], sz[N], ans[N];
struct edge {
  int u, v, w, id;
  bool operator < (const edge &rhs) {
    return w < rhs.w;
  }
} e[N], g[N];
int find(int x) {return fa[x] == x ? x : find(fa[fa[fa[fa[fa[fa[x]]]]]]);} // 
void merge(int u, int v) {
  if((u = find(u)) == (v = find(v))) return;
  if(sz[u] < sz[v]) swap(u, v);
  if((sz[u] & 1) && (sz[v] & 1)) odd -= 2;
  sz[u] += sz[v], fa[v] = u, stc[++top] = v;
  // cout << "merge " << u << " " << v << endl;
}
void undo(int lim) {
  while(top > lim) {
    int v = stc[top--], u = fa[v];
    fa[v] = v, sz[u] -= sz[v];
    // cout << "undo " << u << " " << v << "\n";
    if((sz[u] & 1) && (sz[v] & 1)) odd += 2;
  }
}
void solve(int l, int r, int vl, int vr) {
  // cout << l << " " << r << " " << vl << " " << vr << "\n";
  if(l > r || vl > vr) return;
  if(vl == vr) {
    for(int p = l; p <= r; p++) ans[p] = g[vl].w;
    return;
  }
  int mid = vl + vr >> 1, ori = top;
  for(int p = vl; p <= mid; p++) {
    if(g[p].id < l) {
      // cout << "See " << g[p].id << " " << l << " " << g[p].w << "\n";
      merge(g[p].u, g[p].v);
    }
  }
  int found = r + 1, ori2 = top;
  for(int p = l; p <= r; p++) {
    if(e[p].w <= g[mid].w) {
      // cout << "merge " << e[p].w << " " << g[mid].w << "\n";
      merge(e[p].u, e[p].v);
    }
    if(!odd) {
      found = p;
      break;
    }
  }
  // cout << "found " << found << "\n";
  undo(ori2);
  solve(l, found - 1, mid + 1, vr);
  undo(ori); // add this line
  for(int p = l; p < found; p++) {
    if(e[p].w <= g[vl].w) merge(e[p].u, e[p].v); // vl -> g[vl].w
  }
  solve(found, r, vl, mid);
  undo(ori);
}
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> m, odd = n;
  for(int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
  for(int i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
    e[i].id = i, g[i] = e[i];
  }
  sort(g + 1, g + m + 1);
  g[m + 1].w = -1;
  solve(1, m, 1, m + 1);
  for(int i = 1; i <= m; i++) cout << ans[i] << "\n";
  return cerr << "Time: " << clock() << "\n", 0;
}
/*
2022/7/9
start coding at 11:11
finish debugging at 19:18
*/
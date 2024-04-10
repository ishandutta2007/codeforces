#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
bool Mbe;
constexpr int N = 3e5 + 5;
constexpr int K = N * 26;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
int node, R[N], ls[K], rs[K];
ll val[K], laz[K];
int n, m, dep[N];
vector<int> e[N];
vector<pair<int, int>> buc[N];
void add(ll &x, ll y) {x = min(x + y, inf);}
void pushdown(int x) {
  if(laz[x]) {
    if(ls[x]) add(laz[ls[x]], laz[x]), add(val[ls[x]], laz[x]);
    if(rs[x]) add(laz[rs[x]], laz[x]), add(val[rs[x]], laz[x]);
    laz[x] = 0;
  }
}
void modify(int l, int r, int p, int &x, ll v) {
  if(!x) val[x = ++node] = inf;
  if(l == r) return val[x] = min(val[x], v), void();
  int m = l + r >> 1;
  pushdown(x);
  if(p <= m) modify(l, m, p, ls[x], v);
  else modify(m + 1, r, p, rs[x], v);
  val[x] = min(val[ls[x]], val[rs[x]]);
}
ll query(int l, int r, int ql, int qr, int x) {
  if(!x || ql <= l && r <= qr) return val[x];
  int m = l + r >> 1;
  ll ans = inf;
  pushdown(x);
  if(ql <= m) ans = query(l, m, ql, qr, ls[x]);
  if(m < qr) ans = min(ans, query(m + 1, r, ql, qr, rs[x]));
  return ans;
}
int merge(int l, int r, int x, int y, ll vx, ll vy) {
  pushdown(x), pushdown(y);
  if(!x && !y) return 0;
  if(!x) return add(val[y], vx), laz[y] = vx, y;
  if(!y) return add(val[x], vy), laz[x] = vy, x;
  if(l == r) {
    val[x] = min(inf, min(val[x] + vy, val[y] + vx));
    return x;
  }
  int m = l + r >> 1;
  ls[x] = merge(l, m, ls[x], ls[y], vx, vy);
  rs[x] = merge(m + 1, r, rs[x], rs[y], vx, vy);
  return val[x] = min(val[ls[x]], val[rs[x]]), x;
}
void dfs(int id, int ff) {
  // cerr << "dfs " << id << " " << ff << "\n";
  dep[id] = dep[ff] + 1;
  bool isleaf = 1;
  for(int it : e[id]) {
    if(it == ff) continue;
    dfs(it, id);
    if(isleaf) R[id] = R[it];
    else {
      ll vid = query(1, n, 1, dep[id], R[id]);
      ll vit = query(1, n, 1, dep[id], R[it]);
      R[id] = merge(1, n, R[id], R[it], vid, vit);
    }
    isleaf = 0;
  }
  if(isleaf) {
    // cout << "------------- isleaf " << id << " " << dep[id] << "\n";
    modify(1, n, dep[id], R[id], 0);
  }
  for(auto it : buc[id]) {
    ll v = query(1, n, 1, dep[id], R[id]);
    // cout << "------------- chk " << id << " " << dep[it.first] << " " << v << " " << it.second << "\n";
    modify(1, n, dep[it.first], R[id], min(inf, v + it.second));
  }
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> m;
  val[0] = inf;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for(int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    buc[u].push_back({v, c});
  }
  dfs(1, 0);
  ll ans = query(1, n, 1, 1, R[1]);
  if(ans == inf) ans = -1;
  cout << ans << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/8/11
Author: Alex_Wei
start coding at 20:15
finish debugging at 22:00
*/
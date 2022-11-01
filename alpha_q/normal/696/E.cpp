#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const ll INF = 1e16 + 5;

struct data {
  ll pos, node, val;

  data () {}
  data (ll pos, ll node, ll val) : pos(pos), node(node), val(val) {}

  bool operator < (const data &d) const {
    return val == d.val ? node < d.node : val < d.val;
  }
};

ll lazy[N << 2];
data flat[N], t[N << 2];
vector <int> g[N], vec[N];
int n, m, q, ptr, c[N], par[N], id[N];
int sz[N], h[N], in[N], out[N], nxt[N], en[N];

void dfs (int u = 1, int far = 0) {
  sz[u] = 1, h[u] = far;
  for (int v : g[u]) g[v].erase(find(g[v].begin(), g[v].end(), u));
  for (int &v : g[u]) {
    par[v] = u; dfs(v, far + 1); sz[u] += sz[v];
    if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
  }
}

void hld (int u = 1) {
  in[u] = ++ptr, flat[ptr] = data(INF, INF, INF), id[ptr] = -1;
  for (int x : vec[u]) ++ptr, flat[ptr] = data(ptr, u, x), id[ptr] = x;
  en[u] = ptr;
  for (int v : g[u]) {
    nxt[v] = (v == g[u][0] ? nxt[u] : v); hld(v);
  }
  out[u] = ptr;
}

void init (int u = 1, int b = 1, int e = m) {
  if (b == e) return void(t[u] = flat[b]);
  int mid = b + e >> 1;
  init(u << 1, b, mid), init(u << 1 | 1, mid + 1, e);
  t[u] = min(t[u << 1], t[u << 1 | 1]);
}

inline void push (int u, int b, int e) {
  t[u].val += lazy[u];
  if (b ^ e) lazy[u << 1] += lazy[u], lazy[u << 1 | 1] += lazy[u];
  lazy[u] = 0;
}

void pointUpdate (int p, int u = 1, int b = 1, int e = m) {
  if (lazy[u]) push(u, b, e);
  if (b > p or e < p) return;
  if (b == e) return void(t[u] = data(INF, INF, INF));
  int mid = b + e >> 1;
  pointUpdate(p, u << 1, b, mid);
  pointUpdate(p, u << 1 | 1, mid + 1, e);
  t[u] = min(t[u << 1], t[u << 1 | 1]);
}

void rangeUpdate (int l, int r, ll v, int u = 1, int b = 1, int e = m) {
  if (lazy[u]) push(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    lazy[u] += v;
    return push(u, b, e);
  }
  int mid = b + e >> 1;
  rangeUpdate(l, r, v, u << 1, b, mid);
  rangeUpdate(l, r, v, u << 1 | 1, mid + 1, e);
  t[u] = min(t[u << 1], t[u << 1 | 1]);
}

data rangeQuery (int l, int r, int u = 1, int b = 1, int e = m) {
  if (b > r or e < l) return data(INF, INF, INF);
  if (lazy[u]) push(u, b, e);
  if (b >= l and e <= r) return t[u];
  int mid = b + e >> 1;
  return min(rangeQuery(l, r, u << 1, b, mid), rangeQuery(l, r, u << 1 | 1, mid + 1, e));
}

data query (int u, int v) {
  auto res = data(INF, INF, INF);
  while (nxt[u] != nxt[v]) {
    if (h[nxt[u]] > h[nxt[v]]) swap(u, v);
    res = min(res, rangeQuery(in[nxt[v]], en[v]));
    v = par[nxt[v]];
  }
  if (h[u] > h[v]) swap(u, v);
  res = min(res, rangeQuery(in[u], en[v]));
  return res;
}

int main() {
  cin >> n >> m >> q;
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].push_back(v), g[v].push_back(u);
  }
  for (int i = 1, x; i <= m; ++i) {
    scanf("%d", &x);
    vec[x].emplace_back(i);
  }
  dfs(); hld(); m = ptr; init();
  while (q--) {
    int cmd, u, v; ll k;
    scanf("%d", &cmd);
    if (cmd == 1) {
      scanf("%d %d %lld", &u, &v, &k);
      vector <int> ans;
      while (k--) {
        auto cur = query(u, v);
        if (cur.val > INF / 2) break;
        ans.emplace_back(id[cur.pos]);
        pointUpdate(cur.pos);
      }
      printf("%d", (int) ans.size());
      for (int x : ans) printf(" %d", x); puts("");
    } else {
      scanf("%d %lld", &u, &k);
      rangeUpdate(in[u], out[u], k);
    }
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const int INF = 1e8 + 69;

struct node {
  int min_time, max_time, active_min, active_max;

  node operator + (const node &oth) const {
    node ret;
    ret.min_time = min(min_time, oth.min_time);
    ret.max_time = max(max_time, oth.max_time);
    ret.active_min = min(active_min, oth.active_min);
    ret.active_max = max(active_max, oth.active_max);
    return ret; 
  }
};

node t[N << 2];
int n, q, val[N << 1], ptr, to[N << 1][2];
int p[N << 1], par[N << 1], h[N << 1], jump[N << 1];
int in[N << 1], out[N << 1], flat[N << 1], lazy[N << 2];

int find (int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

void go (int u) {
  in[u] = ++ptr, flat[ptr] = u;
  if (to[u][0]) {
    int v = to[u][0];
    par[v] = u, h[v] = h[u] + 1;
    int x = jump[u], y = jump[x];
    jump[v] = (h[u] + h[y] == h[x] << 1) ? y : u;
    go(v); 
  }
  if (to[u][1]) {
    int v = to[u][1];
    par[v] = u, h[v] = h[u] + 1;
    int x = jump[u], y = jump[x];
    jump[v] = (h[u] + h[y] == h[x] << 1) ? y : u;
    go(v); 
  }
  out[u] = ptr;
}

void init (int u = 1, int b = 1, int e = n) {
  if (b == e) return void(t[u] = {in[b], in[b], INF, -INF});
  int mid = b + e >> 1;
  init(u << 1, b, mid), init(u << 1 | 1, mid + 1, e);
  t[u] = t[u << 1] + t[u << 1 | 1];
}

inline void push (int u, int b, int e) {
  if (lazy[u] == 1) {
    t[u].active_min = t[u].min_time;
    t[u].active_max = t[u].max_time;
  } else {
    t[u].active_min = +INF;
    t[u].active_max = -INF;
  }
  if (b ^ e) lazy[u << 1] = lazy[u << 1 | 1] = lazy[u];
  lazy[u] = 0;
}

void update (int l, int r, int v, int u = 1, int b = 1, int e = n) {
  if (lazy[u]) push(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    lazy[u] = v;
    return push(u, b, e);
  }
  int mid = b + e >> 1;
  update(l, r, v, u << 1, b, mid), update(l, r, v, u << 1 | 1, mid + 1, e);
  t[u] = t[u << 1] + t[u << 1 | 1];
}

int LCA (int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  while (h[u] > h[v]) u = h[jump[u]] < h[v] ? par[u] : jump[u];
  while (u ^ v) (jump[u] ^ jump[v]) ? (u = jump[u], v = jump[v]) : (u = par[u], v = par[v]);
  return u;
}

int main() {
  cin >> n >> q;
  vector <tuple <int, int, int>> edges(n - 1);
  for (int i = 1, u, v, w; i < n; ++i) {
    scanf("%d %d %d", &u, &v, &w);
    edges[i - 1] = make_tuple(w, u, v);
  }
  for (int i = 1; i <= n; ++i) p[i] = par[i] = i;
  sort(edges.begin(), edges.end()), ptr = n;
  for (auto &[w, u, v] : edges) {
    val[++ptr] = w;
    to[ptr][0] = find(u), to[ptr][1] = find(v);
    p[ptr] = p[find(u)] = p[find(v)] = ptr;
    par[find(u)] = par[find(v)] = ptr;
  }
  int root = n + n - 1;
  ptr = 0, par[root] = -1, jump[root] = root; 
  go(root); init();
  while (q--) {
    int cmd, l, r, x;
    scanf("%d", &cmd);
    if (cmd == 1) {
      scanf("%d %d", &l, &r);
      update(l, r, +1);
    } else if (cmd == 2) {
      scanf("%d %d", &l, &r);
      update(l, r, -1);
    } else {
      scanf("%d", &x);
      auto [idk, lol, min_t, max_t] = t[1];
      if (min_t > INF / 2) {
        puts("-1");
        continue;
      }
      int sub = LCA(x, LCA(flat[min_t], flat[max_t]));
      if (sub == x) {
        puts("-1");
        continue;
      }
      printf("%d\n", val[sub]);
    }
  }
  return 0;
}
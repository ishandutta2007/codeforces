#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

struct edge {
  int u, v, w;
  edge (int a = 0, int b = 0, int c = 0) : u(a), v(b), w(c) {}
};

pair<int, int> minmax(int x, int y) {
  if (x > y) swap(x, y);
  return make_pair(x, y);
}

map<pair<int, int>, int> id;
vector<edge> e[maxN * 4];
int b[maxN], opt[maxN], u[maxN], v[maxN], w[maxN], t[maxN];
long long ans[maxN];
int n, m, q, len;

void insert(int u, int L, int R, int l, int r, edge x) {
  if (l <= L && R <= r) {
    e[u].push_back(x);
    return;
  }
  int mid = (L + R) >> 1;
  if (mid >= l) insert(u << 1, L, mid, l, r, x);
  if (mid + 1 <= r) insert(u << 1 | 1, mid + 1, R, l, r, x);
}

const int maxM = 1.5e7;
int lc[maxM], rc[maxM], sum[maxM], rt[maxN], tot;

inline int newNode() {
  ++tot;
  lc[tot] = rc[tot] = sum[tot] = 0;
  return tot;
}

void ins(int &u, int l, int r, int x) {
  if (!u) u = newNode();
  ++sum[u];
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (mid >= x) ins(lc[u], l, mid, x);
  else ins(rc[u], mid + 1, r, x);
}

void del(int &u, int l, int r, int x) {
  --sum[u];
  if (l == r) {
    if (!sum[u]) u = 0, --tot;
    return;
  }
  int mid = (l + r) >> 1;
  if (mid >= x) del(lc[u], l, mid, x);
  else del(rc[u], mid + 1, r, x);
  if (!sum[u]) u = 0, --tot;
}

int getans(int u, int k1, int k2, int l, int r) {
  if (l == r) {
    if (sum[u] != sum[k1] + sum[k2]) return l;
    return 0;
  }
  int mid = (l + r) >> 1;
  if (sum[lc[u]] != sum[lc[k1]] + sum[lc[k2]]) return getans(lc[u], lc[k1], lc[k2], l, mid);
  return getans(rc[u], rc[k1], rc[k2], mid + 1, r);
}

multiset<int> val[maxN];
void solve(int u, int l, int r, long long res) {
  for (auto i : e[u]) {
    int id = getans(rt[0], rt[i.u], rt[i.v], 1, len);
    if (id) res = min(res, (long long)b[i.w] + b[id]);
    ins(rt[i.u], 1, len, i.w);
    ins(rt[i.v], 1, len, i.w);
    ins(rt[0], 1, len, i.w);
    val[i.u].insert(i.w);
    val[i.v].insert(i.w);
    if (val[i.u].size() >= 3) {
      long long sum = 0;
      auto it = val[i.u].begin();
      sum += b[*it];
      ++it; sum += b[*it];
      ++it; sum += b[*it];
      res = min(res, sum);
    }
    if (val[i.v].size() >= 3) {
      long long sum = 0;
      auto it = val[i.v].begin();
      sum += b[*it];
      ++it; sum += b[*it];
      ++it; sum += b[*it];
      res = min(res, sum);
    }
  }
  if (l == r) {
    ans[l] = res;
  } else {
    int mid = (l + r) >> 1;
    solve(u << 1, l, mid, res);
    solve(u << 1 | 1, mid + 1, r, res);
  }
  for (auto i : e[u]) {
    del(rt[i.u], 1, len, i.w);
    del(rt[i.v], 1, len, i.w);
    del(rt[0], 1, len, i.w);
    val[i.u].erase(val[i.u].find(i.w));
    val[i.v].erase(val[i.v].find(i.w));
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
    b[++len] = w[i]; t[i] = -1;
    id[minmax(u[i], v[i])] = i;
  }
  scanf("%d", &q);
  for (int i = m + 1; i <= m + q; i++) {
    scanf("%d", &opt[i]);
    if (opt[i] == 0) {
      int u, v;
      scanf("%d%d", &u, &v);
      t[id[minmax(u, v)]] = i - 1 - m;
    }
    if (opt[i] == 1) {
      scanf("%d%d%d", &u[i], &v[i], &w[i]);
      b[++len] = w[i]; t[i] = -1;
      id[minmax(u[i], v[i])] = i;
    }
  }
  sort(b + 1, b + len + 1);
  len = unique(b + 1, b + len + 1) - b - 1;
  for (int i = 1; i <= m + q; i++) {
    if (i <= m || opt[i] == 1) {
      if (t[i] == -1) t[i] = q;
      int s = (i <= m ? 0 : i - m);
      w[i] = lower_bound(b + 1, b + len + 1, w[i]) - b;
      insert(1, 0, q, s, t[i], edge(u[i], v[i], w[i]));
    }
  }
  solve(1, 0, q, 1e18);
  for (int i = 0; i <= q; i++) printf("%lld\n", ans[i]);
  return 0;
}
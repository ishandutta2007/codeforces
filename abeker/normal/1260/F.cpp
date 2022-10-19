#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;
const int MOD = 1e9 + 7;

struct Node {
  int sum, lazy;
  Node() : sum(0), lazy(0) {}
};

int N;
int inv[MAXN];
Node tour[2 * offset];
vector <int> adj[MAXN];
vector <pii> queries[MAXN];
int dad[MAXN], dep[MAXN], sub[MAXN];
int pos[MAXN], head[MAXN];
int ptr, prod = 1;

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

inline void inc(int &x, int y) {
  x = add(x, y);
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

void init() {
  inv[1] = 1;
  for (int i = 2; i < MAXN; i++)
    inv[i] = MOD - mul(MOD / i, inv[MOD % i]);
}

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    int prob = inv[r - l + 1];
    queries[l].push_back({i, prob});
    queries[r + 1].push_back({i, -prob});
    prod = mul(prod, r - l + 1);
  }
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void dfs_init(int x, int p) {
  sub[x] = 1;
  dad[x] = p;
  dep[x] = dep[p] + 1;
  for (auto it : adj[x])
    if (it != p) {
      dfs_init(it, x);
      sub[x] += sub[it];
    }
}

void dfs_hld(int x, int p, int h) {
  head[x] = h;
  pos[x] = ptr++;
  int heavy = 0;
  for (auto it : adj[x])
    if (it != p && sub[it] > sub[heavy])
      heavy = it;
  if (!heavy)
    return;
  dfs_hld(heavy, x, h);
  for (auto it : adj[x])
    if (it != p && it != heavy)
      dfs_hld(it, x, it);
}

void prop(int x, int len) {
  inc(tour[x].sum, mul(len, tour[x].lazy));
  if (len > 1) {
    inc(tour[2 * x].lazy, tour[x].lazy);
    inc(tour[2 * x + 1].lazy, tour[x].lazy);
  }
  tour[x].lazy = 0;
}

int query(int x, int lo, int hi, int from, int to, int val) {
  prop(x, hi - lo);
  if (lo >= to || hi <= from)
    return 0;
  if (lo >= from && hi <= to) {
    int res = tour[x].sum;
    inc(tour[x].lazy, val);
    prop(x, hi - lo);
    return res;
  }
  int mid = (lo + hi) / 2;
  int lft = query(2 * x, lo, mid, from, to, val);
  int rig = query(2 * x + 1, mid, hi, from, to, val);
  tour[x].sum = add(tour[2 * x].sum, tour[2 * x + 1].sum);
  return add(lft, rig);
}

int get(pii p) {
  int res = 0;
  for (int x = p.first; x; x = dad[head[x]]) 
    inc(res, query(1, 0, offset, pos[head[x]], pos[x] + 1, p.second));
  return res;
}

int solve() {
  dfs_init(1, 0);
  dfs_hld(1, 0, 1);
  int all = 0, sum = 0, sq = 0, sol = 0;
  for (int i = 1; i < MAXN; i++) {
    for (auto it : queries[i]) {
      inc(all, it.second);
      inc(sum, mul(dep[it.first], it.second));
      inc(sq, add(mul(2, mul(get(it), it.second)), mul(dep[it.first], mul(it.second, it.second))));
    }
    inc(sol, add(mul(all, sum), -sq));
  }
  return mul(sol, prod);
}

int main() {
  init();
  load();
  printf("%d\n", solve());
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int ROOT = 7;
const int M = 200200;
const int N = 4 * M;
const int A = 19;

struct Node {
  int mx;
  int cnt;
  Node():
    mx(0),
    cnt(0)
  {}

  Node(int mx, int cnt):
    mx(mx),
    cnt(cnt)
  {}
};

Node merge(const Node &A, const Node &B) {
  int sz;
  if (A.mx > B.mx) {
    sz = A.cnt;
  } else if (B.mx > A.mx) {
    sz = B.cnt;
  } else {
    sz = A.cnt + B.cnt;
  }

  return Node(max(A.mx, B.mx), sz);
}

Node t[N];
int mem[N];

void build(int v, int l, int r) {
  mem[v] = 0;

  if (l + 1 == r) {
    t[v] = Node(0, 1);
    return;
  } 

  int m = (l + r) / 2;
  build(2 * v, l, m);
  build(2 * v + 1, m, r);
  t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void push(int v, int l, int r) {
  if (mem[v] == 0) return;

  t[v].mx += mem[v];
  if (r - l > 1) {
    mem[2 * v] += mem[v];
    mem[2 * v + 1] += mem[v];
  }
  mem[v] = 0;
}

void put(int v, int l, int r, int le, int re, int by) {
  //if (v == 1) {
    //cerr << le << " - " << re << ", " << by << "\n";
  //}
  push(v, l, r);
  if (l == le && r == re) {
    mem[v] += by;
    push(v, l, r);
    return;
  }

  int m = (l + r) / 2;
  if (le < m)
    put(2 * v, l, m, le, min(re, m), by);
  if (m < re)
    put(2 * v + 1, m, r, max(m, le), re, by);

  push(2 * v, l, m);
  push(2 * v + 1, m, r);

  t[v] = merge(t[2 * v], t[2 * v + 1]);
}

int n, q;
vector<int> g[M];
int tin[M], tout[M];
int d[M];
int tim = 0;
int p[M][A];
set<pair<int, int>> e;

void read() {
  cin >> n;
  cin >> q;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}

void dfs(int v, int from, int depth) {
  p[v][0] = from;
  for (int i = 0; i + 1 < A; ++i)
    p[v][i + 1] = p[p[v][i]][i];

  d[v] = depth;
  tin[v] = tim++;
  for (int to : g[v])
    if (to != from)
      dfs(to, v, depth + 1);
  tout[v] = tim;
}

int goup(int v, int by) {
  for (int i = 0; i < A; ++i)
    if ((by >> i) & 1)
      v = p[v][i];
  return v;
}

bool isAnc(int u, int v) {
  return tin[u] <= tin[v] && tout[v] <= tout[u];
}

void kill() {
  int root = ROOT % n;
  cerr << "hooray\n";
  dfs(root, root, 0);
  build(1, 0, n);

  int need = 0;

  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u > v)
      swap(u, v);

    int by;
    pair<int, int> cur = make_pair(u, v);
    if (e.find(cur) == e.end()) {
      e.insert(cur);
      by = +1;
    } else {
      e.erase(cur);
      by = -1;
    }

    if (tin[u] > tin[v])
      swap(u, v);


    if (isAnc(u, v)) {
      put(1, 0, n, tin[v], tout[v], +by);
      int x = goup(v, d[v] - d[u] - 1);
      put(1, 0, n, tin[x], tout[x], -by);
      put(1, 0, n, tin[root], tout[root], +by);
    } else {
      put(1, 0, n, tin[v], tout[v], +by);
      put(1, 0, n, tin[u], tout[u], +by);
    }

    need += by;

    int ans = t[1].mx == need ? t[1].cnt : 0;

    cout << ans << "\n";
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}
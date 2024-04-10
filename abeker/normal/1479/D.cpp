#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
  ll sum;
  Node *l, *r;
  Node() : sum(0), l(0), r(0) {}
  Node(ll sum, Node* l, Node* r) : sum(sum), l(l), r(r) {}
};

class Persistent {
  Node* NIL;
  vector <Node*> roots;
  vector <int> idx;
  int offset;
public:
  Persistent(int n) {
    NIL = new Node();
    NIL -> l = NIL -> r = NIL;
    roots.push_back(NIL);
    idx.resize(n + 1);
    for (offset = 1; offset <= n; offset *= 2);
  }
  Persistent(){}
  Node* insert(Node* x, int lo, int hi, int pos, ll val) {
    if (pos < lo || pos >= hi)
      return x;
    if (hi - lo == 1)
      return new Node(x -> sum ^ val, NIL, NIL);
    int mid = (lo + hi) / 2;
    Node* left = insert(x -> l, lo, mid, pos, val);
    Node* right = insert(x -> r, mid, hi, pos, val);
    return new Node(left -> sum ^ right -> sum, left, right);
  }
  void update(int who, int prev, int pos, ll val) {
    idx[who] = roots.size();
    roots.push_back(insert(roots[idx[prev]], 0, offset, pos, val));
  }
  int search(Node* x1, Node* x2, int lo, int hi, int from, int to) {
    if (lo >= to || hi <= from)
      return to;
    int mid = (lo + hi) / 2;
    if (lo >= from && hi <= to) {
      if (x1 -> sum == x2 -> sum)
        return to;
      if (hi - lo == 1)
        return lo;
      if (x1 -> l -> sum == x2 -> l -> sum)
        return search(x1 -> r, x2 -> r, mid, hi, from, to);
    }
    int left = search(x1 -> l, x2 -> l, lo, mid, from, to);
    if (left != to)
      return left;
    return search(x1 -> r, x2 -> r, mid, hi, from, to);
  }
  int get(int who1, int who2, int from, int to) {
    return search(roots[idx[who1]], roots[idx[who2]], 0, offset, from, to);
  }
};

int N, Q;
vector <int> a;
vector <int> depth;
vector <vector <int>> adj;
vector <vector <int>> anc;
vector <ll> numbers;
Persistent hashes;
int lg;

void load() {
  scanf("%d%d", &N, &Q);
  a.resize(N + 1);
  for (int i = 1; i <= N; i++)
    scanf("%d", &a[i]);
  adj.resize(N + 1);
  for (int i = 1; i < N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}

void dfs(int x, int p) {
  anc[x][0] = p;
  depth[x] = depth[p] + 1;
  hashes.update(x, p, a[x], numbers[a[x]]);
  for (auto it : adj[x])
    if (it != p)
      dfs(it, x);
}

int lca(int u, int v) {
  if (depth[u] < depth[v])
    swap(u, v);
  int diff = depth[u] - depth[v];
  for (int i = 0; i < lg; i++)
    if (diff >> i & 1)
      u = anc[u][i];
  if (u == v)
    return u;
  for (int i = lg - 1; i >= 0; i--)
    if (anc[u][i] != anc[v][i]) {
      u = anc[u][i];
      v = anc[v][i];
    }
  return anc[u][0];
}

int query(int u, int v, int l, int r) {
  int w = lca(u, v);
  int tmp = hashes.get(u, v, l, r + 1);
  if (tmp > r)
    return a[w] >= l && a[w] <= r ? a[w] : -1;
  if (tmp != a[w])
    return tmp;
  tmp = hashes.get(u, v, tmp + 1, r + 1);
  return tmp > r ? -1 : tmp;
}

void solve() {
  anc.resize(N + 1);
  depth.resize(N + 1);
  numbers.resize(N + 1);
  lg = 32 - __builtin_clz(N);
  hashes = Persistent(N);
  for (int i = 0; i <= N; i++) {
    numbers[i] = uniform_int_distribution <ll> (1, 1ll << 60)(rng);
    anc[i].resize(lg);
  }
  dfs(1, 0);
  for (int j = 1; j < lg; j++)
    for (int i = 1; i <= N; i++) 
      anc[i][j] = anc[anc[i][j - 1]][j - 1];
  while (Q--) {
    int u, v, l, r;
    scanf("%d%d%d%d", &u, &v, &l, &r);
    printf("%d\n", query(u, v, l, r));
  }
}

int main() {
  load();
  solve();
  return 0;
}
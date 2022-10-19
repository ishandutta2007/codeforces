#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 1007;
const int N = M * M;

int n, m, q;
int u[N], v[N], w[N];
vector<int> g[M];
bool used[M];
int c[M];

int p[M], sz[M];

int get(int x) {
  return p[x] = p[x] == x ? x : get(p[x]);
}

void uni(int x, int y) {
  x = get(x);
  y = get(y);
  if (sz[x] < sz[y])
    swap(x, y);
  sz[x] += sz[y];
  p[y] = x;
}

bool cmp(int x, int y) {
  return w[x] > w[y];
}

void read() {
  cin >> n >> m >> q;
  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i] >> w[i];
    --u[i], --v[i];
  }
}

struct Bip {
  vector<int> e;
  int ans;

  Bip(): ans(-1) { }
};

void dfs(int v, int u, int col) {
  c[v] = col;

  for (int to : g[v])
    if (to != u)
      dfs(to, v, col ^ 1);
}

void ini(int v) {
  p[v] = v;
  sz[v] = 1;
  g[v].clear();
}

Bip merge(const Bip &a, const Bip &b) {
  Bip res;
  res.ans = max(a.ans, b.ans);
  res.e.resize(a.e.size() + b.e.size());
  merge(a.e.begin(), a.e.end(),
        b.e.begin(), b.e.end(),
        res.e.begin(),
        cmp);

  for (int x : res.e) {
    ini(u[x]);
    ini(v[x]);
  }

  int la = 0;

  vector<int> ans;
  
  for (int x : res.e) {
    int l = u[x], r = v[x];
    if (get(l) == get(r)) {
      if (c[l] == c[r])
        break;
      else {
        ++la;
        continue;
      }
    }

    if (sz[get(l)] < sz[get(r)])
      swap(l, r);

    if (c[l] == c[r])
      dfs(r, -1, c[l] ^ 1);

    g[l].push_back(r);
    g[r].push_back(l);

    ans.push_back(x);
    ++la;
    uni(l, r);
  }

  if (la < (int) res.e.size()) {
    res.ans = max(res.ans, w[res.e[la]]);
  }

  res.e = ans;

  assert((int) res.e.size() < n);
  
  return res;
}

Bip tree[4 * N];

void build(int v, int l, int r) {
  if (l + 1 == r) {
    tree[v].e = {l};
    return;
  }

  int m = (l + r) / 2;
  build(2 * v, l, m);
  build(2 * v + 1, m, r);

  tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
}


Bip get(int v, int l, int r, int le, int re) {
  //cerr << v << " " << l << " " << r << " " << le << " " << re << endl;
  if (l == le && r == re) 
    return tree[v];

  int m = (l + r) / 2;
  Bip ans;
  if (le < m)
    ans = merge(ans, get(2 * v, l, m, le, min(m, re)));
  if (m < re)
    ans = merge(ans, get(2 * v + 1, m, r, max(le, m), re));

  return ans;
}

void kill() {
  build(1, 0, m);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    cout << get(1, 0, m, l, r).ans << "\n";
  }
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}
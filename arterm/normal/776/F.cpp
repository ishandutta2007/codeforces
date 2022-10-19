#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

const int M = 100100;

int n, m, k = 0;
vector<int> g[M], t[M];
vector<pair<int, int>> es;
map<pair<int, int>, int> face;
vector<int> b[M];
int sz[M];
int ans[M], ord[M];
bool u[M], done[M];

void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    tie(a, b) = tuple<int, int>{min(a, b), max(a, b)};
    es.emplace_back(a, b);
  }
}

void add(int u, int v) {
  g[u].push_back(v);
  //g[v].push_back(u);
}

void build() {
  for (int i = 0; i < n; ++i)
    add(i, (i + 1) % n);
  for (auto e : es) {
    add(e.first, e.second);
    add(e.second, e.first);
  }
  for (int v = 0; v < n; ++v)
    sort(g[v].begin(), g[v].end());
}

int nx(int v, int from) {
  int id = lower_bound(g[v].begin(), g[v].end(), from) - g[v].begin();
  int to = (id - 1 + g[v].size()) % g[v].size();
  return g[v][to];
}

pii rev(const pii &x) {
  return make_pair(x.second, x.first);
}

void run(int u, int v) {
  vector<int> a = {u};
  int first = u;
  while (v != first) {
    a.push_back(v);
    tie(u, v) = make_pair(v, nx(v, u));
  }
  
  //cerr << "face " << k << " : ";
  //for (int x : a)
    //cerr << x + 1 << " ";
  //cerr << endl;

  int n = a.size();
  for (int i = 0; i < n; ++i) {
    face[make_pair(a[i], a[(i + 1) % n])] = k;
  }
  b[k] = a;
  sort(b[k].begin(), b[k].end(), greater<int>());
  ++k;
}

void add_tree(int u, int v) {
  //cerr << u << " - " << v << endl;
  t[u].push_back(v);
  t[v].push_back(u);
}

void build_tree() {
  for (auto e : es) {
    add_tree(face[e], face[rev(e)]);
  }
}

int dfs_sz(int v) {
  if (done[v])
    return 0;

  u[v] = true;
  sz[v] = 1;

  for (int to : t[v])
    if (!u[to]) {
      sz[v] += dfs_sz(to);
    }

  return sz[v];
}

int dfs_find(int v, int from, int by) {
  //cerr << v << " " << from << "!\n";
  assert(!done[v]);
  assert(sz[v] >= by);
  for (int to : t[v])
    if (to != from && sz[to] >= by)
      return dfs_find(to, v, by);
  return v;
}

void kill() {
  if (m == 0) {
    cout << "13\n";
    exit(0);
  }

  build();

  for (auto e : es) {
    for (auto p : {e, rev(e)})
      if (!face.count(p)) {
        run(p.first, p.second);
      }
  }

  build_tree();


  for (int i = 0; i < 20; ++i) {
    //cerr << "her " << i << endl;
    fill(u, u + k, 0);
    fill(sz, sz + k, 0);
    for (int v = 0; v < k; ++v)
      if (!u[v] && !done[v]) {
        dfs_sz(v);
        //cerr << "sz done " << sz[v] << endl;
        int x = dfs_find(v, -1, (sz[v] + 1) / 2);
        done[x] = true;
        ans[x] = i;
      }
  }

  iota(ord, ord + k, 0);
  sort(ord, ord + k, [&](int x, int y) -> bool {
      return b[x] < b[y];
      });
  for (int i = 0; i < k; ++i)
    cout << ans[ord[i]] + 1 << " ";
  cout << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}
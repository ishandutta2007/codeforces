#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 300005;

int n, m, x;
int a[N];
vector<pair<int, int>> g[N];
pair<int, int> edges[N];
vector<int> res;
int p[N];
int cnt[N], sum[N];

int root(int x) { return (p[x] == x ? x : p[x] = root(p[x])); }

void dfs(int u, int p) {
  for (auto &e : g[u]) {
    if (e.first == p) {
      swap(e, g[u].back());
      g[u].pop_back();
      break;
    }
  }
  cnt[u] = 1;
  sum[u] = a[u];
  for (auto e : g[u]) {
    if (e.first == p) continue;
    dfs(e.first, u);
    cnt[u] += cnt[e.first];
    sum[u] += sum[e.first];
  }
}

void solve(int u) {
  sort(g[u].begin(), g[u].end(), [&](const auto &lhs, const auto &rhs) {
    return sum[lhs.first] - (cnt[lhs.first] - 1) * x >
           sum[rhs.first] - (cnt[rhs.first] - 1) * x;
  });
  for (auto &e : g[u]) {
    int v = e.first;
    int rem = sum[v] - (cnt[v] - 1) * x;
    if (rem > 0) {
      solve(v);
      a[u] += rem - x;
      res.push_back(e.second);
    } else {
      a[u] -= (x - rem);
      a[v] -= rem;
      res.push_back(e.second);
      solve(v);
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> x;
  int summ = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], p[i] = i, summ += a[i];
  if (summ < (n - 1) * x) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 1; i <= m; i++) {
    cin >> edges[i].first >> edges[i].second;
  }

  for (int i = 1; i <= m; i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    if (root(u) != root(v)) {
      p[root(u)] = root(v);
      g[u].push_back({v, i});
      g[v].push_back({u, i});
    }
  }
  dfs(1, 0);
  solve(1);
  for (int e : res) cout << e << '\n';
  return 0;
}
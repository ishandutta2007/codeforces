#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 3030;
const int N = M * M;

vector<int> g[M];
int n;
ll dd[M][M];
ll p[M][M];
ll sz[M][M];
bool used[M][M];
pair<int, int> q[N];
int qs = 0, qf = 0;

ll uax(ll &x, ll y) {
  return x = max(x, y);
}

ll& d(int u, int v) {
  if (u > v) swap(u, v);
  return dd[u][v];
}

void read() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}

void push(int u, int v) {
  if (u > v) swap(u, v);
  if (used[u][v]) return;

  used[u][v] = true;
  q[qf++] = make_pair(u, v);
}

ll calc(int u, int v) {
  return sz[p[u][v]][u] * sz[p[v][u]][v];
}

int dfs(int u, int from) {
  int sum = 1;

  for (int to : g[u])
    if (to != from) {
      sz[u][to] = dfs(to, u);
      sum += sz[u][to];
    }

  return sum;
}

void pre() {
  for (int u = 0; u < n; ++u) {
    dfs(u, -1);
  }
}

void kill() {
  for (int u = 0; u < n; ++u)
    for (int v : g[u]) {

      p[u][v] = v;
      p[v][u] = u;

      d(u, v) = calc(u, v);

      push(u, v);
    }

  while (qs < qf) {
    int u = q[qs].first;
    int v = q[qs].second;
    ++qs;

    for (int iter = 0; iter < 2; ++iter) {

      for (int z : g[u])
        if (z != p[u][v]) {
          p[z][v] = u;
          p[v][z] = p[v][u];

          uax(d(z, v), d(u, v) + calc(z, v));
          push(z, v);
        }

      swap(u, v);
    }
  }

  ll ans = 0;
  for (int u = 0; u < n; ++u)
    for (int v = u + 1; v < n; ++v)
      uax(ans, d(u, v));

  cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  pre();
  kill();
}
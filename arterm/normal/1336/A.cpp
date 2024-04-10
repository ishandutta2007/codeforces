#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


const int M = 200200;

int sz[M];
int d[M];
int n;
int k;
pair<ll, int> s[M];
vector<int> g[M];
int p[M];
bool u[M];

void read() {
  cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}

void dfs(int v, int from, int depth) {
  d[v] = depth;
  sz[v] = 1;
  p[v] = from;

  for (int to : g[v])
    if (to != from) {
      dfs(to, v, depth + 1);
      sz[v] += sz[to];
    }
}

void kill() {
  dfs(0, -1, 0);

  for (int i = 0; i < n; ++i)
    s[i] = make_pair(d[i] - sz[i], i);

  sort(s, s + n);
  reverse(s, s + n);

  for (int i = 0; i < k; ++i) {
    u[s[i].second] = true;
  }

  ll ans = 0;
  for (int i = 0; i < n; ++i)
    if (u[i] && !u[p[i]])
      ans += ll(sz[i]) * ll(d[i]);
  cout << ans << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}
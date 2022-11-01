#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;
const int MOD = 1e9 + 7;

vector <int> g[N];
int n; ll x[N], ans;

vector <pair <ll, ll>> normalized (vector <pair <ll, ll>> vec) {
  vector <pair <ll, ll>> ret;
  for (int i = 0; i < vec.size();) {
    int j = i; ll tot = 0;
    while (j < vec.size() and vec[j].second == vec[i].second) {
      tot += vec[j++].first;
    }
    ret.emplace_back(tot, vec[i].second); i = j;
  }
  return ret;
}

void dfs (int u = 1, int par = -1, vector <pair <ll, ll>> vec = {}) {
  for (auto &it: vec) it.second = __gcd(it.second, x[u]);
  vec.emplace_back(1, x[u]); vec = normalized(vec);
  for (auto it : vec) {
    ans += (it.second % MOD) * it.first % MOD;
    if (ans >= MOD) ans -= MOD;
  }
  for (int v : g[u]) if (v ^ par) dfs(v, u, vec);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%lld", x + i);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  dfs(); cout << ans << '\n';
  return 0;
}
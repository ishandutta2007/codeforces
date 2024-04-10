#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 100005;
const int MOD = 1e9 + 7;

ll gcd (ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

vector<int> adj [MAX_N];
ll beauty [MAX_N];
vector<pair<ll, ll>> gcs [MAX_N];
ll ans = 0;

void dfs (int vertex, int parent) {
  for (pair<ll, ll> u : gcs[parent]) {
    ll ng = gcd(u.first, beauty[vertex]);
    if (gcs[vertex].empty() || gcs[vertex].back().first != ng) {
      gcs[vertex].push_back(make_pair(ng, 0LL));
    }
    gcs[vertex].back().second += u.second;
  }

  ll ng = beauty[vertex];
  if (gcs[vertex].empty() || gcs[vertex].back().first != ng) {
    gcs[vertex].push_back(make_pair(ng, 0LL));
  }
  gcs[vertex].back().second++;

  for (pair<ll, ll> u : gcs[vertex]) {
    ans += ((u.first % MOD) * (u.second % MOD)) % MOD;
    ans %= MOD;
  }

  for (int nxt : adj[vertex]) {
    if (nxt != parent) {
      dfs(nxt, vertex);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  int vertexc;
  cin >> vertexc;

  for (int i = 1; i <= vertexc; i++) {
    cin >> beauty[i];
  }

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);

  cout << ans << endl;
}
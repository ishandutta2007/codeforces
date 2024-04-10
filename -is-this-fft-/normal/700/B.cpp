#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

typedef long long ll;

ll ans;

int K;
vector<int> adj [MAX_N];
int sz [MAX_N];

void dfs (int u, int p) {
  for (int nxt : adj[u]) {
    if (nxt != p) {
      dfs(nxt, u);
      sz[u] += sz[nxt];
    }
  }

  ans += min(sz[u], K - sz[u]);
} 

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n >> K;

  K *= 2;

  for (int i = 0; i < K; i++) {
    int u;
    cin >> u;

    sz[u]++;
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);

  cout << ans << endl;
}
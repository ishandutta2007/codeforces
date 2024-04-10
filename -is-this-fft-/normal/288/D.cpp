#include <iostream>
#include <vector>

using namespace std;

typedef __int128 lll;
typedef long long ll;

const int MAX_N = 8e4 + 5;

ll badqc;

vector<int> adj [MAX_N];
ll sz [MAX_N];
ll sub3 [MAX_N];

void dfs (int u, int p) {
  vector<ll> cnts (5, 0);
  cnts[0] = 1;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      dfs(nxt, u);
      sz[u] += sz[nxt];
      sub3[u] += sub3[nxt];

      badqc -= sz[nxt] * sub3[nxt];
      for (int i = 4; i >= 1; i--) {
        cnts[i] += cnts[i - 1] * sz[nxt];
      }
    }
  }

  badqc += sz[u] * sub3[u];
  badqc += sub3[u];
  sub3[u] += cnts[3] + cnts[2];
  badqc += cnts[4] + cnts[3];
  sz[u]++;
}

int main () {
  int n;
  cin >> n;

  lll nll = n;
  ll base = nll * (nll - 1) * (nll - 2) * (nll - 3) / (lll) 12;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);

  cout << base - 2 * badqc << endl;
}
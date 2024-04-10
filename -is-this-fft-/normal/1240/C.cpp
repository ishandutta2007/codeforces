#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 5e5 + 5;

vector<pair<int, ll>> adj [MAX_N];
ll dpw [MAX_N];
ll dpwo [MAX_N];

void dfs (int vertex, int parent, ll parw, int deglim) {
  for (pair<int, ll> nxt : adj[vertex]) {
    if (nxt.first != parent) {
      dfs(nxt.first, vertex, nxt.second, deglim);
    }
  }

  dpwo[vertex] = 0;
  dpw[vertex] = parw;
  vector<ll> bests;
  for (pair<int, ll> nxt : adj[vertex]) {
    if (nxt.first != parent) {
      dpwo[vertex] += dpwo[nxt.first];
      dpw[vertex] += dpwo[nxt.first];
      bests.push_back(max(dpw[nxt.first], dpwo[nxt.first]) - dpwo[nxt.first]);
    }
  }

  sort(bests.begin(), bests.end(), greater<ll> ());
  for (int i = 0; i < min((int) bests.size(), deglim); i++) {
    dpwo[vertex] += bests[i];
  }

  for (int i = 0; i < min((int) bests.size(), deglim - 1); i++) {
    dpw[vertex] += bests[i];
  }
}

void solve () {
  int vertexc, deglim;
  cin >> vertexc >> deglim;

  for (int i = 1; i <= vertexc - 1; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  dfs(1, 1, 0, deglim);

  for (int i = 1; i <= vertexc; i++) {
    adj[i].clear();
  }

  cout << dpwo[1] << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}
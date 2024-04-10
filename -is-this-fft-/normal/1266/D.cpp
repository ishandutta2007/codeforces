#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

typedef long long ll;

ll debt [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 1; i <= edgec; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    debt[u] += w;
    debt[v] -= w;
  }

  vector<int> sources;
  vector<int> sinks;
  for (int i = 1; i <= vertexc; i++) {
    if (debt[i] > 0) {
      sources.push_back(i);
    } else if (debt[i] < 0) {
      sinks.push_back(i);
    }
  }

  vector<vector<ll>> ans;
  while (!sources.empty() && !sinks.empty()) {
    int u = sources.back();
    int v = sinks.back();

    ll mn = min(debt[u], -debt[v]);
    ans.push_back({u, v, mn});
    debt[u] -= mn;
    debt[v] += mn;
    if (debt[u] == 0) sources.pop_back();
    if (debt[v] == 0) sinks.pop_back();
  }

  cout << (int) ans.size() << '\n';
  for (auto v : ans) {
    for (auto u : v) {
      cout << u << " ";
    }
    cout << '\n';
  }
}
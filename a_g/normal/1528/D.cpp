#include <bits/stdc++.h>
using namespace std;

const int N = 605;
const int INF = 1e9+1e6;
vector<pair<int, int>> edges[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back(make_pair(b, c));
  }

  for (int i = 0; i < n; i++) {
    vector<int> ans(n, INF);
    vector<bool> visited(n, 0);
    for (pair<int, int> e: edges[i]) {
      ans[e.first] = min(ans[e.first], e.second);
    }
    for (int j = 0; j < n; j++) {
      int v = -1;
      for (int k = 0; k < n; k++) {
        if (!visited[k] && (v == -1 || ans[k] < ans[v])) {
          v = k;
        }
      }
      visited[v] = 1;
      for (pair<int, int> e: edges[v]) {
        int target = (ans[v] + e.first)%n;
        ans[target] = min(ans[target], ans[v]+e.second);
      }
      ans[(v+1)%n] = min(ans[(v+1)%n], ans[v]+1);
    }
    ans[i] = 0;
    for (int d: ans) {
      cout << d << ' ';
    }
    cout << '\n';
  }
}
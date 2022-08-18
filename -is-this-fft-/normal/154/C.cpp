#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

typedef long long llong;

const int MAX_VERTEX = 1000005;

using namespace std;

vector<int> adj [MAX_VERTEX * 2];

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= vertexc; i++) {
    sort(adj[i].begin(), adj[i].end());
  }

  for (int i = 1; i <= vertexc; i++) {
    adj[vertexc + i] = adj[i];
    adj[vertexc + i].push_back(i);
    sort(adj[vertexc + i].begin(), adj[vertexc + i].end());
  }

  sort(adj + 1, adj + 1 + 2 * vertexc);

  llong ans = 0, curl = 1;
  for (int i = 2; i <= 2 * vertexc; i++) {
    if (adj[i] == adj[i - 1]) {
      curl++;
    } else {
      ans += curl * (curl - 1) / 2;
      curl = 1;
    }
  }
  ans += curl * (curl - 1) / 2;

  cout << ans << endl;
}
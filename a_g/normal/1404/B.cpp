#include <bits/stdc++.h>
#define ll long long
using namespace std;

pair<int, int> farthestvtx(vector<vector<int>> &nbrs, int vtx) {
  int n = nbrs.size();
  set<int> visited;
  queue<pair<int, int>> q;
  q.push({vtx, 0});
  while (visited.size() < n-1) {
    pair<int, int> next = q.front();
    q.pop();
    visited.insert(next.first);
    for (int nbr: nbrs[next.first]) {
      if (visited.find(nbr) == visited.end()) {
        q.push({nbr, next.second+1});
      }
    }
  }
  return q.front();
}

int dist(vector<vector<int>> &nbrs, int start, int end) {
  set<int> visited;
  queue<pair<int, int>> q;
  q.push({start, 0});
  while (1) {
    pair<int, int> next = q.front();
    q.pop();
    if (next.first == end) {
      return next.second;
    }
    visited.insert(next.first);
    for (int nbr: nbrs[next.first]) {
      if (visited.find(nbr) == visited.end()) {
        q.push({nbr, next.second+1});
      }
    }
  }
}

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--, b--;
    // cout << n << endl;
    vector<vector<int>> nbrs(n);
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      nbrs[u].push_back(v);
      nbrs[v].push_back(u);
    }
    int endpoint = farthestvtx(nbrs, 0).first;
    int diameter = farthestvtx(nbrs, endpoint).second;
    int currentdist = dist(nbrs, a, b);
    // cout << diameter << endl;
    // cout << currentdist << endl;

    if (min(db, diameter) <= 2*da || currentdist <= da) {
      cout << "Alice" << '\n';
    }
    else  {
      cout << "Bob" << '\n';
    }
  }
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  ll val;
  cin >> n;
  vector<ll> a;
  vector<int> bitcounts(64, 0);
  for (int i = 0; i < n; i++) {
    cin >> val;
    for (int j = 0; j < 64; j++) {
      if ((val>>j)&1) {
        bitcounts[j]++;
        if (bitcounts[j] > 2) {
          cout << "3\n";
          return 0;
        }
      }
    }
    if (val > 0) a.push_back(val);
  }
  bool found = 0;
  int ans = 1e9;
  int m = a.size();
  vector<vector<int>> adj(m);
  for (int i = 0; i < m; i++) {
    for (int j = i+1; j < m; j++) {
      if (a[i] & a[j]) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    set<int> visited;
    vector<int> dists(m, -1);
    queue<int> q;
    q.push(i);
    dists[i] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      visited.insert(v);
      vector<int> closerdists;
      for (int u: adj[v]) {
        if (!visited.count(u)) {
          q.push(u);
        }
        else {
          closerdists.push_back(dists[u]);
        }
      }
      if (closerdists.size() == 1) {
        dists[v] = closerdists[0] + 1;
      }
      else if (closerdists.size() > 1) {
        sort(closerdists.begin(), closerdists.end());
        found = 1;
        ans = min(ans, closerdists[0]+closerdists[1]+2);
        break;
      }
    }
  }
  cout << (found ? ans : -1) << '\n';
}
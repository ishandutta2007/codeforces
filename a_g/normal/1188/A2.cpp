#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<vector<int>> operations;

int leaf(int v, int p) {
  for (pair<int, int> e: adj[v]) {
    if (e.first != p) return leaf(e.first, v);
  }
  return v;
}


void solve(int v, int p) {
  for (pair<int, int> e: adj[v]) {
    int u = e.first;
    int x = e.second;
    if (u != p) {
      vector<int> uleaves;
      vector<int> vleaves;
      for (pair<int, int> f: adj[v]) {
        if (f.first != u) {
          vleaves.push_back(leaf(f.first, v));
          if (vleaves.size() >= 2) break;
        }
      }
      for (pair<int, int> f: adj[u]) {
        if (f.first != v) {
          uleaves.push_back(leaf(f.first, u));
          if (uleaves.size() >= 2) break;
        }
      }
      if (adj[v].size() == 1) {
        if (adj[u].size() == 1) {
          operations.push_back({u+1, v+1, x});
        }
        else {
          assert(uleaves.size() >= 2);
          int a = uleaves[0];
          int b = uleaves[1];
          operations.push_back({a+1, v+1, x/2});
          operations.push_back({b+1, v+1, x/2});
          operations.push_back({a+1, b+1, -x/2});
        }
      }
      else if (adj[u].size() == 1) {
        assert(vleaves.size() >= 2);
        int a = vleaves[0];
        int b = vleaves[1];
        operations.push_back({a+1, u+1, x/2});
        operations.push_back({b+1, u+1, x/2});
        operations.push_back({a+1, b+1, -x/2});
      }
      else {
        int a = uleaves[0];
        int b = uleaves[1];
        int c = vleaves[0];
        int d = vleaves[1];
        operations.push_back({a+1, c+1, x/2});
        operations.push_back({b+1, d+1, x/2});
        operations.push_back({a+1, b+1, -x/2});
        operations.push_back({c+1, d+1, -x/2});
      }
      solve(u, v);
    }
  }
}


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  adj.resize(n);
  for (int i = 0; i < n-1; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    u--, v--;
    adj[u].push_back({v, x});
    adj[v].push_back({u, x});
  }
  for (int i = 0; i < n; i++) {
    if (adj[i].size() == 2) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  solve(0, 0);
  cout << operations.size() << endl;
  for (vector<int> op: operations) {
    cout << op[0] << " " << op[1] << " " << op[2] << endl;
  }
}
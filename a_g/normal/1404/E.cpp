#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> matching;
vector<bool> used;

bool kuhn(int v, vector<vector<int>>& adj) {
  if (used[v]) return 0;
  used[v] = 1;
  for (int j: adj[v]) {
    if (matching[j] == -1 || kuhn(matching[j], adj)) {
      matching[j] = v;
      return 1;
    }
  }
  return 0;
}


int main () {
  int n, m;
  cin >> n >> m;
  bool grid[n][m];
  int count = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      grid[i][j] = (s[j] == '#');
      if (grid[i][j]) count++;
    }
  }
  
  vector<pair<int, int>> hpairs;
  vector<pair<int, int>> vpairs;
  vector<vector<int>> adj(m*n);
  map<pair<int, int>, int> vpairindices;
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] && grid[i+1][j]) {
        vpairindices[pair<int, int>(i, j)] = vpairs.size();
        vpairs.push_back({i, j});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m-1; j++) {
      if (grid[i][j] && grid[i][j+1]) {
        int index = hpairs.size();
        hpairs.push_back({i, j});
        if (i > 0 && grid[i-1][j]) {
          adj[index].push_back(vpairindices[{i-1, j}]);
        }
        if (i > 0 && grid[i-1][j+1]) {
          adj[index].push_back(vpairindices[{i-1, j+1}]);
        }
        if (i < n-1 && grid[i+1][j]) {
          adj[index].push_back(vpairindices[{i, j}]);
        }
        if (i < n-1 && grid[i+1][j+1]) {
          adj[index].push_back(vpairindices[{i, j+1}]);
        }
      }

    }
  }


  int k = hpairs.size();
  int l = vpairs.size();
  int matches = 0;
  matching.assign(l, -1);
  for (int i = 0; i < k; i++) {
    used.assign(k, 0);
    matches += kuhn(i, adj);
  }
  cout << count-k-l+matches << endl;
  // count -|independent set|
  // indpendent set = total vertices - matching size
}
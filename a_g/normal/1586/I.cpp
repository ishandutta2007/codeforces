#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> traversal(int n, int i) {
  vector<pair<pair<int, int>, int>> result;
  for (int j = 0; j < 2*i+1; j++) {
    int k = (j & 1) ? -1 : 1;
    result.push_back({{j, 2*i-j}, k});
  }
  for (int j = 0; j < 2*i+1; j++) {
    int k = (j & 1) ? -1 : 1;
    result.push_back({{2*n-1-j, 2*n-2*i+j-1}, k});
  }
  for (int j = 0; j < 2*n-2*i-1; j++) {
    int k = (j & 1) ? -1 : 1;
    result.push_back({{j, j+2*i+1}, k});
  }
  for (int j = 0; j < 2*n-2*i-1; j++) {
    int k = (j & 1) ? -1 : 1;
    result.push_back({{j+2*i+1, j}, k});
  }
  return result;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  if (n & 1) {
    cout << "NONE" << endl;
    return 0;
  }
  int m = n/2;
  int grid[n][n];
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < n; j++) {
      if (row[j] == 'S') grid[i][j] = 1;
      else if (row[j] == 'G') grid[i][j] = -1;
      else grid[i][j] = 0;
    }
  }
  bool multiple = 0;
  for (int i = 0; i < m; i++) {
    int sign = 0;
    for (pair<pair<int, int>, int> p: traversal(m, i)) {
      int u = p.first.first;
      int v = p.first.second;
      int s = p.second;
      if (grid[u][v] != 0) {
        if (sign == 0) sign = grid[u][v]*s;
        else if (grid[u][v]*s != sign) {
          cout << "NONE" << endl;
          return 0;
        }
      }
    }
    if (sign == 0) multiple = 1; // wait for other iters in case NONE
    for (pair<pair<int, int>, int> p: traversal(m, i)) {
      int u = p.first.first;
      int v = p.first.second;
      int s = p.second;
      grid[u][v] = sign*s;
    }
  }
  if (multiple) {
    cout << "MULTIPLE" << endl;
    return 0;
  }

  cout << "UNIQUE" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ((grid[i][j] == 1) ? 'S' : 'G');
    }
    cout << endl;
  }
}
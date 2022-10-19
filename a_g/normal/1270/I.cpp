#include <bits/stdc++.h>
using namespace std;

long long grid[2][512][512];
int dim;

int add(int x, int y) {
  return (x+y >= dim ? x+y-dim : x+y);
}

int sub(int x, int y) {
  return (x-y < 0 ? x-y+dim : x-y);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int k;
  cin >> k;

  dim = 1<<k;
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      cin >> grid[0][i][j];
    }
  }

  int t;
  cin >> t;
  vector<pair<int, int>> fig(t);
  for (pair<int, int>& p: fig) {
    cin >> p.first >> p.second;
    p.first--, p.second--;
  }

  for (int q = 0; q < k; q++) {
    for (int i = 0; i < dim; i++) {
      for (int j = 0; j < dim; j++) {
        grid[1-q&1][i][j] = 0;
        for (pair<int, int>& p: fig) {
          int x = sub(i, p.first);
          int y = sub(j, p.second);
          grid[1-q&1][i][j] ^= grid[q&1][x][y];
        }
      }
    }
    for (pair<int, int>& p: fig) {
      p.first = add(p.first, p.first);
      p.second = add(p.second, p.second);
    }
  }

  int ans = 0;
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      if (grid[k&1][i][j]) ans++;
    }
  }
  cout << ans << '\n';
}
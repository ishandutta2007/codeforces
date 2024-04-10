#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 105;

typedef long long ll;

int grid [MAX_N][MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int oi = n - i - 1;
      int oj = m - j - 1;
      if (i <= oi && j <= oj) {
        vector<int> cs;
        cs.push_back(grid[i][j]);
        if (oi != i) {
          cs.push_back(grid[oi][j]);
        }
        if (oj != j) {
          cs.push_back(grid[i][oj]);
        }
        if (oi != i || oj != j) {
          cs.push_back(grid[oi][oj]);
        }

        sort(cs.begin(), cs.end());
        int med = cs[(int) cs.size() / 2];

        for (int u : cs) {
          ans += abs(med - u);
        }
      }
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}
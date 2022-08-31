#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> psize (const vector<vector<int>> &a) {
  int n = (int) a.size() - 2;
  int m = (int) a[0].size() - 2;
  vector<vector<int>> ps = a;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ps[i][j] += ps[i][j - 1];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ps[i][j] += ps[i - 1][j];
    }
  }
  return ps;
}

int n, m;
vector<vector<int>> grid;
vector<vector<int>> gridps;

int getsum (int i1, int i2, int j1, int j2) {
  i1--; j1--;
  return gridps[i2][j2] - gridps[i1][j2] - gridps[i2][j1] + gridps[i1][j1];
}

vector<vector<char>> buildans (int t) {
  int w = 2 * t + 1;
  vector<vector<char>> ans (n + 2, vector<char> (m + 2, '.'));
  for (int i = 1; i + w <= n + 1; i++) {
    for (int j = 1; j + w <= m + 1; j++) {
      if (getsum(i, i + w - 1, j, j + w - 1) == w * w) {
        ans[i + t][j + t] = 'X';
      }
    }
  }
  return ans;
}

vector<vector<int>> build (int t) {
  int w = 2 * t + 1;
  vector<vector<int>> ans (n + 2, vector<int> (m + 2, 0));
  for (int i = 1; i + w <= n + 1; i++) {
    for (int j = 1; j + w <= m + 1; j++) {
      if (getsum(i, i + w - 1, j, j + w - 1) == w * w) {
        ans[i][j]++;
        ans[i][j + w]--;
        ans[i + w][j]--;
        ans[i + w][j + w]++;
      }
    }
  }

  return psize(ans);
}

bool check (int t) {
  vector<vector<int>> bt = build(t);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((bt[i][j] > 0) != (grid[i][j] > 0)) {
        return false;
      }
    }
  }
  return true;
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n >> m;

  grid = vector<vector<int>> (n + 2, vector<int> (m + 2, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;

      if (c == 'X') grid[i][j] = 1;
    }
  }

  gridps = psize(grid);

  int ans = 0;
  for (int k = 1 << 20; k != 0; k /= 2) {
    if (2 * (ans + k) + 1 <= min(n, m) && check(ans + k)) {
      ans += k;
    }
  }

  auto ansgr = buildans(ans);
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ansgr[i][j];
    }
    cout << '\n';
  }
}
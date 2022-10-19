#include <bits/stdc++.h>
using namespace std;

const int N = 203;
const long long INF = 1e18;
int c[N][N];
long long csum[N][N];
pair<long long, int> dp[N][N];
int par[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c[i][j];
      csum[i][j+1] = csum[i][j] + c[i][j];
    }
  }
  for (int d = 0; d < n; d++) {
    for (int i = 0; i+d < n; i++) {
      dp[i][i+d] = make_pair(INF, 0);
      long long ex = 0;
      for (int j = i; j <= i+d; j++) {
        ex += csum[j][i] + (csum[j][n] - csum[j][i+d+1]);
      }
      for (int j = i; j <= i+d; j++) {
        // pick j as the root
        dp[i][i+d] = min(dp[i][i+d], make_pair(dp[i][j-1].first + dp[j+1][i+d].first + ex, j));
      }
    }
  }
  
  function<int(int, int)> label = [&] (int l, int r) {
    if (l > r) return N-1;
    int j = dp[l][r].second;
    int x = label(l, j-1);
    int y = label(j+1, r);
    par[x] = j+1;
    par[y] = j+1;
    return j;
  };

  label(0, n-1);
  for (int i = 0; i < n; i++) {
    cout << par[i] << ' ';
  }
  cout << '\n';
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < m; i += 2) {
    a[0][i] = a[n - 1][i] = 1;
  }
  for (int i = 2; i <= n - 3; i += 2) {
    a[i][0] = a[i][m - 1] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j];
    }
    cout << "\n";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin>> t;
  while (t--) {
    solve();
  }
}
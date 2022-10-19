#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1005;
int bell[N][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  bell[0][0] = 1;
  for (int i = 1; i < N; i++) {
    bell[i][0] = bell[i-1][i-1];
    for (int j = 1; j <= i; j++) {
      bell[i][j] = bell[i][j-1]+bell[i-1][j-1];
      if (bell[i][j] >= MOD) bell[i][j] -= MOD;
    }
  }

  int m, n;
  cin >> m >> n;
  map<long long, int> repr;
  vector<string> a(n);
  for (string& x: a) cin >> x;
  for (int i = 0; i < m; i++) {
    long long mask = 0;
    for (int j = 0; j < n; j++) {
      if (a[j][i] == '1') mask |= 1LL<<j;
    }
    repr[mask]++;
  }
  int ans = 1;
  for (pair<long long, int> p: repr) {
    ans = 1LL*ans*bell[p.second][0] % MOD;
  }
  cout << ans << '\n';
}
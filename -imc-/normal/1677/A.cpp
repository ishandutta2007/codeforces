#include <bits/stdc++.h>

using namespace std;

using li = long long;

#define all(v) (v).begin(), (v).end()

void solve(bool read) {
  int n;
  cin >> n;

  vector<int> p(n);
  // less[val][i]
  vector<vector<int>> less(n, vector<int>(n));
  vector<vector<int>> less_s(n, vector<int>(n));
  for (int& x : p) {
    cin >> x;
    --x;
  }

  for (int val = 0; val < n; ++val) {
    for (int i = 0; i < n; ++i) {
      less[val][i] = (i ? less[val][i - 1] : 0) + (p[i] < val ? 1 : 0);
    }
    for (int i = n - 1; i >= 0; --i) {
      less_s[val][i] = (i + 1 < n ? less_s[val][i + 1] : 0) + (p[i] < val ? 1 : 0);
    }
  }

  li ans = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j + 1 < n; ++j) {
      ans += less[p[j]][i - 1] * less_s[p[i]][j + 1];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //while (true) solve(false);

  return 0;
}
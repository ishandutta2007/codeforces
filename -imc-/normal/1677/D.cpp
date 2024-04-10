#include <bits/stdc++.h>

using namespace std;

using li = long long;

#define all(v) (v).begin(), (v).end()

void solve(bool read) {
  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  for (int i = n - k; i < n; ++i) {
    if (v[i] != 0 && v[i] != -1) {
      cout << 0 << "\n";
      return;
    }
  }

  const li MOD = 998244353;

  li ans = 1;
  for (int i = n - k - 1; i >= 0; --i) {
    if (v[i] == -1) {
      ans = (ans * (i + k + 1)) % MOD;
    } else {
      if (v[i] != 0) {
        if (v[i] + k > i + k) {
          ans = 0;
        }
      } else {
        int mx = min(k, i + k);
        ans = ans * (mx + 1) % MOD;
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    ans = (ans * (i + 1)) % MOD;
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
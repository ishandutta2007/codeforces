#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

void solve(bool read = true) {
  int n;
  cin >> n;

  vector<int> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  li ans = 0;

  bool have = false;
  bool all_ones = true;

  for (int i = 1; i < n - 1; ++i) {
    if (a[i] % 2 == 0) {
      have = true;
    }
    if (a[i] != 1) {
      all_ones = false;
    }

    ans += (a[i] + 1) / 2;
  }

  if (!have && (n == 3 || all_ones)) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  return 0;
}
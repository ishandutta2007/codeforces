#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

void solve(bool read = true) {
  int n;
  cin >> n;

  vector<int> a(n), p(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    p[i] = (i ? p[i - 1] : 0) + (a[i] == 0 ? 1 : 0);
  }

  li ans = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      int nz = p[r] - (l ? p[l - 1] : 0);
      ans += nz + (r - l + 1);
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

  return 0;
}
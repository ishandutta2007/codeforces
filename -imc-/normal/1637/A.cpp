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
    p[i] = max(i ? p[i - 1] : 0, a[i]);
  }

  int sm = 2e9;
  for (int i = n - 1; i >= 0; --i) {
    sm = min(sm, a[i]);
    if (i && sm < p[i - 1]) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
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
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

void solve() {
  vector<int> mx(10, -1);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int b, d;
    cin >> b >> d;
    d--;
    mx[d] = max(mx[d], b);
  }
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    if (mx[i] == -1) {
      cout << "MOREPROBLEMS\n";
      return;
    }
    ans += mx[i];
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
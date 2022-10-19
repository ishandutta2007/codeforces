#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  vector<pair<int, int>> shows(n);
  for (auto& [l, r]: shows) cin >> l >> r;
  sort(shows.begin(), shows.end());

  multiset<int, greater<int>> S;
  int ans = 0;
  for (auto& [l, r]: shows) {
    bool done = 0;
    auto it = S.lower_bound(l-1);
    if (it != S.end() && x > 1LL*(l-*it)*y) {
      int r0 = *it;
      ans = (ans+1LL*(r-r0)*y) % MOD;
    }
    else {
      ans = (ans+x+1LL*(r-l)*y) % MOD;
    }
    if (it != S.end()) S.erase(it);
    S.insert(r);
  }
  cout << ans << '\n';
}
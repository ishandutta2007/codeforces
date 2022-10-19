#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 3e5+2;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& [l, r]: a) cin >> l >> r;
  reverse(a.begin(), a.end());
  vector<int> cnt(n);
  
  set<int> s;
  for (int i = 0; i < N; i++) s.insert(i);

  for (int i = 0; i < n; i++) {
    int l = a[i].first;
    int r = a[i].second;
    for (auto it = s.lower_bound(l); it != s.end() && *it <= r; s.erase(it++)) {
      cnt[i]++;
    }
  }
  cnt[n-2] += cnt[n-1];
  cnt.pop_back();
  int ans = 0;
  int wt = 2;
  for (int i = 0; i < n-2; i++) {
    wt = 3LL*wt % MOD;
  }
  for (int i = 0; i < n-1; i++) {
    ans = (ans+1LL*wt*cnt[i]) % MOD;
    wt = 2LL*wt * (MOD+1)/3 % MOD;
  }
  cout << ans << '\n';
}
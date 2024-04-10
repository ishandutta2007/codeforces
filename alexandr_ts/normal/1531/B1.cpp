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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& x: a) {
    cin >> x.first >> x.second;
  }

  ll ans = 0;
  map<int, int> cnt;
  map<pair<int, int>, int> cnt2;
  for (auto x: a) {
    vector<int> sz = {x.first};
    if (x.first != x.second) {
      sz.push_back(x.second);
    }
    for (auto el: sz) {
      ans += cnt[el];
      cnt[el]++;
    }
    if (sz.size() == 2u) {
      if (sz[0] > sz[1]) swap(sz[0], sz[1]);
      ans -= cnt2[{sz[0], sz[1]}];
      cnt2[{sz[0], sz[1]}]++;
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
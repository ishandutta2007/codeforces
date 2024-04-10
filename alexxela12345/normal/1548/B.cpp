#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

ll gcd(ll a, ll b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

random_device rddev;
mt19937 rd(rddev());

void solve() {
  int n;
  cin >> n;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  vector<ll> df(n -1 );
  for (int i = 1; i < n; i++) {
    df[i - 1] = abs(arr[i] - arr[i - 1]);
  }
  vector<pair<ll, int>> st;
  int ans = 1;
  for (int i = 0; i < n - 1; i++) {
    for (auto &el : st) {
      el.first = gcd(el.first, df[i]);
    }
    st.push_back({df[i], i});
    vector<pair<ll, int>> st2;
    for (auto &el : st) {
      if (st2.empty() || st2.back().first != el.first) {
        st2.push_back(el);
      }
    }
    if (st2[0].first != 1) {
      ans = max(ans, i + 2);
    } else if (1 < st2.size()) {
      ans = max(ans, i + 2 - st2[1].second);
    }
    st = st2;
  }
  cout << ans << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
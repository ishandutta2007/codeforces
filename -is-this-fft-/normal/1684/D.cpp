#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve () {
  int n, K;
  cin >> n >> K;

  vector<ll> opts;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;

    ans += a;
    opts.push_back(-a + n - i - 1);
  }

  sort(opts.begin(), opts.end());
  for (int i = 0; i < K; i++) {
    ans += opts[i] - i;
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}
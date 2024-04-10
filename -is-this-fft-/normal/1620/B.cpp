#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve () {
  ll w, h;
  cin >> w >> h;

  ll ans = 0;
  vector<ll> ht = {h, h, w, w};
  for (int i = 0; i < 4; i++) {
    int k;
    cin >> k;

    ll mn, mx;
    cin >> mn;
    for (int j = 0; j < k - 1; j++) {
      cin >> mx;
    }

    ans = max(ans, (mx - mn) * ht[i]);
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
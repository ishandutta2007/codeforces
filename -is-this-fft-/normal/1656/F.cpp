#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 1e18 + 500;

ll mx (ll b, ll c, ll L, ll R) {
  return max(b * L + c, b * R + c);
}

void solve () {
  int n;
  cin >> n;
  
  vector<ll> arr (n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  sort(arr.begin(), arr.end());

  ll sm = arr[0];
  ll lg = arr[n - 1];

  if ((ll) (n - 2) * sm + sum > 0) {
    cout << "INF" << '\n';
    return;
  }

  if ((ll) (n - 2) * lg + sum < 0) {
    cout << "INF" << '\n';
    return;
  }
  
  ll pos = sum, neg = 0;
  ll ans = -INF;
  for (int i = 0; i < n - 1; i++) {
    // i is last negative
    pos -= arr[i];
    neg += arr[i];

    ll b = 0, c = 0;
    c += sm * pos;
    b += pos;
    b += sm * (ll) (n - i - 1);
    
    c += lg * neg;
    b += neg;
    b += lg * (ll) (i + 1);

    c -= sm * lg;
    b -= sm;
    b -= lg;

    ll L = -arr[i + 1];
    ll R = -arr[i];
    ans = max(ans, mx(b, c, L, R));
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
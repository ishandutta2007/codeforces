#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve () {
  int n;
  cin >> n;

  vector<ll> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  ll prevsum = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += prevsum - (ll) i * arr[i];
    prevsum += arr[i];
  }
  ans += arr.back();

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
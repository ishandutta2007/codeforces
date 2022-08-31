#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve () {
  int n;
  cin >> n;

  vector<ll> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = n - 1; i > 0; i--) {
    arr[i] -= arr[i - 1];
  }

  ll ans = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] < 0) {
      ans -= arr[i];
      arr[0] += arr[i];
    } else if (arr[i] > 0) {
      ans += arr[i];
    }
  }

  ans += abs(arr[0]);
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
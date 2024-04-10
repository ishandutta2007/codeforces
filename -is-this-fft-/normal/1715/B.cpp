#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve () {
  ll n, K, b, s;
  cin >> n >> K >> b >> s;

  if (b * K > s) {
    cout << -1 << '\n';
    return;
  }

  vector<ll> arr (n);
  arr[0] += b * K;
  s -= b * K;
  for (int i = 0; i < n; i++) {
    ll add = min(s, K - 1);
    s -= add;
    arr[i] += add;
  }

  if (s > 0) {
    cout << -1 << '\n';
    return;
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << '\n';
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
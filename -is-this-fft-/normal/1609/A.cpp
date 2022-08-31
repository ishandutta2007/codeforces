#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 20;

ll arr [MAX_N];

void solve () {
  int n;
  cin >> n;

  ll d2 = 1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];

    while (arr[i] % 2 == 0) {
      arr[i] /= 2;
      d2 *= 2;
    }
  }

  pair<ll, int> mx = make_pair(-1LL, -1);
  for (int i = 0; i < n; i++) {
    mx = max(mx, make_pair(arr[i], i));
  }

  arr[mx.second] *= d2;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += arr[i];
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
#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

typedef long long ll;

void solve () {
  int n;
  cin >> n;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  bool all1 = true;
  for (int i = 1; i < n - 1; i++) {
    ans += (arr[i] + 1) / 2;
    if (arr[i] != 1) {
      all1 = false;
    }
  }

  if (all1) {
    cout << -1 << '\n';
  } else if (n == 3 && arr[1] % 2 == 1) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
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
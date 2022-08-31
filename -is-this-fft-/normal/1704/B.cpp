#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 5;

void solve () {
  int n, X;
  cin >> n >> X;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int mn = arr[0], mx = arr[0], ans = 0;
  for (int i = 0; i < n; i++) {
    mn = min(mn, arr[i]);
    mx = max(mx, arr[i]);
    if (mx - mn > 2 * X) {
      ans++;
      mn = arr[i];
      mx = arr[i];
    }
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
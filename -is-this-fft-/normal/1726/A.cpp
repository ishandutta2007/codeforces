#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> a (n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = a[n - 1] - a[0];
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      ans = max(ans, a[i] - a[0]);
    }

    if (i != n - 1) {
      ans = max(ans, a[n - 1] - a[i]);
      ans = max(ans, a[i] - a[i + 1]);
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
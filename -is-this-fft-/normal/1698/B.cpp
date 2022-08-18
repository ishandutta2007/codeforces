#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n, K;
  cin >> n >> K;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (K == 1) {
    cout << (n - 1) / 2 << '\n';
    return;
  }

  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    if (arr[i] > arr[i - 1] + arr[i + 1]) {
      ans++;
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
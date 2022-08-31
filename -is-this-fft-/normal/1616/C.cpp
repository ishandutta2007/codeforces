#include <iostream>

using namespace std;

const int MAX_N = 77;

int arr [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ans = n - 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int cur = 0;
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) continue;

        if ((arr[j] - arr[i]) * (k - i) != (arr[k] - arr[i]) * (j - i)) {
          cur++;
        }
      }
      ans = min(ans, cur);
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
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 20;

int arr [MAX_N];
int has [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  for (int i = 1; i <= 2 * n + 5; i++) {
    has[i] = 0;
  }

  for (int i = n - 1; i >= 0; i--) {
    if (!has[arr[i] + 1]) {
      arr[i]++;
    }
    has[arr[i]] = 1;
  }

  int ans = 0;
  for (int i = 1; i <= 2 * n + 5; i++) {
    ans += has[i];
  }
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}
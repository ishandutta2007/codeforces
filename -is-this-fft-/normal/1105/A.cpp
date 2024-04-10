#include <iostream>

using namespace std;

const int MAX_N = 1005;

int arr [MAX_N];

int try_with (int t, int n) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] < t - 1) {
      ans += t - 1 - arr[i];
    } else if (arr[i] > t + 1) {
      ans += arr[i] - t - 1;
    }
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  pair<int, int> ans = {10000000, -1};
  for (int i = 1; i <= 100; i++) {
    ans = min(ans, {try_with(i, n), i});
  }
  cout << ans.second << " " << ans.first << '\n';
}
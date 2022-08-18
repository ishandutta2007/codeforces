#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll solve (const vector<int> &arr, int fst) {
  ll ans = 0;
  int cf = 0, co = 0;
  for (int u : arr) {
    if (u % 2 == fst) {
      ans += max(0, co - cf);
      cf++;
    } else {
      ans += max(0, cf - co - 1);
      co++;
    }
  }
  return ans;
}

void solve () {
  int n;
  cin >> n;
  
  vector<int> arr (n);
  vector<int> cnt (2, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i] % 2]++;
  }

  if (cnt[0] == cnt[1]) {
    cout << min(solve(arr, 0), solve(arr, 1)) << '\n';
  } else if (cnt[0] == cnt[1] + 1) {
    cout << solve(arr, 0) << '\n';
  } else if (cnt[1] == cnt[0] + 1) {
    cout << solve(arr, 1) << '\n';
  } else {
    cout << -1 << '\n';
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
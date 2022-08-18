#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
  int n, l, r, K;
  cin >> n >> l >> r >> K;

  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    
    if (l <= x && x <= r) {
      arr.push_back(x);
    }
  }

  sort(arr.begin(), arr.end());

  int ans = 0;
  for (int u : arr) {
    if (u <= K) {
      ans++;
      K -= u;
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
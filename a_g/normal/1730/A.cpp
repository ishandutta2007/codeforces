#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, c;
    cin >> n >> c;
    vector<int> cnt(105);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    int ans = 0;
    for (int x: cnt) {
      ans += min(c, x);
    }
    cout << ans << '\n';
  }
}
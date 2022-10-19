#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;
    vector<int> cnt(102);
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++)
      ans += min(cnt[i], c);
    cout << ans << '\n';
  }
}
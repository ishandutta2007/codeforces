#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    vector<int> c(k);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      ans += a/k;
      c[a%k]++;
    }
    int l = 1;
    int r = k-1;
    while (l <= r) {
      if (!c[r]) {
        r--;
        continue;
      }
      if (!c[l]) {
        l++;
        continue;
      }
      if (l+r < k) {
        l++;
        continue;
      }
      if (l == r) {
        if (c[l] >= 2) {
          c[l] -= 2;
          ans++;
          continue;
        }
        else {
          break;
        }
      }
      c[l]--;
      c[r]--;
      ans++;
    }
    cout << ans << '\n';
  }
}
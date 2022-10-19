#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[x] = i;
    }
    long long ans = 0;
    int L = n;
    int R = -1;
    for (int i = 1; i <= n; i++) {
      // length i
      if (i&1) {
        L = min(L, a[i/2]);
        R = max(R, a[i/2]);
      }
      // 0 <= s <= L
      // R+1 <= s+i <= n
      ans += max(0, min(n-i, L)-max(0, R+1-i)+1);
    }
    cout << ans << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      p[a[i]] = i;
    }
    int ans = 1;
    int l = p[0];
    int r = p[0];
    int open = 0;
    for (int i = 1; i < n; i++) {
      if (p[i] < l) {
        open += l-p[i]-1;
        l = p[i];
      }
      else if (p[i] > r) {
        open += p[i]-r-1;
        r = p[i];
      }
      else {
        ans = 1LL * ans * open % MOD;
        open--;
      }
    }
    cout << ans << '\n';
  }
}
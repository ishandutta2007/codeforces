#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int pos = 0;
    int neg = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = -INF;
    for (int j = 0; j < 5; j+=2) {
      long long prod = 1;
      for (int k = 0; k < j; k++) {
        prod *= a[k];
      }
      for (int k = 0; k < 5-j; k++) {
        prod *= a[n-1-k];
      }
      ans = max(ans, prod);
    }
    cout << ans << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int m = n*k;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[m-1-i];
    int l = n/2+1;
    long long ans = 0;
    for (int i = 0; i < k; i++) {
      ans += a[(i+1)*l-1];
    }
    cout << ans << '\n';
  }
}
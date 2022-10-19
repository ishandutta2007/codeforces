#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < k; i++) {
      ans += a[n-1-i-k]/a[n-1-i];
    }
    a.resize(n-2*k);
    ans += accumulate(a.begin(), a.end(), 0);
    cout << ans << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n-1; i++) {
      ans += abs(a[i+1]-a[i]);
    }
    ans += min({a[0]-1, a[n-1]-1, 2*(mn-1)});
    if (x > mx) {
      ans += min({abs(x-a[0]), abs(x-a[n-1]), 2*(x-mx)});
    }
    cout << ans << '\n';
  }
}
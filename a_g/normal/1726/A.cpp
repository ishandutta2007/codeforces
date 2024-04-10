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
    for (int& x: a) cin >> x;
    int ans = a[n-1]-a[0];
    ans = max(ans, *max_element(a.begin()+1, a.end())-a[0]);
    ans = max(ans, a[n-1]-*min_element(a.begin(), a.end()-1));
    for (int i = 0; i+1 < n; i++) {
      ans = max(ans, a[i]-a[i+1]);
    }
    cout << ans << '\n';
  }
}
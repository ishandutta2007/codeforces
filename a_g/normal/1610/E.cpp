#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 1e9;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      if (i > 0 && a[i] == a[i-1]) continue;
      int j = i+1;
      while (j < n && a[j] == a[i]) j++;
      int len = j-i;
      if (j == n) {
        ans = min(ans, n-len);
        break;
      }
      int index = j;
      while (index < n) {
        index = lower_bound(a.begin(), a.end(), 2*a[index]-a[i])-a.begin();
        len++;
      }
      ans = min(ans, n-len);
    }
    cout << ans << endl;
  }
}
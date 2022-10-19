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
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> suff;
    int tot = 0;
    for (int i = 0; i < n; i++) {
      tot += a[n-1-i];
      suff[tot] = i+1;
    }
    int ans = 0;
    tot = 0;
    for (int i = 0; i < n; i++) {
      tot += a[i];
      if (suff.count(tot) && suff[tot] + i + 1 <= n) {
        ans = i+1+suff[tot];
      }
    }
    cout << ans << '\n';
  }
}
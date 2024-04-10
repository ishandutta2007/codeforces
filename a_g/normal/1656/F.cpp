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
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long tot = accumulate(a.begin(), a.end(), 0LL);
    if (tot+1LL*(n-2)*a[n-1] < 0 || tot+1LL*(n-2)*a[0] > 0) {
      cout << "INF\n";
      continue;
    }
    vector<long long> pref(n+1), suff(n+1);
    for (int i = 0; i < n; i++) {
      pref[i+1] = pref[i] + a[i];
    }
    for (int i = n-1; i >= 0; i--) {
      suff[i] = suff[i+1] + a[i];
    }
    long long ans = -1e18;
    for (int i = 0; i < n; i++) {
      // t = -a[i]
      long long left = (a[0]-a[i]) * (suff[i+1]-1LL*(n-1-i)*a[i]);
      long long right = (a[n-1]-a[i]) * (pref[i]-1LL*i*a[i]);
      ans = max(ans, left+right-1LL*(a[0]-a[i])*(a[n-1]-a[i])-1LL*(n-1)*a[i]*a[i]);
    }
    cout << ans << '\n';
  }
}
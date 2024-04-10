#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), ans(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long tot = accumulate(a.begin(), a.end(), 0LL);
    int cnt = tot/n;
    for (int i = 0; i < n-1; i++) {
      a[i] -= a[i+1];
    }

    for (int i = n-1; i >= 0; i--) {
      if (i != n-1) a[i] += a[i+1];
      if (cnt) {
        a[i]--;
        if (i >= cnt) a[i-cnt]++;
      }
      if (a[i]) {
        assert(a[i] == i);
        cnt--;
        ans[i] = 1;
      }
    }
    if (cnt) ans[0] = 1;

    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i==n-1];
    }
  }
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int g = __gcd(n, d);
    bool valid = true;
    int ans = 0;
    for (int i = 0; i < g; i++) {
      int startrun = 0;
      int endrun = 0;
      int maxrun = 0;
      int currentrun = 0;
      bool start = 1;
      bool haszero = 0;
      for (ll j = 0; j < n/g; j++) {
        if (a[(d*j+i)%n]) {
          currentrun++;
          if (start) startrun++;
          endrun++;
        }
        else {
          maxrun = max(currentrun, maxrun);
          start = 0;
          currentrun = 0;
          endrun = 0;
          haszero = 1;
        }
      }
      maxrun = max(maxrun, startrun+endrun);
      if (!haszero) valid = 0;
      ans = max(ans, maxrun);
    }
    if (valid) cout << ans << endl;
    else cout << -1 << endl;
  }
}
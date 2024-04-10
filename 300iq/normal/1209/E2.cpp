#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <vector <int> > a(n, vector <int> (m));
    vector <int> cs(m);
    vector <int> ord(m);
    for (int i= 0; i < m; i++) {
      ord[i] = i;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        cs[j] = max(cs[j], a[i][j]);
      }
    }
    sort(ord.begin(), ord.end(), [&] (int i, int j) {
      return cs[i] > cs[j];
    });
    if (ord.size() > n) {
      ord.resize(n);
    }
    vector <int> dp(1 << n);
    for (int i = 0; i < (int) ord.size(); i++) {
      int r = ord[i];
      auto ndp = dp;
      vector <int> best(1 << n);
      for (int s = 0; s < n; s++) {
        for (int j = 0; j < (1 << n); j++) {
          int nmask = 0;
          int nsum = 0;
          for (int i = 0; i < n; i++) {
            if ((j >> i) & 1) {
              nmask |= (1 << ((i + s) % n));
              nsum += a[i][r];
            }
          }
          best[nmask] = max(best[nmask], nsum);
        }
      }
      for (int nmask = 0; nmask < (1 << n); nmask++) {
        for (int mask = nmask; mask < (1 << n); mask = (mask + 1) | nmask) {
          ndp[mask] = max(ndp[mask], dp[mask ^ nmask] + best[nmask]);
        }
      }
      dp = ndp;
    }
    cout << dp[(1 << n) - 1] << endl;
  }
}
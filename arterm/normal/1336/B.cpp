#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


const int M = 100100;
const ll inf = 4e18;

int a[3][M];
int k[3];
int tot[3 * M];
int m;

ll value() {
  ll ans = 0;
  for (int i = 0; i < 3; ++i) {
    int j = (i + 1) % 3;
    ans += ll(a[i][k[i]] - a[j][k[j]]) * ll(a[i][k[i]] - a[j][k[j]]);
  }
  return ans;
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n[3];
    for (int i = 0; i < 3; ++i)
      cin >> n[i];

    m = 0;
  
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < n[i]; ++j) {
        cin >> a[i][j];
        tot[m++] = a[i][j];
      }

      sort(a[i], a[i] + n[i]);

      k[i] = 0;
    }

    sort(tot, tot + m);

    ll best = inf;

    for (int h = 0; h < m; ++h) {
      int x = tot[h];

      for (int i = 0; i < 3; ++i) {
        while (k[i] + 1 < n[i] && a[i][k[i] + 1] <= x)
          ++k[i];
      }

      for (int mask = 0; mask < 8; ++mask) {
        bool bad = false;

        for (int i = 0; i < 3; ++i)
          if ((mask >> i) & 1) {
            if (k[i] + 1 >= n[i]) {
              bad = true;
            }
          }

        if (bad) continue;
        
        for (int i = 0; i < 3; ++i)
          if ((mask >> i) & 1) {
            ++k[i];
          }

        best = min(best, value());

        for (int i = 0; i < 3; ++i)
          if ((mask >> i) & 1) {
            --k[i];
          }
      }

    }
    cout << best << "\n";
  }

}
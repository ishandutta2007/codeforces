#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

  int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int fib[200000];

const int mod = 1e9 + 7;

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  fib[1] = 1;
  for (int n = 2; n <= 100002; n++) {
    fib[n] = fib[n - 1] + fib[n - 2];
    if (fib[n] >= mod) fib[n] -= mod;
  }
  int n, m;
  cin >> n >> m;
  int value = (2 * fib[n + 1]) % mod;
  value += (2 * fib[m + 1]) % mod;
  value %= mod;
  value -= 2;
  if (value < 0) value += mod;
  cout << value << '\n';
  /*
  for (int n = 1; n <= 4; n++) {
    for (int m = 1; m <= 5; m++) {
      int lim = (1 << (n * m));
      int ans = 0;
      for (int mask = 0; mask < lim; mask++) {
        vector <vector <int> > a(n, vector <int> (m));
        bool bad = false;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m;j ++) {
            a[i][j] = ((mask >> (i * m + j)) & 1);
          }
        }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int t = 0; t < 4; t++) {
              int x = i + dx[t], y = j + dy[t];
              if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == a[i][j]) cnt++;
            }
            if (cnt > 1) bad = true;
          }
        }
        if (!bad) ans++;
      }
      if (n == 1) {
        //cout << ans << ' ' << 2 * fib[m + 1] << endl;
      } else {
        cout << ans << ' ' << 2 * fib[m + 1] + 2 * fib[n + 1] - 2 << endl;
      }
    }
  }
  */
}
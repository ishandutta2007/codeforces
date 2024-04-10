#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 1000100;
const int A = 3;

int n, m;
int d[M][A][A];
int a[M];

void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    a[x]++;
  }
}

int uax(int &x, int y) {
  return x = max(x, y);
}

void kill() {
  for (int i = 0; i <= m; ++i)
    for (int a = 0; a <= 2; ++a)
      for (int b = 0; b <= 2; ++b)
        d[i][a][b] = -1;

  d[0][0][0] = 0;
  int ans = 0;
  for (int x = 0; x < m; ++x) {
    int here = a[x];
    for (int i = 0; i <= 2; ++i)
      for (int j = 0; j <= 2; ++j) {
        int now = d[x][i][j];
        if (now == -1)
          continue;

        for (int a = 0; a <= i; ++a)
          for (int b = 0; b <= j; ++b)
            for (int c = 0; c <= 2; ++c) {
              int rem = here - a - b - c;
              if (rem < 0) continue;
              uax(d[x + 1][b][c], now + a + (rem / 3));
            }
      }
  }

  for (int a = 0; a <= 2; ++a)
    for (int b = 0; b <= 2; ++b)
      ans = max(ans, d[m][a][b]);

  cout << ans << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);


  read();
  kill();

}
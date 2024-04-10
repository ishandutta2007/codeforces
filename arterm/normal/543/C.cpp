#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 21;
const int inf = 1e9;

int d[1 << M];
int n, m;
int a[M][M];
int b[M][M], cost[M][M];
string s[M];

void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> s[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
}


void kill() {
  for (int i = 0; i < m; ++i) {
    for (char c = 'a'; c <= 'z'; c += 1) {
      int mask = 0;
      int sum = 0, mx = 0;

      for (int j = 0; j < n; ++j)
        if (s[j][i] == c) {
          mask |= 1 << j;
          sum += a[j][i];
          mx = max(mx, a[j][i]);
        }

      if (mask == 0)
        continue;

      for (int j = 0; j < n; ++j)
        if (s[j][i] == c) {
          b[j][i] = mask;
          cost[j][i] = sum - mx;
        }
    }
  }

  fill(d, d + (1 << n), inf);
  d[0] = 0;
  for (int mask = 0; mask + 1 < 1 << n; ++mask) {
    int x = 0;
    while ((mask >> x) & 1)
      ++x;
    for (int i = 0; i < m; ++i) {
      int to = mask | (1 << x);
      d[to] = min(d[to], d[mask] + a[x][i]);
      to |= b[x][i];
      d[to] = min(d[to], d[mask] + cost[x][i]);
    }
  }

  cout << d[(1 << n) - 1] << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}
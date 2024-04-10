#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int A = 13;
const int M = 1 << A;
const int N = 107;

int n, m, q;
int w[A];
int cnt[M];
int d[A][N][M];

void read() {
  cin >> n >> m >> q;
  for (int i = 0; i < n; ++i)
    cin >> w[n - 1 - i];
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    int cur = 0;
    for (char c : s)
      cur = (cur << 1) | (c == '1' ? 1 : 0);
    cnt[cur]++;
  }
}

void kill() {
  for (int i = n; i >= 0; --i)
    for (int s = 0; s < N; ++s)
      for (int mask = 0; mask < (1 << n); ++mask) {

        if (i == n) {
          d[i][s][mask] = cnt[mask];
          continue;
        }

        d[i][s][mask] += d[i + 1][s][mask ^ (1 << i)];
        if (s >= w[i])
          d[i][s][mask] += d[i + 1][s - w[i]][mask];
      }

  while (q--) {
    string t;
    int s;
    cin >> t >> s;
    int mask = 0;
    for (char c : t)
      mask = (mask << 1) | (c == '1' ? 1 : 0);
    cout << d[0][s][mask] << "\n";
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}
#include <bits/stdc++.h>

using namespace std;

const int A = 26;
const int N = 2010;
const int INF = 696969696;

char a[N], b[N];
int t, n, f[N][N];
vector <int> cntA[N], cntB[N];

int main() {
  for (int i = 0; i < N; ++i) {
    cntA[i].resize(A, 0), cntB[i].resize(A, 0);
  }
  cin >> t;
  while (t--) {
    scanf("%d %s %s", &n, a + 1, b + 1);
    cntA[n + 1].resize(A, 0), cntB[n + 1].resize(A, 0);
    for (int i = n; i >= 1; --i) {
      cntA[i] = cntA[i + 1], cntB[i] = cntB[i + 1];
      ++cntA[i][a[i] - 'a'], ++cntB[i][b[i] - 'a'];
    }
    if (cntA[1] != cntB[1]) {
      puts("-1"); continue;
    }
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) {
      if (i + j == 0) {
        f[i][j] = 0; continue;
      }
      f[i][j] = INF;
      if (!j) continue;
      if (i) {
        f[i][j] = min(f[i][j], 1 + f[i - 1][j]);
        if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
      }
      if (cntA[i + 1][b[j] - 'a'] > cntB[j + 1][b[j] - 'a']) {
        f[i][j] = min(f[i][j], f[i][j - 1]);
      }
    }
    int ans = f[n][n] > INF / 2 ? -1 : f[n][n];
    printf("%d\n", ans);
  }
  return 0;
}
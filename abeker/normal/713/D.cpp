#include <cstdio>
#include <algorithm>
using namespace std;

#define max4(a, b, c, d) max(max(a, b), max(c, d))

const int MAXN = 1005;
const int LOG = 10;

int N, M;
int a[MAXN][MAXN];
int dp[MAXN][MAXN][LOG][LOG];
int exp[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      scanf("%d", a[i] + j);
}

int get(int x1, int y1, int x2, int y2) {
  return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}

void init() {
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
  
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      int lo = 0, hi = min(N - i + 1, M - j + 1);
      while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (get(i, j, i + mid - 1, j + mid - 1) == mid * mid)
          lo = mid;
        else
          hi = mid - 1;
      }
      dp[i][j][0][0] = lo;  
    } 
  
  for (int k = 0; k < LOG; k++)
    for (int l = 0; l < LOG; l++)
      for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
          if (k)
            dp[i][j][k][l] = max(dp[i][j][k - 1][l], i + (1 << k - 1) > N ? 0 : dp[i + (1 << k - 1)][j][k - 1][l]);
          if (l)
            dp[i][j][k][l] = max(dp[i][j][k][l - 1], j + (1 << l - 1) > M ? 0 : dp[i][j + (1 << l - 1)][k][l - 1]);           
        }            
    
  for (int i = 2; i <= max(N, M); i++)
    exp[i] = exp[i / 2] + 1;
}

int query(int x1, int y1, int x2, int y2) {
  int ex = exp[x2 - x1 + 1];
  int ey = exp[y2 - y1 + 1];
  return max4(dp[x1][y1][ex][ey], dp[x1][y2 + 1 - (1 << ey)][ex][ey], dp[x2 + 1 - (1 << ex)][y1][ex][ey], dp[x2 + 1 - (1 << ex)][y2 + 1 - (1 << ey)][ex][ey]);
}

void solve() {
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int lo = 0, hi = min(x2 - x1 + 1, y2 - y1 + 1);
    while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      if (query(x1, y1, x2 - mid + 1, y2 - mid + 1) >= mid)
        lo = mid;
      else
        hi = mid - 1;
    }
    printf("%d\n", lo);
  }
}

int main() {
  load();
  init();
  solve();
  return 0;
}
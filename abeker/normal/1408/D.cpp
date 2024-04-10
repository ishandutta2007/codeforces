#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;
const int MAXC = 1e6 + 5;

int N, M;
int a[MAXN], b[MAXN];
int c[MAXN], d[MAXN];
int maks[MAXC];

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%d%d", a + i, b + i);
  for (int i = 0; i < M; i++)
    scanf("%d%d", c + i, d + i);
  
  memset(maks, -1, sizeof maks);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (a[i] <= c[j] && b[i] <= d[j]) 
        maks[c[j] - a[i]] = max(maks[c[j] - a[i]], d[j] - b[i]);
  
  int ans = 2 * MAXC;
  for (int i = MAXC - 2; i >= 0; i--) {
    maks[i] = max(maks[i], maks[i + 1]);
    ans = min(ans, i + maks[i] + 1);
  }
  
  printf("%d\n", ans);
  
  return 0;
}
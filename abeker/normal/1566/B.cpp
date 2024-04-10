#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
char s[MAXN];

int solve() {
  scanf("%s", s);
  N = strlen(s);
  int mini = N, maks = -1, cnt = 0;
  for (int i = 0; i < N; i++)
    if (s[i] == '0') {
      mini = min(mini, i);
      maks = max(maks, i);
      cnt++;
    }
  if (!cnt)
    return 0;
  if (maks - mini + 1 == cnt)
    return 1;
  return 2;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%d\n", solve());
  return 0;
}
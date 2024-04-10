#include <bits/stdc++.h>
using namespace std;

int solve() {
  int N, M;
  scanf("%d%d", &N, &M);
  if (N == 1 && M == 1)
    return 0;
  if (N == 1 || M == 1)
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
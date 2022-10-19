#include <bits/stdc++.h>
using namespace std;

int solve() {
  int N, X;
  scanf("%d%d", &N, &X);
  int mini = 2e9, maks = 0, sol = 0;
  while (N--) {
    int x;
    scanf("%d", &x);
    mini = min(mini, x);
    maks = max(maks, x);
    if (maks - mini > 2 * X) {
      mini = maks = x;
      sol++;
    }
  }
  return sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%d\n", solve());
  return 0;
}
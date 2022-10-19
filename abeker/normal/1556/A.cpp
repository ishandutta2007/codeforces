#include <bits/stdc++.h>
using namespace std;

int solve(int c, int d) {
  if ((c + d) % 2)
    return -1;
  if (!c && !d)
    return 0;
  if (c == d)
    return 1;
  return 2;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int C, D;
    scanf("%d%d", &C, &D);
    printf("%d\n", solve(C, D));
  }
  return 0;
}
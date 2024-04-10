#include <bits/stdc++.h>
using namespace std;

int solve() {
  int X, Y;
  scanf("%d%d", &X, &Y);
  if (X == Y)
    return X;
  if (X > Y)
    return X + Y;
  int R = (Y / 2) % (X / 2);
  int ans = (Y - R) / (X / 2) * (X / 2) + R;
  assert(ans % X == Y % ans);
  return ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%d\n", solve());
  return 0;
}
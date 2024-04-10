#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    int min_x = 0, max_x = 0;
    int min_y = 0, max_y = 0;
    while (N--) {
      int x, y;
      scanf("%d%d", &x, &y);
      min_x = min(min_x, x);
      max_x = max(max_x, x);
      min_y = min(min_y, y);
      max_y = max(max_y, y);
    }
    printf("%d\n", 2 * (max_x - min_x + max_y - min_y));
  }
  return 0;
}
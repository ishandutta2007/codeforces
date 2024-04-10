#include <cstdio>
#include <algorithm>

int main () {
  int x1, y1, x2, y2;

  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  if (std::abs(x1-x2) != std::abs(y1-y2) && x1!=x2 && y1!=y2) {
    puts("-1");
  } else {
    if (x1==x2) {
      printf("%d %d %d %d\n", x1+(y1-y2), y1, x1+(y1-y2), y2);
    } else if (y1 == y2) {
      printf("%d %d %d %d\n", x1, y1+(x1-x2), x2, y1+(x1-x2));
    } else {
      printf("%d %d %d %d\n", x1, y2, x2, y1);
    }
  }

  return 0;
}
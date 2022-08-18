#include <stdio.h>

int height, width, a, b, on;

int main () {
  // cin >> height >> width;
  scanf("%d %d", &height, &width);
  int i;
  for (i = 0; i < height*width; i++) {
    // cin >> a >> b;
    scanf("%d %d", &a, &b);
    on += a|b;
  }
  printf("%d\n", on);
  // cout << on << endl;
}
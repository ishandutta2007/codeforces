#include <cstdio>
using namespace std;

inline int mod(int x) {
  return (x % 2 + 2) % 2;
}

int main() {
  int N;
  scanf("%d", &N);
  puts("YES");
  while (N--) {
    int x1, y1;
    scanf("%d%d%*d%*d", &x1, &y1);
    printf("%d\n", 2 * mod(x1) + mod(y1) + 1);
  }
  return 0;
}
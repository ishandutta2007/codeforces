#include <bits/stdc++.h>
using namespace std;

int T, n, m;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1) {
      printf("0\n");
      continue;
    }
    if (n == 1 || m == 1) {
      printf("1\n");
      continue;
    }
    printf("2\n");
  }
  return 0;
}
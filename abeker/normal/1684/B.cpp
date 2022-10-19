#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d %d %d\n", ((c - a) / b + 1) * b + a, b, c);
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
      int x;
      scanf("%d", &x);
      printf("%d ", i % 2 ? abs(x) : -abs(x));
    }
    puts("");
  }
  return 0;
}
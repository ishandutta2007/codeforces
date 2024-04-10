#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N, K;
    scanf("%d%d", &N, &K);
    if (K > (N + 1) / 2) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
        printf("%c", (i == j && !(i % 2) && i < 2 * K) ? 'R' : '.');
      puts("");
    }
  }
  return 0;
}
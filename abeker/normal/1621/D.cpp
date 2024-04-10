#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    long long sum = 0;
    int mini = 1e9;
    for (int i = 0; i < 2 * N; i++)
      for (int j = 0; j < 2 * N; j++) {
        int cost;
        scanf("%d", &cost);
        if (i >= N && j >= N)
          sum += cost;
        bool ok = false;
        for (int k = 0; k < 2; k++) {
          ok |= (i == 0 || i == N - 1) && (j == N || j == 2 * N - 1);
          swap(i, j);
        }
        if (ok)
          mini = min(mini, cost);
      }
    printf("%lld\n", sum + mini);
  }
  return 0;
}
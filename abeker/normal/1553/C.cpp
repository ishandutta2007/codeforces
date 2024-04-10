#include <bits/stdc++.h>
using namespace std;

const int N = 10;

char pred[N + 1];

void load() {
  scanf("%s", pred);
}

int calc(int mask) {
  int goals[2] = {0};
  for (int i = 0; i < N; i++) {
    int curr = mask >> i & 1;
    if (pred[i] != '?' && pred[i] - '0' != curr)
      return N + 1;
    goals[i % 2] += curr;
    for (int j = 0; j < 2; j++)
      if (goals[j ^ 1] > goals[j] + 5 - (i - j + 2) / 2)
        return i + 1;
  }
  return N;
}

int solve() {
  int sol = N + 1;
  for (int i = 0; i < 1 << N; i++)
    sol = min(sol, calc(i));
  return sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}
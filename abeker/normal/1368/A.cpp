#include <bits/stdc++.h>
using namespace std;

int N;
int a[2];

void load() {
  scanf("%d%d%d", a, a + 1, &N);
}

int solve() {
  sort(a, a + 2);
  int sol = 0;
  for (; a[0] <= N && a[1] <= N; sol++)
    a[sol % 2] += a[(sol + 1) % 2];
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
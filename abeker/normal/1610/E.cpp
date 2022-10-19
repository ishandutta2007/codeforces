#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

int go(int x) {
  int res = 0;
  for (int curr = x + 1; curr < N; curr = lower_bound(a, a + N + 1, 2 * a[curr] - a[x]) - a)
    res++;
  return res;
}

int solve() {
  a[N] = 2e9;
  int maks = 0, last = -1;
  for (int i = 0; i < N; i++)
    if (a[i] < a[i + 1]) {
      maks = max(maks, go(i) + i - last);
      last = i;
    }
  return N - maks;
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
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN], b[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d%d", a + i, b + i);
}

bool check(int k) {
  int idx = 0;
  for (int i = 0; i < N; i++)
    if (idx <= b[i] && k - idx - 1 <= a[i])
      idx++;
  return idx >= k;
}

int solve() {
  int lo = 1, hi = N;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  return lo;
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
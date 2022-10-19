#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, K;
int a[MAXN];
int cnt[MAXN];

void load() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
}

int check(int len) {
  int sum = 0;
  for (int i = len; i <= N; i++)
    if (2 * (cnt[i] - cnt[i - len]) >= N + K)
      return i;
  return 0;
}

void solve() {
  for (int i = 1; i <= N; i++)
    cnt[i] = 0;
  for (int i = 1; i <= N; i++)
    cnt[a[i]]++;
  for (int i = 1; i <= N; i++)
    cnt[i] += cnt[i - 1];
  int lo = 1, hi = N;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  int y = check(lo);
  int x = y - lo + 1;
  int curr = 0, last = 1, ptr = 1;
  printf("%d %d\n", x, y);
  for (int i = 1; i <= N; i++) {
    if (a[i] >= x && a[i] <= y)
      curr++;
    else
      curr--;
    if ((ptr < K && curr >= ptr) || i == N) {
      printf("%d %d\n", last, i);
      last = i + 1;
      ptr++;
    }
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}
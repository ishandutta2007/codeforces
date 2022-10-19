#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N;
int a[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

ll solve() {
  int cnt_ones = 0, cnt_odd = 0;
  for (int i = 1; i < N - 1; i++) {
    cnt_ones += a[i] == 1;
    cnt_odd += a[i] % 2;
  }
  if (cnt_ones == N - 2 || (N == 3 && cnt_odd == 1))
    return -1;
  return (accumulate(a + 1, a + N - 1, 0ll) + cnt_odd) / 2;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%lld\n", solve());
  }
  return 0;
}
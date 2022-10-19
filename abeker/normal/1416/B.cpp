#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

int N;
int a[MAXN], b[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", a + i);
    b[i] = a[i];
  }
}

void apply(int i, int j, int x) {
  printf("%d %d %d\n", i, j, x);
  assert(b[i] >= x * i);
  b[i] -= x * i;
  b[j] += x * i;
}

void solve() {
  int sum = accumulate(a + 1, a + N + 1, 0);
  if (sum % N) {
    puts("-1");
    return;
  }
  printf("%d\n", 3 * (N - 1));
  for (int i = 2; i <= N; i++) {
    int ceiling = (a[i] - 1) / i + 1;
    apply(1, i, ceiling * i - a[i]);
    apply(i, 1, ceiling);
  }
  for (int i = 2; i <= N; i++)
    apply(1, i, sum / N);
  for (int i = 2; i <= N; i++)
    assert(b[i] == b[1]);
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
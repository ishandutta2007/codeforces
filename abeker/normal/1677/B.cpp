#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N, M;
char s[MAXN];
int pref[MAXN];
int by_row[MAXN], by_col[MAXN];

void load() {
  scanf("%d%d%s", &N, &M, s + 1);
}

void solve() {
  for (int i = 1; i <= N * M; i++) {
    int tmp = s[i] - '0';
    int prev = max(i - M, 0);
    pref[i] = pref[i - 1] + tmp;
    by_row[i] = by_row[prev] + (pref[prev] < pref[i]);
    by_col[i] = by_col[prev] | tmp;
  }
  for (int i = 1; i <= N * M; i++) {
    by_col[i] += by_col[i - 1];
    printf("%d ", by_row[i] + by_col[i] - by_col[max(i - M, 0)]);
  }
  puts("");
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
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int ALPHA = 20;

int N;
char a[MAXN], b[MAXN];

void load() {
  scanf("%d%s%s", &N, a, b);
}

int solve() {
  vector <int> curr(ALPHA);
  vector <vector <int>> v(ALPHA);
  for (int i = 0; i < ALPHA; i++)
    curr[i] = i;
  for (int i = 0; i < N; i++) {
    int tmp_a = a[i] - 'a';
    int tmp_b = b[i] - 'a';
    if (tmp_a > tmp_b)
      return -1;
    if (tmp_a < tmp_b)
      v[tmp_b].push_back(tmp_a);
  }
  int sol = 0;
  for (int i = 0; i < ALPHA; i++) {
    int mask = 0;
    for (auto it : v[i])
      mask |= 1 << curr[it];
    sol += __builtin_popcount(mask);
    for (int j = 0; j < ALPHA; j++)
      if (mask >> curr[j] & 1)
        curr[j] = i;
  }
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
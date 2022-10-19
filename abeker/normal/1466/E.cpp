#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int LOG = 60;
const int MOD = 1e9 + 7;

inline int mul(int x, int y) {
  return (ll)x * y % MOD;
}

inline void add(int &x, int y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
  else if (x < 0)
    x += MOD;
}

int solve() {
  int N;
  scanf("%d", &N);
  vector <ll> x(N);
  for (auto &it : x)
    scanf("%lld", &it);
  vector <int> cnt(LOG);
  for (auto it : x)
    for (int i = 0; i < LOG; i++)
      cnt[i] += it >> i & 1ll;
  int sol = 0;
  for (auto it : x) {
    int sum_and = 0, sum_or = 0;
    for (int i = 0; i < LOG; i++) {
      ll tmp = (1ll << i) % MOD;
      add(sum_or, mul(N, tmp));
      if (it >> i & 1)
        add(sum_and, mul(cnt[i], tmp));
      else
        add(sum_or, -mul(N - cnt[i], tmp));
    }
    add(sol, mul(sum_and, sum_or));
  }
  return sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%d\n", solve());
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;

int N;
ll sum;
map <ll, int> cnt;

void load() {
  scanf("%d", &N);
  cnt.clear();
  sum = 0;
  for (int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    sum += x;
    if (i < N - 1)
      cnt[sum]++;
  }
}

inline int mul(int x, int y) {
  return (ll)x * y % MOD;
}

int pot(int x, int y) {
  int res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      res = mul(res, x);
    x = mul(x, x);
  }
  return res;
}

int solve() {
  vector <int> fact(N + 2);
  fact[0] = 1;
  for (int i = 1; i <= N + 1; i++)
    fact[i] = mul(fact[i - 1], i);
  vector <int> inv(N + 2);
  inv[N + 1] = pot(fact[N + 1], MOD - 2);
  for (int i = N; i >= 0; i--)
    inv[i] = mul(inv[i + 1], i + 1);
  ll half = sum / 2;
  int sol = sum % 2 ? 1 : pot(2, cnt[half]);
  auto ways = [&](int a, int b) {
    return mul(fact[a + b], mul(inv[a], inv[b]));
  };
  for (auto it : cnt)
    if (2 * it.first < sum)
      sol = mul(sol, ways(it.second, cnt[sum - it.first]));
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
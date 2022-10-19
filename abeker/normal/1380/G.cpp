#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int MAXN = 3e5 + 5;
const int MOD = 998244353;
 
int N;
ll cost[MAXN];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%lld", cost + i);
  sort(cost, cost + N, greater <ll> ());
  for (int i = 1; i < N; i++)
    cost[i] += cost[i - 1];
  auto mul = [](int x, int y) -> int {
    return (ll)x * y % MOD;
  };
  auto pot = [mul](int x, int y) -> int {
    int res = 1;
    for (; y; y /= 2) {
      if (y % 2)
        res = mul(res, x);
      x = mul(x, x);
    }
    return res;
  };
  int inverse = pot(N, MOD - 2);
  for (int k = 1; k <= N; k++) {
    auto get = [cost](int lo, int hi) -> ll {
      return cost[hi] - cost[lo - 1];
    };
    ll sum = N / k * get(N - N % k, N - 1);
    for (int i = k; i <= N - k; i += k)
      sum += i / k * get(i, i + k - 1);
    printf("%d ", mul(sum % MOD, inverse));
  }
  puts("");
  return 0;
}
#include <cstdio>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

ll phi(ll x) {
  ll res = x;
  for (ll i = 2; i * i <= x; i++)
    if (!(x % i)) {
      res = res / i * (i - 1);
      while (!(x % i))
        x /= i;
    }
  if (x > 1) 
    res = res / x * (x - 1);
  return res;
}

int main() {
  ll N, K;
  scanf("%lld%lld", &N, &K);
  for (K = (K + 1) / 2; K && N > 1; K--)
    N = phi(N);
  printf("%lld\n", N % MOD);
  return 0;
}
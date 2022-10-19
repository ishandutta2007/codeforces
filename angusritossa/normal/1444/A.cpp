/*
 * If q is not a factor of p, output p
 * Otherwise, find all the prime factors of q
 * Consider each prime factor separately:
 *  Consider some factor m. Try x = p/m, x = p/m^2, x = p/m^3, etc, until one of these is not divisible by q
 *  Take the maximum valid x across all prime factors
 */

#include <vector>
#include <cstdio>
#include <algorithm>
#include <cassert>
typedef long long ll;
using namespace std;

vector<int> primefactorize(int x) {
  vector<int> factors;
  for (int f = 2; f*f <= x; f++) {
    while (x % f == 0) {
      factors.push_back(f);
      x /= f;
    }
  }
  if (x != 1) factors.push_back(x);
  return factors;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        ll p, q;
        scanf("%lld%lld", &p, &q);
        if (p%q != 0) {
            printf("%lld\n", p);
        } else {
            auto factors = primefactorize(q);
            ll ans = 1;
            for (int m : factors) {
                ll x = p/m;
                while (x % q == 0) {
                    x /= m;
                }
                assert(p%x == 0);
                assert(x%q != 0);
                ans = max(ans, x);
            }
            printf("%lld\n", ans);
        }
    }
}
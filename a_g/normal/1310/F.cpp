#include <bits/stdc++.h>
using namespace std;

using nimber = unsigned long long;

const nimber primitive = ULLONG_MAX;
const int K = 7;

int primes[K] = {3, 5, 17, 257, 65537, 641, 6700417};
unsigned long long z[K], crt_factor[K];
nimber primitive_by_prime[K];
map<nimber, int> logmaps[K];

int inversemod(int p, int q) {
  return (p > 1 ? q-1LL*inversemod(q%p, p)*q/p : 1);
}

// from ecnerwala library
struct nim_prod_t {
	uint64_t bit_prod[64][64]{};
	constexpr nim_prod_t() {
		for (int i = 0; i < 64; i++) {
			for (int j = 0; j < 64; j++) {
				if ((i & j) == 0) {
					bit_prod[i][j] = uint64_t(1) << (i|j);
				} else {
					int a = (i&j) & -(i&j);
					bit_prod[i][j] = bit_prod[i ^ a][j] ^ bit_prod[(i ^ a) | (a-1)][(j ^ a) | (i & (a-1))];
				}
			}
		}
	}
	constexpr uint64_t operator () (uint64_t x, uint64_t y) const {
		uint64_t res = 0;
		for (int i = 0; i < 64 && (x >> i); i++)
			if ((x >> i) & 1)
				for (int j = 0; j < 64 && (y >> j); j++)
					if ((y >> j) & 1)
						res ^= bit_prod[i][j];
		return res;
	}
};

constexpr nim_prod_t nimProd;

nimber multiply(nimber a, nimber b) {
  return nimProd(a, b);
}


nimber exp(nimber base, unsigned long long pow) {
  nimber res = 1;
  while (pow) {
    if (pow & 1) res = multiply(res, base);
    pow >>= 1;
    base = multiply(base, base);
  }
  return res;
}

int discrete_log(int i, nimber x) {
  // given that x = primitive^(z[i]*n), find n
  int ans = 0;
  while (!logmaps[i].count(x)) {
    x = multiply(x, primitive_by_prime[i]);
    ans--;
  }
  ans += logmaps[i][x];
  if (ans < 0) ans += primes[i];
  if (ans >= primes[i]) ans -= primes[i];
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < K; i++) {
    z[i] = 1;
    for (int j = 0; j < K; j++) {
      if (j == i) continue;
      z[i] *= primes[j];
    }
    crt_factor[i] = z[i] * inversemod(z[i]%primes[i], primes[i]);
  }

  // logarithm_maps[p] is a mapping from elements of order p to their logarithm
  for (int i = 0; i < K; i++) {
    primitive_by_prime[i] = exp(primitive, z[i]);
    int step = (primes[i] < 500 ? 1 : 100);
    nimber base = exp(primitive_by_prime[i], step);
    int exponent = step;
    nimber val = base;
    while (exponent < primes[i]) {
      logmaps[i][val] = exponent;
      exponent += step;
      val = multiply(val, base);
    }
  }

  int T;
  cin >> T;
  while (T--) {
    nimber a, b;
    cin >> a >> b;
    bool ok = 1;
    __int128 ans = 0;
    unsigned long long order_a = 1;
    for (int i = 0; i < K; i++) {
      int res_a = discrete_log(i, exp(a, z[i]));
      int res_b = discrete_log(i, exp(b, z[i]));
      if (res_a == 0 && res_b != 0) {
        ok = 0;
        break;
      }
      if (!res_a) continue;
      order_a *= primes[i];
      ans += (__int128)(inversemod(res_a, primes[i]))*crt_factor[i]*res_b;
    }
    if (!ok) {
      cout << "-1\n";
      continue;
    }
    unsigned long long output = ans%order_a;
    cout << output << '\n';
  }
}
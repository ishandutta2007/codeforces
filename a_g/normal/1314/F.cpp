#include <bits/stdc++.h>
using namespace std;

using nimber = unsigned long long;

const nimber primitive = ULLONG_MAX;
const int K = 7;

int primes[K] = {3, 5, 17, 257, 65537, 641, 6700417};
unsigned long long z[K], crt_factor[K];
nimber primitive_by_prime[K];
map<nimber, int> logmaps[K];

nimber power_2_prods[64][64];
nimber smallprods[256][256];

int inversemod(int p, int q) {
  return (p > 1 ? q-1LL*inversemod(q%p, p)*q/p : 1);
}

int doublelog(unsigned long long a) {
  // return smallest n with 2^{2^n} > a
  int n = 0;
  while (1LLu << (1 << n) <= a) {
    n++;
    if (n > 5) return n;
  }
  return n;
}

nimber naive_mult(nimber a, nimber b) {
  // very important: precomputation of the table in main()
  nimber ans = 0;
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 64; j++) {
      if ((a>>i)&1 && (b>>j)&1) {
        ans ^= power_2_prods[i][j];
      }
    }
  }
  return ans;
}

nimber multiply2(nimber a, nimber b) {
  if (a == 1 || b == 1) return a*b;
  int n = doublelog(max(a, b)+1)-1;
  unsigned long long power = 1LLu << (1 << n);
  if (a >= power && b >= power) {
    nimber c = multiply2(a/power, b/power);
    return naive_mult(power, c)^naive_mult(power/2, c);
  }
  else if (a >= power) {
    return multiply2(a/power, b)*power;
  }
  else {
    return multiply2(a, b/power)*power;
  }
}

nimber multiply(nimber a, nimber b) {
  // Karatsuba
  if (a == 0 || b == 0) return 0;
  if (a == 1 || b == 1) return a*b;
  int n = doublelog(max(a, b));
  if (n <= 3) return smallprods[a][b];
  int split = 1<<(n-1);
  long long P = 1LL << split;
  nimber a1 = a>>split;
  nimber b1 = b>>split;
  nimber a2 = a % P;
  nimber b2 = b % P;
  nimber prod1 = multiply(a1^a2, b1^b2);
  nimber prod2 = multiply(a1, b1);
  nimber prod3 = multiply(a2, b2);
  return (prod2<<split)^multiply(prod2, P/2)^prod3^((prod1^prod2^prod3)<<split);
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

  for (int i = 0; i < 64; i++) {
    for (int j = i; j < 64; j++) {
      nimber prod = multiply2(1LLu<<i, 1LLu<<j);
      power_2_prods[i][j] = prod;
      power_2_prods[j][i] = prod;
    }
  }

  for (int i = 0; i < 256; i++) {
    for (int j = i; j < 256; j++) {
      smallprods[i][j] = naive_mult(i, j);
      smallprods[j][i] = smallprods[i][j];
    }
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
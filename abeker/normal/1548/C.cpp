#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int main() {
  int N, Q;
  scanf("%d%d", &N, &Q);
  vector <int> inv(3 * (N + 1) + 1);
  vector <int> fact(3 * (N + 1) + 1), inv_fact(3 * (N + 1) + 1);
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i <= 3 * (N + 1); i++) {
    inv[i] = i > 1 ? mul(MOD - MOD / i, inv[MOD % i]) : 1;
    fact[i] = mul(fact[i - 1], i);
    inv_fact[i] = mul(inv_fact[i - 1], inv[i]);
  }
  vector <int> large(3 * (N + 1) + 1);
  for (int i = 0; i <= 3 * (N + 1); i++)
    large[i] = mul(fact[3 * (N + 1)], mul(inv_fact[i], inv_fact[3 * (N + 1) - i]));
  vector <int> small = {1, 3, 3, 1};
  for (int i = 0; i < 4; i++)
    large[i] = add(large[i], -small[i]);
  large.erase(large.begin());
  small.erase(small.begin());
  vector <int> poly;
  for (int i = 3 * N + 2; i >= 2; i--) {
    poly.push_back(large[i]);
    for (int j = 0; j < 3; j++)
      large[i - 2 + j] = add(large[i - 2 + j], -mul(small[j], poly.back()));
  }
  reverse(poly.begin(), poly.end());
  while (Q--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", poly[x]);
  }
  return 0;
}
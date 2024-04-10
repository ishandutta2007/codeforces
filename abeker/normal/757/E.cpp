#include <cstdio>
using namespace std;

const int MAXN = 2000005;
const int MOD = 1000000007;

int Q;
int p[MAXN];
int fact[MAXN], inv[MAXN];

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
  else if (x < 0)
    x += MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
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

int choose(int n, int k) {
  if (k < 0 || n < k)
    return 0;
  return mul(fact[n], mul(inv[k], inv[n - k]));
}

void init() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv[i] = pot(fact[i], MOD - 2);
  } 
  
  for (int i = 2; i < MAXN; i++) {
    if (p[i])
      continue;
    for (int j = i; j < MAXN; j += i)
      if (!p[j])
        p[j] = i;
  }
}

int f(int r, int n) {
  int res = 1;
  while (n > 1) {
    int tmp = p[n];
    int exp = 0;
    for (; !(n % tmp); n /= tmp)
      exp++;
    int sum = 0;
    for (int i = 0; i <= exp; i++)
      sum = add(sum, mul(choose(i + r - 1, i), i < exp ? 2 : 1));
    if (r)
      res = mul(res, sum);
    else 
      res = mul(res, 2);
  }
  return res;      
}

void solve() {
  scanf("%d", &Q);
  while (Q--) {
    int r, n;
    scanf("%d%d", &r, &n);
    printf("%d\n", f(r, n));
  }
}

int main() {
  init();
  solve();
  return 0;
}
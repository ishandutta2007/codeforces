#include <bits/stdc++.h>

using namespace std;

using lint = long long;

const int MOD = int(1e9) + 7;

const int MAXC = 63;

struct modint {
  int v;
  modint(long long v_ = 0): v(v_ % MOD) { }
  modint operator+ (modint other) {
    return modint(v + other.v);
  }
  modint operator- (modint other) {
    return modint(v - other.v + MOD);
  }
  modint operator* (modint other) {
    return modint((lint)v * other.v % MOD);
  }
  modint operator+= (modint other) {
    (v += other.v) %= MOD;
    return *this;
  }
  modint operator*= (modint other) {
    v = ((lint)v * other.v) % MOD;
    return *this;
  }
  modint operator-= (modint other) {
    (v += MOD - other.v) %= MOD;
    return *this;
  }
};

modint inv[MAXC + 10];

using pli = pair<lint, int>;

const int K_ = int(1.1e4);


lint N; int K;

vector<lint> divisors;

modint ways[MAXC + 10][MAXC + 10];

int main() {
  inv[1] = 1;
  for(int i = 2; i <= MAXC + 9; i++) {
    inv[i] = modint(MOD - MOD / i) * inv[MOD % i];
  }

#ifdef IN_MY_COMPUTER
  freopen("d.in", "r", stdin);
#endif

  scanf("%lld%d", &N, &K);

  for(int i = 1; i <= MAXC; i++) {
    ways[i][i] = 1;
    for(int k = 1; k <= K; k++) {
      for(int j = i; j >= 0; j--) {
        ways[i][j] = ways[i][j+1] + ways[i][j] * inv[j+1];
      }
    }
  }


  auto go = [&](lint p, int c) {
    modint ret = 0;
    modint a(1);
    for(int i = 0; i <= c; i++) {
      ret += a * ways[c][i];
      a *= p;
    }
    return ret;
  };

  modint ans = 1;

  vector<pli> factorized;
  {
    lint n = N;
    for(lint i = 2; i * i <= N && n > 1; i++) {
      int c = 0;
      while(n % i == 0) {
        n /= i;
        c += 1;
      }
      if(c > 0) {
        ans *= go(i, c);
      }
    }
    if(n > 1) {
      ans *= go(n, 1);
    }
  }
  
  printf("%d\n", ans.v);
  return 0;
}
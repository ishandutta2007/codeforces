#include <iostream>

#define int long long

const int MAXN = 1000006;
const int MOD = 1000000007;
const int HALF = 500000004;
const int EF = -1000000;
const int OF = -999999;

int fact[MAXN];
signed bit[2][MAXN];

void add(int b, int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[b][x] += v;
    x += x&(-x);
  }
}

int sum(int b, int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret += bit[b][x];
    x -= x&(-x);
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  fact[0] = 1;
  bit[0][0] = bit[0][1] = 0;
  for(int i = 1; i < MAXN; i++) {
    fact[i] = (fact[i-1]*i)%MOD;
    bit[0][i] = bit[1][i] = 0;
  }

  int m;
  std::cin >> m;

  for(int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    int l = 1-x;
    int r = x-1;
    int b = r%2;

    int li, ri;
    if(b) {
      li = (l-OF)/2;
      ri = (r-OF)/2;
    }
    else {
      li = (l-EF)/2;
      ri = (r-EF)/2;
    }

    add(b, li, 1);
    add(b, ri+1, -1);
  }

  int cb[2];
  cb[0] = (MOD + EF)%MOD;
  cb[1] = (MOD+OF)%MOD;

  int pb[2];
  pb[0] = pb[1] = 0;

  int ans2 = 1;
  int ans1 = 0;
  int id = 0;
  for(int i = 0; i < 2*MAXN; i++) {
    int b = i%2;
    int cur = sum(b, pb[b]);
    ans2 = (ans2*fact[cur])%MOD;

    int coeff = ((id + (id+cur-1))*(cur))%MOD;
    coeff *= HALF;
    coeff %= MOD;
    coeff *= cb[b];
    coeff %= MOD;
    ans1 = (ans1 + coeff)%MOD;
    id = (id + cur)%MOD;

    cb[b] = (cb[b] + 2)%MOD;
    pb[b]++;
  }

  std::cout << ans1 << " " << ans2 << std::endl;

  return 0;
}
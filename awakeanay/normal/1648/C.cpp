#include <iostream>

#define int long long

const int MOD = 998244353;

const int MAXN = 200005;

int bit[MAXN];

void add(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&(-x);
  }
}

int sum(int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= x&(-x);
  }
  return ret;
}

int expo(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p&1)
      ret = (ret*x)%MOD;

    p >>= 1;
    x = (x*x)%MOD;
  }
  return ret;
}

int inv(int x) {
  return expo(x, MOD-2);
}

int fact[MAXN];
int val[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  fact[0] = 1;
  for(int i = 1; i < MAXN; i++)
    fact[i] = (i*fact[i-1])%MOD;

  int n, m;
  std::cin >> m >> n;

  int ans = 0;
  for(int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    val[x]++;
    add(x, 1);
  }

  int t[n];
  for(int i = 0; i < n; i++)
    std::cin >> t[i];

  int k = std::min(n, m);
  int tot = fact[m];
  for(int i = 0; i < MAXN; i++)
    tot = (tot*inv(fact[val[i]]))%MOD;


  int okay = true;
  for(int i = 0; i < k; i++) {
    int cur = sum(t[i]-1)*inv(m-i);
    cur %= MOD;
    cur *= tot;
    cur %= MOD;
    ans += cur;
    ans %= MOD;

    if(val[t[i]] == 0) {
      okay = false;
      break;
    }

    tot *= val[t[i]];
    val[t[i]]--;
    tot %= MOD;
    tot *= inv(m-i);
    tot %= MOD;
    add(t[i], -1);
  }

  if(okay && m < n) {
    ans = (ans+1)%MOD;
  }

  std::cout << ans << std::endl;

  return 0;
}
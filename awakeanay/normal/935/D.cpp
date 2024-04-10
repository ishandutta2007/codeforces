#include <iostream>

#define int long long

const int MOD = 1000000007;

int expo(int x, int p) {
  int ret = 1;
  while(p > 0) {
    if(p&1)
      ret = (ret*x)%MOD;
    x = (x*x)%MOD;
    p >>= 1;
  }
  return ret;
}

int inv(int x) {
  return expo(x, MOD-2);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  int a[n], b[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];
  for(int i = 0; i < n; i++)
    std::cin >> b[i];

  int ans = 0;
  int cur = 1;

  for(int i = 0; i < n; i++) {
    if(a[i] == 0 && b[i] == 0) {
      int add = (cur*(m-1))%MOD;
      add *= inv(2);
      add %= MOD;
      add *= inv(m);
      add %= MOD;
      ans = (ans + add)%MOD;
      cur *= inv(m);
      cur %= MOD;
    }
    else if(a[i] == 0) {
      int add = (cur*(m-b[i]))%MOD;
      add *= inv(m);
      add %= MOD;
      ans = (ans + add)%MOD;
      cur *= inv(m);
      cur %= MOD;
    }
    else if(b[i] == 0) {
      int add = (cur*(a[i]-1))%MOD;
      add *= inv(m);
      add %= MOD;
      ans = (ans + add)%MOD;
      cur *= inv(m);
      cur %= MOD;
    }
    else {
      if(a[i] > b[i]) {
        ans = (ans + cur)%MOD;
        cur = 0;
      }
      else if(a[i] < b[i]) {
        cur = 0;
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
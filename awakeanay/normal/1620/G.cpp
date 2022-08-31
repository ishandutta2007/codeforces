#include <iostream>

#define int long long

const int MOD = 998244353;

struct str
{
  signed ct[26];
};

const int MAXM = 8388609;

str add(const str& a, const str& b) {
  str ret;
  for(int i = 0; i < 26; i++)
    ret.ct[i] = std::min(a.ct[i], b.ct[i]);
  return ret;
}

int eval(const str& a) {
  int ret = 1;
  for(int i = 0; i < 26; i++)
    ret = (ret*(a.ct[i]+1))%MOD;
  return ret;
}

const int MAXN = 24;

int f[MAXM];
str calc[MAXM];
str arr[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;

    for(char j : s)
      arr[i].ct[j-'a']++;

  }


  int m = (1 << n);
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < 26; j++)
      calc[i].ct[j] = 40000;
    for(int j = 0; j < n; j++)
      if((i >> j)&1)
        calc[i] = add(calc[i], arr[j]);
  }

  for(int i = 1; i < m; i++)
    f[i] = eval(calc[i]);

  f[0] = 0;
  for(int j = 0; j < m; j++) {
    if(!__builtin_parity(j))
      f[j] = (MOD - f[j])%MOD;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(j&(1 << i))
        f[j] = (f[j] + f[j^(1 << i)])%MOD;
    }
  }

  int ans = 0;
  for(int j = 1; j < m; j++) {
    int cur = 0;
    for(int i = 0; i < n; i++)
      if((j >> i)&1)
        cur += i+1;
    cur *= __builtin_popcount(j);
    cur *= f[j];
    ans ^= cur;
  }

  std::cout << ans << std::endl;

  return 0;
}
#include <iostream>
#include <vector>

#define int long long

const int MAXN = 100005;
const int MOD = 998244353;

int mob[MAXN];
int lp[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  mob[1] = 1;

  for(int i = 2; i < MAXN; i++) {
    if(lp[i] == 0) {
      for(int j = i; j < MAXN; j+=i)
        lp[j] = i;
      mob[i] = -1;
    }
    else {
      int next = i/lp[i];
      if(lp[i] == lp[next])
        mob[i] = 0;
      else
        mob[i] = -mob[next];
    }
  }

  int n, m;
  std::cin >> n >> m;

  int l[n], r[n];
  for(int i = 0; i < n; i++)
    std::cin >> l[i] >> r[i];

  int ans = 0;

  for(int i = 1; i <= m; i++) {
    if(mob[i] == 0)
      continue;

    int cmax = m/i;
    std::vector<int> plast(cmax+1, 1);

    bool imposs = 0;
    for(int j = 0; j < n; j++) {
      std::vector<int> cur(cmax+1, 0);
      int lx = l[j]/i + (l[j]%i != 0);
      int rx = r[j]/i;

      if(rx < lx || rx > cmax) {
        imposs = 1;
        break;
      }

      for(int k = 0; k <= cmax; k++) {
        cur[k] = 0;
        if(k-lx >= 0)
          cur[k] = plast[k-lx];
        if(k-rx-1 >= 0)
          cur[k] = (cur[k] + MOD - plast[k-rx-1])%MOD;
        if(k)
          cur[k] = (cur[k-1] + cur[k])%MOD;
      }

      plast = cur;
    }

    if(imposs)
      continue;

    ans = (ans + mob[i]*plast[cmax] + MOD)%MOD;
  }

  std::cout << ans << std::endl;

  return 0;
}
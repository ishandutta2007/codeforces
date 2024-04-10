#include <iostream>

#define int long long

const int MX = 100;

int ct[10];
int binom[MX][MX];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  for(int i = 0; i < MX; i++)
    binom[i][i] = binom[i][0] = 1;
  for(int j = 1; j < MX; j++)
    for(int k = 1; k < j; k++)
      binom[j][k] = (binom[j-1][k-1] + binom[j-1][k]);

  int n;
  std::cin >> n;

  int cpn = n;
  while(cpn > 0) {
    ct[cpn%10]++;
    cpn /= 10;
  }

  int num = 1;
  for(int j = 0; j < 10; j++)
    num *= ct[j]+1;

  //std::cout << num << std::endl;

  int ans = 0;
  int ans1 = 0, ans2 = 0;
  for(int u = 0; u < num; u++) {
    int ctn[10];
    int tot = 0;
    int v = u;
    int skip = false;
    for(int j = 0; j < 10; j++) {
      ctn[j] = v%(ct[j]+1);
      if(ctn[j] == 0 && ct[j] != 0) {
        skip = true;
        break;
      }
      tot += ctn[j];
      v /= ct[j]+1;
    }
    if(skip)
      continue;

    int ntot = tot;
    int cur = 1;
    for(int j = 0; j < 10; j++) {
      cur *= binom[tot][ctn[j]];
      tot -= ctn[j];
    }

    ans1 += cur;

    int curn = 0;
    if(ctn[0] > 0) {
      curn = 1;
      ctn[0]--;
      ntot--;
      for(int j = 0; j < 10; j++) {
        curn *= binom[ntot][ctn[j]];
        ntot -= ctn[j];
      }
    }

    ans2 -= curn;
  }

  std::cout << ans1+ans2 << std::endl;

  return 0;
}
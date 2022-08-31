#include <iostream>

#define int long long

const int MAXN = 505;
const int MAXP = 124755;

int n, MOD;

int numi[MAXN][MAXP];
int ans[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n >> MOD;

  int maxi[n+1]; // max number of inversions for permuation of i numbers
  for(int i = 1; i <= n; i++)
    maxi[i] = (i*(i-1))/2;

  for(int i = 0; i < MAXP; i++)
    numi[1][i] = 1;

  ans[1] = 0;
  ans[0] = 0;

  for(int i = 2; i <= n; i++) {
    for(int j = 0; j <= maxi[i]; j++) {
      int sub = (j-i >= 0 ? numi[i-1][j-i] : 0);
      numi[i][j] = (numi[i-1][j] - sub + MOD)%MOD;
    }

    for(int j = 1; j < MAXP; j++)
      numi[i][j] = (numi[i][j] + numi[i][j-1])%MOD;
  }

  for(int i = 2; i <= n; i++) {
    int dp0[maxi[i]+1];
    int dp1[maxi[i]+1];
    int dp2[maxi[i]+1];
    int dp3[maxi[i]+1];

    dp0[0] = dp1[0] = dp2[0] = dp3[0] = numi[i][0];
    for(int j = 1; j <= maxi[i]; j++) {
      int end = i;
      int slast = (i*(i+1))/2;
      dp0[j] = (numi[i][j]-numi[i][j-1]+MOD)%MOD;
      dp1[j] = (dp1[j-1] + dp0[j])%MOD;
      if(j-end >= 0)
        dp1[j] = (dp1[j] + MOD - dp0[j-end])%MOD;
      dp2[j] = (dp2[j-1] + dp1[j])%MOD;
      if(j - end >= 0)
        dp2[j] = (dp2[j] + MOD - (i*dp0[j-end])%MOD)%MOD;
      dp3[j] = (dp3[j-1] + dp2[j])%MOD;
      if(j - end >= 0) {
        int sub = (i*(i+1))/2;
        sub *= dp0[j-i];
        sub %= MOD;
        dp3[j] = (dp3[j] + MOD - sub)%MOD;
      }
    }

    for(int j = 2; j <= maxi[i]; j++) {
      int end = i;
      int slast = (i*(i+1))/2;

      int cur = (i+1)*dp2[j-2];
      cur %= MOD;
      cur += MOD - dp3[j-2];
      cur %= MOD;

      if(j-2-end >= 0) {
        cur += slast*numi[i][j-2-end];
        cur %= MOD;
      }

      ans[i] += dp0[j]*cur;
      ans[i] %= MOD;
    }
  }

  int finale = 0;
  int cur = 1;

  for(int i = 0; i < n; i++) {
    finale += cur*ans[n-i-1];
    finale %= MOD;
    cur = (cur*(n-i))%MOD;
  }

  std::cout << finale << std::endl;

  return 0;
}
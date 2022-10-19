#include <bits/stdc++.h>
using namespace std;

const int N = 52;
long long dp[N][2*N][2];
// (bits done, current pcsum, carry bit)

long long solve(int l, int r, long long s) {
  // a = 10... (l+1 digits)
  // b = 11... (r+1 digits)
  // 2a+2b-pc(a)-pc(b)=s+1
  long long ans = 0;
  for (int pcsum = (s+1)%2+2; pcsum <= max(l, 1)+r+1; pcsum += 2) {
    long long target = (s+pcsum+1)/2;
    dp[0][0][0] = 1;
    for (int bit = 0; bit < N-1; bit++) {
      int tx = (target>>bit)&1;
      for (int sum = 0; sum <= pcsum; sum++) {
        for (int carry = 0; carry < 2; carry++) {
          if (!dp[bit][sum][carry]) continue;
          for (int ax = 0; ax < 2; ax++) {
            if (bit == l-1 && ax != 0) continue;
            if (bit == l && ax != 1) continue;
            if (bit > l && ax != 0) continue;
            for (int bx = 0; bx < 2; bx++) {
              if ((bit == r || bit == r-1) && bx != 1) continue;
              if (bit > r && bx != 0) continue;
              if (((carry+ax+bx)&1) != tx) continue;
              if (sum+ax+bx > pcsum) continue;
              dp[bit+1][sum+ax+bx][carry+ax+bx > tx] += dp[bit][sum][carry];
            }
          }
        }
      }
    }
    ans += dp[N-1][pcsum][0];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j <= pcsum; j++) {
        for (int k = 0; k < 2; k++) {
          dp[i][j][k] = 0;
        }
      }
    }
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  long long s;
  cin >> s;
  long long ans = 0;
  for (int ld = 0; ld < N; ld++) {
    for (int rd = 0; rd < N; rd++) {
      // (2^{l+1}+2^{r+1}-3)x+2^r-1 <= s
      long long expl = 1LL<<ld;
      long long expr = 1LL<<rd;
      long long z = 2*(expl+expr)-3;
      long long x = (s-expr+1)/z;
      if (x <= 0) continue;
      ans += solve(ld, rd, s-(x-1)*z);
    }
  }
  cout << ans << '\n';
}
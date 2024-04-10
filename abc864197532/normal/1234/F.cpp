#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second
const long long INF = 1ll << 60;

int main () {
  string ss;
  cin >> ss;
  int n = ss.length(), dp[1 << 20], now[20], s = 0, k = 0;
  bool has[1 << 20];
  fop (i,0,1 << 20) has[i] = false;
  for(lli i=0;i<n;i++){
        lli msk=0;
        for(lli j=i;j>=0;j--){
            if((msk>>ss[j]-'a')%2) break;
            msk+=1<<(ss[j]-'a');
            has[msk]=true;
            //cout<<msk<<'\n';
        }
    }
  fop (s,0,1 << 20) {
    if (has[s]) {
      dp[s] = __builtin_popcount(s);
      continue;
    }
    dp[s] = 0;
    fop (i,0,20) {
      if (s & (1 << i)) {
        dp[s] = max(dp[s], dp[s ^ (1 << i)]);
      }
    }
  }
  int ans = 0;
  fop (s,0,1 << 20) if (has[s]) {
    ans = max(ans, dp[s] + dp[s ^ ((1 << 20) - 1)]);
  }
  cout << ans << endl;
}
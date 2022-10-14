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
  int n, tmp;
  cin >> n;
  lli cnt[20][20], color[20];
  fop (i,0,20) color[i] = 0;
  fop (i,0,20) fop (j,0,20) cnt[i][j] = 0;
  fop (i,0,n) {
    cin >> tmp;
    tmp--;
    fop (i,0,20) cnt[tmp][i] += color[i];
    color[tmp]++;
  }
  lli dp[1 << 20];
  dp[0] = 0;
  fop (s,1,(1 << 20)) {
    dp[s] = INF;
    fop (i,0,20) {
      if (!(s & (1 << i))) continue;
      lli tmp = dp[s ^ (1 << i)];
      fop (j,0,20) {
        if (!(s & (1 << j))) tmp += cnt[i][j];
      }
      dp[s] = min(dp[s], tmp);
    }
  }
  cout << dp[(1 << 20) - 1] << endl;
}
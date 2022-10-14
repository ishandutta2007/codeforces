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
#define pli pair<lli,int> 
#define X first
#define Y second

int main () {
  int n, m;
  cin >> n;
  int s[n];
  fop (i,0,n) cin >> s[i];
  cin >> m;
  int t[m];
  fop (i,0,m) cin >> t[i];
  vector <int> dp[n+1][m+1], ord[520];
  fop (i,0,n+1) dp[i][0] = vector <int>();
  fop (i,0,m+1) dp[0][i] = vector <int>();
  fop (i,0,n) {
    fop (j,0,m) {
      if (s[i] == t[j]) {
        dp[i+1][j+1] = dp[i][j];
        if (dp[i+1][j+1].empty() or dp[i+1][j+1].back() < s[i]) {
          dp[i+1][j+1].push_back(s[i]);
          ord[dp[i+1][j+1].size()] = dp[i+1][j+1];
        } else *lower_bound(dp[i+1][j+1].begin(), dp[i+1][j+1].end(), s[i]) = s[i];
      } else {
        if (dp[i+1][j].size() > dp[i][j+1].size()) dp[i+1][j+1] = dp[i+1][j];
        else if (dp[i+1][j].size() < dp[i][j+1].size()) dp[i+1][j+1] = dp[i][j+1];
        else {
          dp[i+1][j+1].resize(dp[i+1][j].size());
          fop (k,0,dp[i+1][j].size()) {
            dp[i+1][j+1][k] = min(dp[i+1][j][k], dp[i][j+1][k]);
          }
        }
      }
    }
  }
  cout << dp[n][m].size() << endl;
  for (int i : ord[dp[n][m].size()]) cout << i << ' ';
  cout << endl;
}
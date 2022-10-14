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
int MOD = 1e9 + 7;

int main () {
    int n,m;
    cin >> n >> m;
    lli dp[n+1][m+1]; // m+11-(n+1)
    fop (i,0,m+1) dp[0][i] = 0;
    fop (j,1,m+1) {
        fop (i,1,n+1) {
            if (j == 1) dp[i][j] = i;
            else {
                dp[i][j] = 0;
                fop (k,1,i+1) {
                    dp[i][j] += dp[k][j-1];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    lli ans = 0;
    fop (i,1,n+1) {
        ans += (dp[i][m] - dp[i-1][m]) * dp[n+1-i][m];
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}
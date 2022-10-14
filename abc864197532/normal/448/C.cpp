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
int dp[5050][5050];

int main () {
    int n;
    cin >> n;
    vector <int> h(n + 1);
    fop (i,0,n) cin >> h[i];
    h[n] = n;
    fop (i,0,5050) {
        fop (j,0,5050) {
            dp[i][j] = n;
        }
    }
    dp[0][0] = 0;
    fop (i,0,n) {
        fop (j,0,min(n, h[i])+1) {
            if (j + 1 <= n and j + 1 <= h[i]) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            int t = min(j, h[i + 1]);
            dp[i+1][t] = min(dp[i+1][t], dp[i][j] + (j != h[i]));
        }
    }
    int ans = 1 << 20;
    fop (i,0,min(h[n - 1], n)+1) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
}
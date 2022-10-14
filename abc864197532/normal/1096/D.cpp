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

int main () {
    int n;
    string s;
    cin >> n >> s;
    int a[n];
    fop (i,0,n) cin >> a[i];
    string t = "hard";
    lli dp[4][n+1];
    dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = 0;
    fop (i,1,n+1) {
        fop (j,0,4) {
            if (s[i-1] != t[j]) {
                dp[j][i] = dp[j][i-1];
            } else if (j == 0) {
                dp[j][i] = dp[j][i-1] + a[i-1];
            } else {
                dp[j][i] = min(dp[j-1][i], dp[j][i-1] + a[i-1]);
            }
        }
    }
    cout << min({dp[0][n], dp[1][n], dp[2][n], dp[3][n]}) << endl;
}
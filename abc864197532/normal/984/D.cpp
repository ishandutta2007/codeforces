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
#define endl '\n'
const int mod = 998244353;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int dp[n+1][n+1];
    fop (i,0,n) cin >> dp[i][i+1];
    fop (i,2,n+1) {
        fop (j,0,n-i+1) {
            dp[j][i+j] = dp[j+1][i+j] ^ dp[j][i+j-1];
        }
    }
    fop (i,2,n+1) {
        fop (j,0,n-i+1) {
            dp[j][i+j] = max({dp[j][i+j], dp[j+1][i+j], dp[j][i+j-1]});
        }
    }
    int q, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << dp[l-1][r] << endl;
    }
}
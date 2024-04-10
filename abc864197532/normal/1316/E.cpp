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
    int n, p, l;
    cin >> n >> p >> l;
    vector <vector <int>> input(n);
    fop (i,0,n) {
        input[i].resize(p + 1);
        cin >> input[i][0];
    }
    fop (i,0,n) fop (j,0,p) cin >> input[i][j+1];
    sort(input.begin(), input.end(), [](vector <int> a, vector <int> b) {
        return a[0] > b[0];
    });
    lli dp[n][1 << p];
    fop (i,0,n) {
        fop (j,0,1<<p) {
            if (__builtin_popcount(j) > i + 1) {
                dp[i][j] = -1ll << 60;
                continue;
            }
            if (j) {
                if (i) {
                    dp[i][j] = dp[i - 1][j] + (l - i + __builtin_popcount(j) <= 0 ? 0 : input[i][0]);
                    fop (k,0,p) {
                        if (j & (1 << k)) {
                            dp[i][j] = max(dp[i][j], dp[i - 1][j ^ (1 << k)] + input[i][k + 1]);
                        }
                    }
                } else {
                    fop (k,0,p) {
                        if (j & (1 << k)) dp[i][j] = input[i][k + 1];
                    }
                }
            } else {
                if (i) dp[i][j] = dp[i - 1][j] + (l - i + __builtin_popcount(j) <= 0 ? 0 : input[i][0]);
                else dp[i][j] = input[i][0];
            }
        }
    }
    lli ans = 0;
    fop (i,0,1<<p) ans = max(ans, dp[n - 1][i]);
    cout << ans << endl;
}
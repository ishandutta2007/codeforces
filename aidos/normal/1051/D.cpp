#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, m;
int dp[4][2020];
int d[4][2020];
void upd(int &v, int u) {
    v += u;
    if(v >= mod) v -= mod;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < 4; i++) {
        if((i&1) == ((i>>1)&1)) {
            dp[i][1] = 1;
        }else {
            dp[i][2] = 1;
        }
    }
    for(int i = 2; i <= n; i++) {
        for(int mask = 0; mask < 4; mask++) {
            for(int j = 0; j <= 2 * i; j++) {
                d[mask][j] = dp[mask][j];
                dp[mask][j] = 0;
            }
        }
        for(int mask = 0; mask < 4; mask++) {
            for(int nmask = 0; nmask < 4; nmask++) {
                int add = 0;
                if(nmask == 3) {
                    if(mask == 0) add = 1;
                } else if(nmask == 0) {
                    if(mask == 3) add = 1;
                }
                else if(mask == 0 || mask == 3) {
                    add = 1;
                } else if(mask == nmask) {
                    add = 0;
                }else add = 2;
                for(int k = 0; k <= 2*i; k++) {
                    upd(dp[nmask][k + add],d[mask][k]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 4; i++) {
        upd(ans, dp[i][m]);
    }

    cout << ans << "\n";

}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
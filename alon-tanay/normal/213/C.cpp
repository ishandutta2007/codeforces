#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT = 
#define enl "\n";
#define debug(k) for(int _ = 0; _ < DEBUG_INDENT; _ ++) { cout << "  "; } cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vvi mp(n,vi(n));
    for(int ri = 0; ri < n; ri ++) {
        for(int ci = 0; ci < n; ci ++) {
            cin >> mp[ri][ci];
        }
    }
    vvi dp(n+1,vi(n+1,-1e9));
    dp[0][0] = mp[0][0];
    for(int i = 1; i < n; i ++) {
        vvi new_dp(n+1,vi(n+1,-1e9));
        for(int j = 0; j <= i; j ++) {
            for(int k = j; k <= i; k ++) {
                int dif = mp[i-j][j] + mp[i-k][k];
                if(k == j) {
                    dif /= 2;
                }
                if(j == 0) {
                    if(k == 0) {
                        new_dp[j][k] = dp[j][k] + dif;
                    } else {
                        new_dp[j][k] = max(dp[j][k],dp[j][k-1]) + dif;
                    }
                } else {
                    new_dp[j][k] = max(max(dp[j-1][k-1],dp[j][k]),max(dp[j-1][k],dp[j][k-1])) + dif;
                }
            }
        }
        dp = new_dp;
        // cout << "~~~~\n";
        // for(int i = 0; i < 2; i ++) {
        //     for(int j = 0; j < 2; j ++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    
    for(int i = n - 2; i >= 0; i --) {
        vvi new_dp(n+1,vi(n+1,-1e9));
        for(int j = 0; j <= i; j ++) {
            for(int k = j; k <= i; k ++) {
                int dif = mp[n-1-j][n-1-i+j] + mp[n-1-k][n-1-i+k];
                if(k == j) {
                    dif /= 2;
                }
                new_dp[j][k] = max(max(dp[j+1][k+1],dp[j][k]),max(dp[j+1][k],dp[j][k+1])) + dif;
            }
        }
        dp = new_dp;
        // cout << "~~~\n";
        // for(int i = 0; i < 2; i ++) {
        //     for(int j = 0; j < 2; j ++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    cout << dp[0][0] << endl;
    return 0;
}
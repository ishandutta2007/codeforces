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
    string str;
    cin >> str;
    vector<ll> ws(n);
    for(ll &w :ws) {
        cin >> w;
    }
    vector<vector<ll>> dp(n,vector<ll>(5));
    dp[0][0] = 1e16;
    if(str[0] == 'h') { dp[0][1] = ws[0]; }
    string hard = "#hard";
    for(int i = 1; i < n; i ++) {
        dp[i][0] = 1e16;
        for(int j = 1; j <= 4; j ++) {
            if(str[i] == hard[j]) {
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]+ws[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << dp[n-1][4];
    return 0;
}
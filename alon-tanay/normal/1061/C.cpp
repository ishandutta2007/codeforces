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
    vector<int> xs(n);
    for(int &x : xs) {
        cin >> x;
    }
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 0; i < n; i ++) {
        int x = xs[i];
        int sx = sqrt(x);
        deque<pi> add;
        for(int j = 1; j <= min(sx,n); j ++) {
            if(x%j == 0) {
                add.push_back({j,dp[j-1]});
                if(j*j != x && x/j <= n) {
                    add.push_back({x/j,dp[x/j-1]});
                }
            }
        }
        for(pi p : add) {
            dp[p.f] += p.s;
            dp[p.f] %= MOD;
        }
    }
    int total = MOD - 1;
    for(int i = 0; i <= n; i ++) {
        total += dp[i];
        total %= MOD;
    }
    cout << total;
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll>
#define MOD 1000000007

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, p;
    cin >> n >> p;
    vector<ll> xs(n);
    set<ll> dis;
    for(ll i = 0; i < n; i ++) {
        cin >> xs[i];
        dis.insert(xs[i]);
    }
    vector<bool> used(n,true);
    for(ll i = 0; i < n; i ++) {
        ll x = xs[i];
        while(x) {
            if(x&1) {
                x >>= 1;
            } else {
                x >>= 1;
                if(x&1) {
                    break;
                }
                x >>= 1;
            }
            if(dis.find(x) != dis.end()) {
                used[i] = false;
                break;
            }
        }
    }
    vector<ll> dp(200005);
    dp[0] = 1;
    dp[1] = 1;
    for(ll i = 2; i <= 200004; i ++) {
        dp[i] = (dp[i-1] + dp[i-2])%MOD;
    }
    vector<ll> dp_sum(200006);
    for(ll i = 1; i <= 200005; i ++) {
        dp_sum[i] = (dp_sum[i-1] + dp[i-1]) % MOD;
    }
    ll total = 0;
    for(ll i = 0; i < n; i ++) {
        if(used[i]) {
            ll dig = log2(xs[i]);
            if(p-dig >= 0) {
                total += dp_sum[p-dig];
                total %= MOD;
            }
        }
    }
    cout << total;
    return 0;
}
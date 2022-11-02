#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
typedef long long ll;
int n, m, p;
ll a[maxn];
void solve(){
    cin >> n >> m >> p;
    ll M = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i] += (1ll<<j) * (c - '0');
        }
    }
    srand(time(0));
    set<ll> S;
    map<ll, int> cnt, dp, dp2;
    for(int it  = 0; clock() * 1.0/CLOCKS_PER_SEC < 0.5; it++) {
        int pos = (rand() * 1ll * rand() + rand()) % n;
        ll val = a[pos];
        if(S.count(val)) continue;
        S.insert(val);
        cnt.clear();
        dp.clear();

        dp[val] = 0;
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            ll c = a[i] & val;
            dp[c]++;
        }

        for(int j = 0; j < m; j++) {
            if(val & (1ll<<j)) {
                dp2 = dp;
                for(auto x: dp2) {
                    if(x.first&(1ll<<j)) {
                        dp[x.first ^ (1ll<<j)] += x.second;
                    }
                }
            }
        }
        for(auto x: dp) {
            if(x.second >= (n+1)/2 && __builtin_popcountll(x.first) > __builtin_popcountll(M)) {
                M = x.first;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        if(M&(1ll<<i)) cout << 1;
        else cout << 0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}
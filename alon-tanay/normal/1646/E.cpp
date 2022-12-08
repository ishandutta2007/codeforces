#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define ppi pair<int,pi>
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<bool> root(n+1,true);
    vector<ll> dp(20);
    vector<bool> used(20*m+1);
    vector<ll> dif(20);
    int cnt = 0;
    for(ll i = 1; i < 20; i ++) {
        for(ll j = 1; j <= m; j ++) {
            if(!used[i*j]) {
                used[i*j] = true;
                cnt ++;
            }
        }
        dp[i] = cnt;
    }
    ll total = 1;
    for(ll i = 2; i <= n; i ++) {
        if(root[i]) {
            ll p = 2;
            for(ll j = i * i; j <= n; j *= i) {
                root[j] = false;
                p ++;
            }
            p --;
            total += dp[p];
        }
    }
    cout << total;
    return 0;
}
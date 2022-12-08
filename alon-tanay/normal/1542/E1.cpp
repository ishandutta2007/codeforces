#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
ll res = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    if(n <= 2) {
        cout << 0;
        return 0;
    }
    vector<ll> choose_ord(n+1);
    choose_ord[0] = 1;
    for(int i = 1; i <= n; i ++) {
        choose_ord[i] = (choose_ord[i-1] * (n-i+1))%m;
    }
    vector<vector<ll>> inv(n,vector<ll>(n*n/2));
    inv[0][0] = 1;
    for(int s = 1; s < n; s ++) {
        for(int i = 0; i < s; i ++) {
            for(int in = i; in < n*n/2; in ++) {
                inv[s][in] += inv[s-1][in-i];
                inv[s][in] %= m;
            }
        }
    }
    vector<vector<ll>> dp(n,vector<ll>(n*n/2));
    for(int s = 0; s < n; s ++) {
        for(int d = 1; d < n*n/2; d ++) {
            ll sum = 0;
            for(int i = d; i < n*n/2; i ++) {
                sum += inv[s][i-d];
                sum %= m;
                dp[s][d] += sum * inv[s][i];
                dp[s][d] %= m;
            }
        }
    }
    for(int pre = 0; pre < n; pre ++) {
        ll cur = 0;
        int sz = n - pre;
        for(int dif = 1; dif < sz; dif ++) {
            cur += (sz-dif)*dp[sz-1][dif+1];
            cur %= m;
        }
        res += choose_ord[pre] * cur;
        res %= m;
    }
    cout << res;
    return 0;
}
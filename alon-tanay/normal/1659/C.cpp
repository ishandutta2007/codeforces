#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 998244353
#define pi pair<ll,ll>
#define f first
#define s second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--) {
        ll n, a, b;
        cin >> n>> a >> b;
        vector<ll> xs(n);
        vector<ll> suf_sum(n);
        for(ll &x : xs) { cin >> x; }
        ll sum = 0;
        for(int i = n - 1; i >= 0; i --) {
            sum += xs[i] * b;
            suf_sum[i] = sum;
        }
        ll res = suf_sum[0];
        for(int i = 0; i < n; i ++) {
            ll cur = (a+b) * xs[i] + suf_sum[i] - b * xs[i] * (n-i);
            res = min(cur,res);
        }
        cout << res << "\n";

    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 998244353
#define pi pair<int,int>
#define f first
#define s second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> xs(n);
    for(ll &x : xs) {
        cin >> x;
    }
    ll best = 1e18;
    for(int i = 0; i < n; i ++) {
        ll cur = 0;
        ll res = 0;
        for(int j = i - 1; j >= 0; j --) {
            ll m = (cur) / xs[j] + 1;
            res += m;
            cur = m * xs[j];
        }
        cur = 0;
        for(int j = i + 1; j < n; j ++) {
            ll m = (cur) / xs[j] + 1;
            res += m;
            cur = m * xs[j];
        }
        best = min(res,best);
    }
    cout << best;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j, m;
vector<pll> p;
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
//    p.push_back({1, 0});
    for (i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
//        a--;
        p.push_back({a, b});
    }
//    p.push_back({m, 0});
    sort(p.begin(), p.end());

    vector<ll> dp;
    dp.resize(m + 1, inf);
    dp[0] = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = p[i].F; j < 2 * m + 2; j++) {
            ll l = p[i].F - max(abs(j - p[i].F), p[i].S);
            l--;
            l = max(0ll, l);
            ll pay = j - p[i].F;
            pay -= p[i].S;
            pay = max(0ll, pay);
            ll vj = j;
            vj = min(vj, m);
            dp[vj] = min(dp[vj], dp[l] + pay);
            if (viv)
                cout << "After " << i << ' ' << vj << " is " << dp[vj] << "( " << l << " that is " << dp[l]  << " + " << pay << ")" << endl;
        }
        for (ll j = m - 1; j >= 0; j--)
            dp[j] = min(dp[j], dp[j+1]);
    }

    cout << dp.back();

    return 0;
}
/**
2 6
2 1
4 0

1 3
2 0




**/
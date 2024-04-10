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


ll n, i, j;
vector<ll> m;
bool viv = false;

ll a(ll r) {
    ll res = 0;
    for (ll i = 1; i < 61; i++) {
        ll y = 1ll << i;
        y--;
        for (ll j = 0; j < i - 1; j++) {
            y -= (1ll << j);
            if (y <= r) {
                res++;
            }
            y += (1ll << j);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    ans += a(r);
    ans -= a(l - 1);
    cout << ans << endl;



    return 0;
}
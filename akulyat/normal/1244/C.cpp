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

void ans(vector<ll> val) {
    for (auto i : val)
        cout << i << ' ';
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll p, w, d;
    cin >> n >> p >> w >> d;

    ll g = __gcd(w, d);
    ll com = w * d / g;
    ll delt = w / g - d / g;
    for (ll i = 0; i < 200 * kk; i++) {
        ll y = i;
        if (!((p - y * d) % w) && p - y * d >= 0) {
            ll x = (p - y * d) / w;
            ll z = n - x - y;
            if (z >= 0)
            ans({x, y, z});

        }

    }
    ans({-1});





    return 0;
}
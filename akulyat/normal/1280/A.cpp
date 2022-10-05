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


ll n, i, j, x;
string s;
vector<ll> m;
bool viv = false;

void solve() {
    cin >> x;
    cin >> s;
    n = s.size();
    ll ans = n;
    ll now = 0;
    for (ll i = 0; i < x; i++) {
        now++;
        if (s.size() < min(x + 10, ml)) {
            for (ll j = 0; j < s[now - 1] - '1'; j++)
                for (ll u = now; u < n; u++)
                    s += s[u];
            n = s.size();
            ans = n;
//            cout << "See " << s << '\n';
        } else
            ans += (ans - now) * (s[now - 1] - '1');
        ans %= mod;
    }
    if (ans < 0)
        ans += mod;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
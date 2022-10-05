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

void solve() {
    ll n;
    cin >> n;
    ll a, b, c;
    cin >> a >> b >> c;
    string s;
    cin >> s;
    string ans;
    for (auto i : s)
        ans += '.';
    ll win = 0;
    for (ll i = 0; i < n; i++) {
        bool need = true;
        if (s[i] == 'R' && b && need)
            ans[i] = 'P', b--, win++, need = false;
        if (s[i] == 'P' && c && need)
            ans[i] = 'S', c--, win++, need = false;
        if (s[i] == 'S' && a && need)
            ans[i] = 'R', a--, win++, need = false;
    }
//    cout << "__ " << s  << " : " << ans << " __" << endl;
    for (ll i = 0; i < n; i++)
        if (ans[i] == '.') {
            bool need = true;
            if (b && need)
                ans[i] = 'P', b--, need = false;
            if (c && need)
                ans[i] = 'S', c--, need = false;
            if (a && need)
                ans[i] = 'R', a--, need = false;
        }

    if (2 * win >= n)
        cout << "YES\n" << ans << '\n';
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
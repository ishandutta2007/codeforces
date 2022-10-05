#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long    ll;
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
    cin >> n;
    m.clear();
    map<ll, vector<ll>> mp;
    set <ll> s;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
        s.insert(a);
        mp[a].push_back(i);
    }
    vector<ll> bad;
    vector<ll> all;
    for (auto i : s)
        all.push_back(i);
    bad.push_back(-1);
    for (ll i = 0; i < s.size() - 1; i++)
        if (mp[all[i]].back() > mp[all[i+1]][0])
            bad.push_back(i);
    bad.push_back(s.size() - 1);
    ll ans = mod;
    for (ll i = 0; i < bad.size() - 1; i++)
        ans = min(ans, (ll)s.size() - abs(bad[i]-bad[i+1] + 1));
    cout << ans - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
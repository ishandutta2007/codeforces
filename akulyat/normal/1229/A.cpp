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
vector<ll> m, v;
set <ll> s;
vector<bool> good;
bool viv = false;

void solve(ll k) {
    for (ll i = 0; i < n; i++)
        if ((k | m[i]) == k)
            good[i] = true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    map<ll, ll> mp;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
        s.insert(a);
        mp[a]++;
    }
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    set <ll> s2;
    for (auto i : s)
        if (mp[i] > 1)
            s2.insert(i);
    s.clear();
    s = s2;
    good.resize(n, false);
    for (auto i : s)
        solve(i);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        if (good[i])
            ans += v[i];
    cout << ans << endl;

    return 0;
}
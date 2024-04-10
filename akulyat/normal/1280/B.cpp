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
vector<vector<bool>> f;
bool viv = false;

void mortal() {
    cout << "MORTAL\n";
    return;
}

void ans(ll val) {
    cout << val << '\n';
}

bool lines() {
    vector<ll> r, c;
    for (ll i = 0; i < n; i++) {
        bool good = true;
        for (ll j = 0; j < m; j++) {
            good &= f[i][j];
        }
        if (good)
            r.push_back(i);
    }
    for (ll j = 0; j < m; j++) {
        bool good = true;
        for (ll i = 0; i < n; i++) {
            good &= f[i][j];
        }
        if (good)
            c.push_back(j);
    }
    if (r.size() && r[0] == 0) {
        ans(1);
        return true;
    }
    if (r.size() && r.back() == n - 1) {
        ans(1);
        return true;
    }
    if (c.size() && c[0] == 0) {
        ans(1);
        return true;
    }
    if (c.size() && c.back() == m - 1) {
        ans(1);
        return true;
    }
    if (r.size()) {
        ans(2);
        return true;
    }
    if (c.size()) {
        ans(2);
        return true;
    }
    return false;
}

bool corners() {
    if (f[0][0]) {
        ans(2);
        return true;
    }
    if (f[0][m-1]) {
        ans(2);
        return true;
    }
    if (f[n - 1][0]) {
        ans(2);
        return true;
    }
    if (f[n - 1][m-1]) {
        ans(2);
        return true;
    }
    return false;
}

bool sides() {
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (f[i][j] && (i == 0 || j == 0 || i == n-1 || j == m-1)) {
                ans(3);
                return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    f.clear();
    bool can = false;
    bool all = true;
    for (i = 0; i < n; i++) {
        f.push_back({});
        string a;
        cin >> a;
        for (ll j = 0; j < m; j++) {
            f[i].push_back(a[j] == 'A');
            can |= a[j] == 'A';
            all &= a[j] == 'A';
        }
    }
    if (all) {
        ans(0);
        return;
    }
    if (!can) {
        mortal();
        return;
    }
    if (lines())
        return;
    if (corners())
        return;
    if (sides())
        return;
    ans(4);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
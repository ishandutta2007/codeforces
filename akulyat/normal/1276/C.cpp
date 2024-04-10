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


ll n, i, j, rn;
vector<ll> m;
vector<pll> v;
bool viv = false;

ll ma(ll n) {
    ll best = 0;
    for (ll i = n; i*n <= rn; i++) {
        if (v[i * n - 1].F <= n)
            best = i;
    }
    return best;
}

void solve(ll n) {
    ll m = ma(n);
    ll sz = n * m;
    vector<vector<ll>> ans(n);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
            ans[i].push_back(-1);
    }

    ll x, y;
    x = y = 0;
    vector<ll> lv;
    for (ll i = 0; i < sz; i++)
        lv.push_back(v[i].S);
    sort(lv.begin(), lv.end());
    ll las = 0;
    vector<ll> full;
    for (ll i = 0; i < lv.size(); i++) {
        ll cnt = 1;
        if (i > 0 && lv[i] == lv[i-1])
            cnt += las;        
        las = cnt;
        if (cnt == n)
            full.push_back(lv[i]);
    }
    vector<ll> h;
    for (auto i : full)
        for (ll j = 0; j < n; j++)
            h.push_back(i);
    set<ll> s;
    for (auto i : full)
        s.insert(i);

    for (auto i : lv)
        if (s.count(i) == 0)
            h.push_back(i);
    lv = h;

    if (viv) {
        for (auto i : lv)
            cout << i << ' ';
        cout << endl;
    }
    for (ll i = 0; i < n * m; i++) {
        while (ans[x][y] != -1) {
            y++;
            if (y >= m)
                y = 0;
        }
        ans[x][y] = lv[i];
        x++;
        y++;
        if (x >= n)
            x = 0;
        if (y >= m)
            y = 0;
    }

    cout << sz << endl;
    cout << n << ' ' << m << endl;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}


int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rn = n;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    sort(m.begin(), m.end());
    ll las = 0;
    for (ll i = 0; i < n; i++) {
        ll cnt = 1;
        if (i > 0 && m[i] == m[i-1])
            cnt += las;
        las = cnt;
        v.push_back({cnt, m[i]});
    }
    sort(v.begin(), v.end());
    if (viv) {
        for (auto i : v)
            cout << i.F << ' ' << i.S << "; ";
        cout << endl;
    }
    ll ans = 1;
    ll myn = 1;
    for (ll i = 1; i <= n; i++) {
        ll m = ma(i);
        ans = max(ans, i * m);
        if (i * m == ans)
            myn = i;
    }
    solve(myn);






    return 0;
}
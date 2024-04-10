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
vector<ll> ans;
vector<ll> t, t2;
ll s;
bool viv = false;

void prepare() {
    s = 1;
    while (s < m.size())
        s <<= 1;

    t.resize(2 * s);
    for (ll i = 0; i < m.size(); i++)
        t[s + i] = m[i];
    for (ll i = s-1; i > 0; i--)
        t[i] = min(t[2*i], t[2*i + 1]);

    t2.resize(2 * s);
    for (ll i = 0; i < m.size(); i++)
        t2[s + i] = m[i];
    for (ll i = s-1; i > 0; i--)
        t2[i] = max(t2[2*i], t2[2*i + 1]);
}

ll min(ll l, ll r, ll v, ll tl, ll tr) {
    if (r < tl || tr < l)
        return mod;
    if (l <= tl && tr <= r)
        return t[v];
    ll tm = tl + tr >> 1;
    ll v1 = min(l, r, 2*v, tl, tm);
    ll v2 = min(l, r, 2*v+1, tm+1, tr);
    return min(v1, v2);
}

ll max(ll l, ll r, ll v, ll tl, ll tr) {
    if (r < tl || tr < l)
        return 0;
    if (l <= tl && tr <= r)
        return t2[v];
    ll tm = tl + tr >> 1;
    ll v1 = max(l, r, 2*v, tl, tm);
    ll v2 = max(l, r, 2*v+1, tm+1, tr);
    return max(v1, v2);
}

void solve(ll num, bool fir = false) {
    ll l = num;
    ll r = num + n;

    while (l + 1 < r) {
        ll mi = l + r >> 1;
        if (min(num, mi, 1, 0, s-1)*2 >= m[num])
            l = mi;
        else
            r = mi;
    }
    ll lans = l - num + 1;
    if (lans == n && fir) {
        for (int i = 0; i < n; i++)
            cout << -1 << ' ';
        exit(0);
    }
    if (lans == n)
        lans = 2*n;
    ans[num] = lans;
    if (viv)
        cout << "clear for " << num << ' ' << ans[num] << endl;
}


int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    for (ll i = 0; i < n; i++)
        m.push_back(m[i]);

    ll mpl = max_element(m.begin(), m.end()) - m.begin();
    ans.resize(n, 0);
    prepare();
    if (viv) {
        for (auto i : t)
            cout << i << ' ';
        cout << endl;
        for (auto i : t2)
            cout << i << ' ';
        cout << endl;
    }

    solve(mpl, true);
    for (int i = mpl + n - 1; i > mpl; i--) {
        ll who = i % n;
        solve(who);
        ll l = who;
        ll r = who + n - 1;
        while (l + 1 < r) {
            ll mi = l + r >> 1;
            ll val = max(who + 1, mi, 1, 0, s-1);
            if (val >= m[who])
                r = mi;
            else
                l = mi;
        }
        if (viv) {
            cout << "near for " << who << " is " << r << endl;
            cout << ans[who] << ' ' << ans[r%n] << ' ' << r << ' ' << who << endl;
            cout << endl;
        }
        ans[who] = min(ans[who], ans[r % n] + r - who);
    }
    for (auto i : ans)
        cout << i << ' ';


    return 0;
}
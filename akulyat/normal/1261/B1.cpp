#include <bits/stdc++.h>

#pragma GCC optimize("O3", "unroll-all-loops")

using namespace std;

#define F first
#define S second
typedef int   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
const ll s = 300;

ll n, i, j;
vector<ll> m;
vector<pll> tos;
vector<vector<pll>> allns;
vector<vector<ll>> bs, all;
bool viv = false;

vector<ll> merge(vector<ll> a, vector<ll> b) {
    ll i = 0, j = 0;
    vector<ll> res;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j])
            res.push_back(a[i]), i++;
        else
            res.push_back(b[j]), j++;
    }
    while (i < a.size())
        res.push_back(a[i]), i++;
    while (j < b.size())
        res.push_back(b[j]), j++;
    return res;
}

void prepare() {
    for (ll i = 0; i < n; i++) {
        tos.push_back({m[i], -i});
    }
    sort(tos.rbegin(), tos.rend());
    for (auto &i : tos)
        i.S *= -1;
    for (ll i = 0; i < n; i += s) {
        ll r = i + s;
        r = min(r, n);
        vector<pll> sv;
        for (ll j = i; j < r; j++)
            sv.push_back(tos[j]);
        allns.push_back(sv);
        vector<ll> vv;
        for (auto i : sv)
            vv.push_back(i.S);
        sort(vv.begin(), vv.end());
        all.push_back(vv);
    }
    for (ll i = 0; i < all.size(); i++) {
        auto z = all[i];
        if (i)
            z = merge(bs[i-1], z);
        bs.push_back(z);
        if (viv) {
            for (auto i : z)
                cout << i << ' ';
            cout << endl;
        }
    }
}

void solve() {
    ll k, pos;
    cin >> k >> pos;
    pos --;
    ll full = k / s;
    k -= full * s;
    vector<pll> add2;
    for (ll i = 0; i < k; i++)
        add2.push_back(allns[full][i]);
    vector<ll> add;
    for (auto i : add2)
        add.push_back(i.S);
    sort(add.begin(), add.end());
    if (viv) {
        cout << "A ";
        for (auto i : add)
            cout << i << ' ';
        cout << endl;
    }
    if (full == 0) {
//        cout << add[pos] + 1 << '\n';
        if (viv)
            cout << "pos " << pos << ' ';
        cout << m[add[pos]] << '\n';
        return;
    }
    ll pl = pos - add.size();
    if (pl < 0) {
        vector<ll> a;
        for (ll i = 0; i < min(bs[full-1].size(), add.size()); i++)
            a.push_back(bs[full-1][i]);
        a = merge(a, add);
        cout << m[a[pos]] << '\n';
        return;
    }
    if (viv) {
        cout << "B " << full << '\n';
        for (auto i : bs[full - 1])
            cout << i << ' ';
        cout << '\n';
        for (auto i : add)
            cout << i << ' ';
        cout << '\n';
    }
    for (ll i = 0; i < add.size(); i++) {
        if (bs[full - 1][pl] > add[i])
            pl++;
    }
    cout << m[bs[full-1][pl]] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    prepare();
    ll q;
    cin >> q;
    while (q--)
        solve();







    return 0;
}
#include <bits/stdc++.h>

#pragma GCC optimize("O3", "unroll-all-loops")
#pragma GCC target("avx2")

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

struct node {
    ll mi = 0, ma = 0, ps = 0;
};

ll n, i, j, bal;
vector<ll> m, v;
bool viv = false;
vector<node> t;
ll s;



void prepare() {
    s = 1;
    while (s < v.size())
        s <<= 1;
    t.resize(2 * s);
}

void adder(ll v, ll val) {
    t[v].mi += val;
    t[v].ma += val;
    t[v].ps += val;
}

void push(ll v) {
    if (v >= s)
        return;
    ll add = t[v].ps;
    t[v].ps = 0;
    adder(2*v, add);
    adder(2*v + 1, add);
}

void upd(ll v) {
    if (v >= s)
        return;
    t[v].mi = min(t[2*v].mi, t[2*v+1].mi);
    t[v].ma = max(t[2*v].ma, t[2*v+1].ma);
}

void add(ll l, ll r, ll v, ll tl, ll tr, ll val) {
    if (r < tl || tr < l)
        return;
//    cout << "Oooon " << l << ' ' << r << endl;
    if (viv)
        cout << "On " << v << ' ' << tl << ' ' << tr << ' ' << val << endl;
    push(v);
    if (l <= tl && tr <= r) {
        t[v].mi += val;
        t[v].ma += val;
        t[v].ps += val;
        return;
    }
    ll tm = tl + tr >> 1;
    add(l, r, 2*v, tl, tm, val);
    add(l, r, 2*v + 1, tm+1, tr, val);
    upd(v);
}

void change(ll pos, ll val) {
    ll was = v[pos];
    add(pos, v.size() - 1, 1, 0, s - 1, val - was);
    bal += val - was;
    if (viv || false) {
        cout << "Tree: ";
        for (ll i = 1; i < 2 * s; i++) {
            cout << t[i].mi << ' ' << t[i].ma << ' ' << t[i].ps << "; ";
            if (!(i & (i + 1)))
                cout << endl;
        }
        cout << endl;
    }
    v[pos] = val;
}

void solve() {
//    add(0, v.size()-1, 1, 0, s-1, 0);
    if (bal || t[1].mi < 0) {
        cout << "-1 ";
    } else {
        cout << t[1].ma << ' ';
    }
}

int main() {
//    viv = true;
//    freopen("a.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    string s;
    cin >> s;
    v.resize(n + 2, 0);
    for (i = 0; i < n; i++) {
        ll a = 0;
        if (s[i] == '(')
            a = 1;
        if (s[i] == ')')
            a = -1;
        if (s[i] == 'L')
            a = 3;
        if (s[i] == 'R')
            a = 4;
        m.push_back(a);
    }
    prepare();

    ll pos = 0;
    for (auto i : m) {
//        cout << "_" << i << ' ' << pos << "_" << endl;
        if (viv)
            cout << "val " << i << endl;
        if (i == 3)
            pos--;
        if (i == 4)
            pos++;
        pos = max(pos, 0);
        if (i != 3 && i != 4) {
            change(pos, i);
        }
        solve();
    }







    return 0;
}
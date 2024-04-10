#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("fma")
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
//const long long inf = kk + 7;


ll n, i, j, a, b, c;
vector<ll> m[3];
vector<ll> where;
bool viv = false;
ll s;
vector<pll> t;

void ad(ll v, ll val) {
    t[v].F += val;
    t[v].S += val;
}

void push(ll v) {
    if (v >= s)
        return;
    ll add = t[v].S;
    t[v].S = 0;
    ad(2*v, add);
    ad(2*v + 1, add);
}

void upd(ll v) {
    if (v >= s)
        return;
    push(2*v);
    push(2*v + 1);
    t[v].F = min(t[2*v].F, t[2*v+1].F);
}

void add(ll l, ll r, ll v, ll tl, ll tr, ll val) {
    if (r < tl || tr < l)
        return;
    push(v);
    if (l <= tl && tr <= r) {
        t[v].F += val;
        t[v].S += val;
        push(v);
        return;
    }

    ll tm = tl + tr >> 1;
    add(l, r, 2*v, tl, tm, val);
    add(l, r, 2*v + 1, tm + 1, tr, val);
    upd(v);
}



void build() {
    s = 1;
    while (s < n)
        s <<= 1;
    t.resize(2*s);
    ll cnt = 0;
    for (ll i = 0; i < s; i++)
        t[s + i].F = inf;
    for (auto i : m[1])
        t[s + i].F = 0;
    for (ll i = s - 1; i > 0; i--)
        t[i].F = min(t[2*i].F, t[2*i+1].F);

    for (auto i : m[1])
        add(0, i - 1, 1, 0, s-1, 1);
    for (auto i : m[2])
        add(i + 1,  n-1, 1, 0, s-1, 1);
}

ll mini(ll l, ll r, ll v, ll tl, ll tr) {
    if (r < tl || tr < l) {
        return inf;
    }
    push(v);
    if (l <= tl && tr <= r) {
        return t[v].F;
    }

    ll tm = tl + tr >> 1;
    ll v1 = mini(l, r, 2*v, tl, tm);
    ll v2 = mini(l, r, 2*v + 1, tm + 1, tr);
    return min(v1, v2);
}

void show() {
    cout << "Tree: with " << 2 * s << endl;
    for (ll i = 1; i < 2*s; i++) {
        cout << t[i].F << ' ' << t[i].S << "; ";
        if (!(i & (i + 1)))
            cout << endl;
    }

}

void solve() {
    build();
    if (viv)
        show();
    if (viv)
        cout << "Adder end" << endl;
    if (viv)
        show();
    if (viv)
        cout << "End of preparing" << endl;
    if (viv)
        show();
    ll lans = m[0].size();
    ll ans = lans + mini(0, n-1, 1, 0, s-1);
    if (viv)
        cout << "______________ At start " << ans << endl;
    ans = min(min(ans, n - a), min(n - b, n - c));
    ll on[3];
    on[1] = b;
    on[2] = c;
    for (ll i = 0; i < n; i++) {
        if (viv)
            cout << "what about prefix " << i << endl;
        ll w = where[i];
        if (w == 0) {
            lans--;
        }
        if (w == 1) {
            lans++;
            add(i, i, 1, 0, s-1, inf);
            add(0, i - 1, 1, 0, s-1, -1);
            on[1]--;
        }
        if (w == 2) {
            lans++;
            add(i + 1, n - 1, 1, 0, s-1, -1);
            on[2]--;
        }
        if (viv) {
            cout << "_______ On pref " << i << " can " << lans << ' ' << mini(0, n-1, 1, 0, s-1);
            cout << endl;
            show();
        }
        ans = min(ans, lans + mini(0, n-1, 1, 0, s-1));
        ans = min(ans, lans + min(on[1], on[2]));
    }
    cout << ans << endl;
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
    n = a + b + c;
    m[0].resize(a);
    m[1].resize(b);
    m[2].resize(c);
    where.resize(n);
    for (ll j = 0; j < 3; j++) {
        for (auto &i : m[j])
            cin >> i, i--;
        sort(m[j].begin(), m[j].end());
        for (auto i : m[j])
            where[i] = j;
    }

/**
    ll l = -1;
    ll r = n;
    while (l + 1 < r ) {
        ll mi = l + r >> 1;
        if (can(mi))
            r = mi;
        else
            l = mi;
    }
    cout << r << endl;
**/
    solve();


    return 0;
}
/**
3 2 2
1 4 7
2 6
3 5

3 3 3
1 2 3
4 5 6
7 8 9

3 3 3
7 8 9
1 2 3
4 5 6

3 3 3
4 5 6
7 8 9
1 2 3

4 4 4
1 2 3 8
5 6 7 10
4 9 11 12

5 4 3
1 3 8 10 12
2 5 6 7
4 9 11

3 2 2
1 3 4
5 2
6 7


**/
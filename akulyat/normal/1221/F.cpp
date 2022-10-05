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

struct node{
    ll max;
    ll push;
};

ll n, i, j, s;
vector<pair<pll, ll>> m;
vector<ll> blocks, was;
unordered_map<ll, ll> mp;
bool viv = false;
vector<node> t;

void show_tree() {
    cout << "Segment tree:" << endl;
    for (ll i = 1; i < 2 * s; i++) {
        cout << t[i].max << ' ' << t[i].push <<";\t";
        if ((i & (i + 1)) == 0)
            cout << endl;
    }
    cout << endl;
}

void read() {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll x, y, c;
        cin >> x >> y >> c;
        if (y > x)
            swap(x, y);
        m.push_back({{x, y}, c});
    }

}

void compress() {
    set<ll> all_x;
    for (auto p : m)
        all_x.insert(p.F.F);
    for (auto x : all_x)
        mp[x] = was.size(), was.push_back(x);

    for (auto& p : m)
        p.F.F = mp[p.F.F];
}

bool cmp(pair<pll, ll> a, pair<pll, ll> b) {
    if (a.F.S > b.F.S)
        return true;
    if (a.F.S < b.F.S)
        return false;
    return false;
}

void sorted() {
    sort(m.begin(), m.end(), cmp);
}

void calc(ll pl) {
    if (pl >= s)
        return;
    t[pl].max = max(t[2 * pl].max, t[2 * pl + 1].max);
}

void build() {
    s = 1;
    while (s < was.size())
        s <<= 1;
    t.resize(2 * s);
    for (ll i = 0; i < was.size(); i++)
        t[s + i].max = -was[i];
    for (ll i = was.size(); i < s; i++)
        t[s + i].max = -inf;
    for (ll i = s - 1; i > 0; i--)
        calc(i);
}

void ub(ll pl) {
    t[pl].max = max(t[pl].max, -inf);
    t[pl].push = max(t[pl].push, -inf);
}

void push(ll pl) {
    if (pl >= s)
        return;
    ll push = t[pl].push;
    t[pl].push = 0;
    t[2 * pl].push += push;
    t[2 * pl +1 ].push += push;
    t[2 * pl].max += push;
    t[2 * pl +1 ].max += push;
    ub(2 * pl);
    ub(2 * pl + 1);
}

void add(ll l, ll r, ll v, ll tl, ll tr, ll val) {
    if (r < tl || tr < l)
        return;
    push(v);
    if (l <= tl && tr <= r) {
        t[v].max += val;
        t[v].push += val;
        push(v);
        return;
    }
    ll tm = tl + tr >> 1;
    add(l, r, 2 * v, tl, tm, val);
    add(l, r, 2 * v + 1, tm + 1, tr, val);
    calc(v);
}

ll max(ll l, ll r, ll v, ll tl, ll tr) {
    if (r < tl || tr < l)
        return -inf;
    push(v);
    if (l <= tl && tr <= r) {
        return t[v].max;
    }
    ll tm = tl + tr >> 1;
    ll m1 = max(l, r, 2 * v, tl, tm);
    ll m2 = max(l, r, 2 * v + 1, tm + 1, tr);
    return max(m1, m2);
}


void prepare() {
    blocks.push_back(-1);
    for (ll i = 0; i < n; i++)
        if (i == n - 1 || m[i].F.S != m[i+1].F.S)
            blocks.push_back(i);
    build();
}

void split(ll l, ll r, ll v, ll tl, ll tr, vector<pair<ll, pll>>& vec) {
    if (r < tl || tr < l)
        return;
    push(v);
    if (l <= tl && tr <= r) {
        vec.push_back({v, {tl, tr}});
        return;
    }
    ll tm = tl + tr >> 1;
    split(l, r, 2 * v, tl, tm, vec);
    split(l, r, 2 * v + 1, tm + 1, tr, vec);
}

ll find(ll v, ll tl, ll tr, ll val) {
    if (tl == tr) {
        if (t[v].max != val)
            return -mod;
        if (tl >= was.size())
            return -mod;
        return tl;
    }
    push(v);
    ll tm = tl + tr >> 1;
    if (t[2 * v + 1].max == val)
        return find(2 * v + 1, tm + 1, tr, val);
    return find(2 * v, tl, tm, val);
}

void solve() {
    ll d = mod;
    ll r = mod;
    ll ans = 0;

    if (viv) {
        cout << "Points:\n";
        for (auto p : m)
            cout << p.F.F << ' ' << p.F.S << ' ' << p.S << endl;
        cout << "blocks:\n";
        for (auto i : blocks)
            cout << i << ' ';
        cout << endl;
        show_tree();
    }

    for (ll i = 1; i < blocks.size(); i++) {
        for (ll j = blocks[i - 1] + 1; j <= blocks[i]; j++)
            add(m[j].F.F, was.size() - 1, 1, 0, s-1, m[j].S);
        ll cur_d = m[blocks[i]].F.S;

        ll mix = lower_bound(was.begin(), was.end(), cur_d) - was.begin();
        ll res = max(mix, was.size() - 1, 1, 0, s-1);
        if (res + cur_d > ans) {
            res += cur_d;
            ll cur_r = -1;
            vector<pair<ll, pll>> v;
            split(mix, was.size() - 1, 1, 0, s-1, v);
            for (auto p : v)
                if (t[p.F].max == res - cur_d)
                    cur_r = find(p.F, p.S.F, p.S.S, res - cur_d);
            if (0 <= cur_r && cur_r < was.size()) {
                cur_r = was[cur_r];
                if (viv) {
                    cout << "with " << m[blocks[i]].F.S << " can reach " << res << endl;
                    cout << "cur_r = " << cur_r << endl;
                    show_tree();
                }

                if (cur_r >= cur_d) {
                    d = cur_d;
                    r = cur_r;
                    ans = res;
                }
            }
        }
    }
    cout << ans << endl;
    cout << d << ' ' << d << ' ' << r << ' ' << r;
}


int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    read();
    compress();
    sorted();
    prepare();
    solve();

    return 0;
}

/**
5
5 5 2
6 5 -3
7 5 5
8 5 0
9 5 3


**/
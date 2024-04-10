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
const long long gs = 2 * kk;

ll l, n1, m1, n2, m2;
vector<ll> reb1[gs + 10], reb2[gs + 10];
vector<ll> col1, col2, lst1, lst2, q1, q2, sz1, sz2, p1, p2;
vector<pll> seg1, seg2;
vector<pair<pll, ll>> all;
bool viv = false;

void DFS1(ll v, ll c) {
    col1[v] = c;
    ll l = reb1[v].size();
    for (ll i = 0; i < l; i++) {
        ll s = reb1[v][i];
        if (col1[s] == -1) {
            DFS1(s, c  +1);
        }
    }
    q1.push_back(v);
}

void DFS2(ll v, ll c) {
    col2[v] = c;
    ll l = reb2[v].size();
    for (ll i = 0; i < l; i++) {
        ll s = reb2[v][i];
        if (col2[s] == -1) {
            DFS2(s, c  +1);
        }
    }
    q2.push_back(v);
}

void work1(ll v) {
    if (seg1[v].F >= 0)
        return;
    ll mi = mod;
    ll ma = -mod;
    sz1[v] = 1;
    for (auto s : reb1[v]) {
        if (col1[s] > col1[v]) {
            mi = min(mi, seg1[s].F);
            ma = max(ma, seg1[s].S);
            sz1[v] += sz1[s];
        }
    }
    seg1[v] = {mi, ma};
    if (v == 0)
        sz1[v]--;
    all.push_back({{mi, ma}, sz1[v]});
}

void work2(ll v) {
    if (seg2[v].F >= 0)
        return;
    ll mi = mod;
    ll ma = -mod;
    sz2[v] = 1;
    for (auto s : reb2[v])
        if (col2[s] > col2[v]) {
            mi = min(mi, seg2[s].F);
            ma = max(ma, seg2[s].S);
            sz2[v] += sz2[s];
        }
    seg2[v] = {mi, ma};
    if (v == 0)
        sz2[v]--;
    all.push_back({{mi, ma}, sz2[v]});
}

void sort(vector<pair<pll, ll>> &v) {
    vector<vector<ll>> tos(l);
    for (ll i = 0; i < v.size(); i++) {
        tos[v[i].F.F].push_back(i);
    }
    vector<pair<pll, ll>> new_v;
    for (ll i = 0; i < l; i++) {
        for (auto num : tos[i])
            new_v.push_back(v[num]);
    }
    v = new_v;
}

void solve() {
    vector<ll> ans(l + 1, 0);
    sort(all);
    ll las = 0;

    for (auto p : all) {
        for (ll i = las + 1; i <= p.F.F; i++)
            ans[i] = max(ans[i], ans[i-1]);
        las = p.F.F;
        ans[p.F.S + 1] = max(ans[p.F.S + 1], ans[p.F.F] + p.S);
    }
    for (ll i = las + 1; i < ans.size(); i++)
        ans[i] = max(ans[i], ans[i-1]);

    cout << ans.back();
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> l;
    cin >> n1;
    m1 = n1 - 1;
    p1.resize(n1, 0);
    for (ll i = 1; i < n1; i++) {
        long a, b;
        b = i;
        cin >> a;
        a--;
        reb1[a].push_back(b);
        reb1[b].push_back(a);
        p1[b] = a;
    }
    col1.assign(n1, -1);
    sz1.assign(n1, -1);
    seg1.resize(n1, {-1, -1});
    for (ll i = 0; i < l; i++) {
        ll a;
        cin >> a;
        a--;
        lst1.push_back(a);
        seg1[a] = {i, i};
        sz1[a] = 1;
        all.push_back({{i, i}, 1});
    }

    cin >> n2;
    m2 = n2 - 1;
    p2.resize(n2, 0);
    for (ll i = 1; i < n2; i++) {
        long a, b;
        b = i;
        cin >> a;
        a--;
        reb2[a].push_back(b);
        reb2[b].push_back(a);
        p2[b] = a;
    }
    col2.assign(n2, -1);
    sz2.assign(n2, -1);
    seg2.resize(n2, {-1, -1});
    for (ll i = 0; i < l; i++) {
        ll a;
        cin >> a;
        a--;
        lst2.push_back(a);
        seg2[a] = {i, i};
        sz2[a] = 1;
        all.push_back({{i, i}, 1});
    }


    DFS1(0, 0);
    DFS2(0, 0);

    for (auto i : q1)
        work1(i);
    for (auto i : q2)
        work2(i);

    solve();


    return 0;
}
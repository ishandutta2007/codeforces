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

ll n, m, i, j;
vector<vector<ll>> reb;
vector<ll> col, tc, sz;
vector<pll> seg;
bool viv = false;

void DFS(ll v, ll c) {
    col[v] = c;
    ll l = reb[v].size();
    sz[v] = 1;
    for (ll i = 0; i < l; i++) {
        ll s = reb[v][i];
        if (col[s] == -1) {
            DFS(s, c  +1);
            sz[v] += sz[s];
        }
    }
}

void BFS(ll v) {
    vector<long> st;
    st.push_back(v);
    ll s = 0;
    tc[v] = 0;
    while (s < st.size()) {
        ll e = st[s];
        ll l = reb[e].size();
        for (ll i = 0; i < l; i++) {
            ll s = reb[e][i];
            if (tc[s] == -1) {
                st.push_back(s);
                tc[s] = tc[e]+1;
            }
        }
        s++;
    }
}


void solve(ll v, ll l, ll r) {
	vector<ll> kids;
	for (auto s : reb[v])
		if (col[s] > col[v])
			kids.push_back(s);
	ll k = kids.size();
	seg[v].S = l + k;
	ll lef = l + k - 1;
	ll tl, tr;
	tl = l + k + 1;
	for (auto s : kids) {
		tr = tl + 2 * sz[s] - 2;
		seg[s].F = lef;
		solve(s, tl, tr);
		tl = tr + 1;
		lef--;
	}
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    m = n - 1;
    reb.resize(n);
    for (i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;
        a--; b--;
        reb[a].push_back(b);
        reb[b].push_back(a);
    }
    col.assign(n, -1);
    sz.resize(n, 0);
    DFS(0, 0);
    seg.resize(n);
    seg[0].F = 0;
    solve(0, 1, 2 * n - 1);

    for (auto p : seg) {
    	cout << p.F + 1 << ' ';
    	cout << p.S + 1 << '\n';
    }



    return 0;
}
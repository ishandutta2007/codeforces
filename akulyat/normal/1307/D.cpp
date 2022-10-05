#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
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
 
ll n, m, s;
vector<vector<ll>> reb;
vector<ll> sp;
bool viv = false;

vector<ll> BFS(ll v) {
	vector<ll> col(n, mod);
	col[v] = 0;
	vector<ll> q;
	q.push_back(v);
	ll st = 0;
	while (st != q.size()) {
		ll v = q[st];
		for (auto s : reb[v])
			if (col[s] == mod) {
				col[s] = col[v] + 1;
				q.push_back(s);
			}
		st++;
	}
	return col;
}

void solve() {
	cin >> n >> m >> s;
	sp.resize(s, 0);
	for (auto &i : sp)
		cin >> i, i--;
	reb.resize(n);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		reb[a].push_back(b);
		reb[b].push_back(a);
	}

	auto st = BFS(0);
	auto en = BFS(n - 1);
	vector<pll> vall;
	for (auto v : sp) 
		vall.push_back({min(st[v], en[v]), v});
	vector<ll> vv;
	sort(vall.rbegin(), vall.rend());
	for (ll i = 0; i < min(100ll, (ll)vall.size()); i++)
		vv.push_back(vall[i].S);
	sort(vall.begin(), vall.end());
	for (ll i = 0; i < min(100ll, (ll)vall.size()); i++)
		vv.push_back(vall[i].S);
	ll dist = 0;
	for (auto v : vv) {
		for (auto sv : sp) 
			if (sv != v) {
				ll ldist = 1 + min(st[v] + en[sv], st[sv] + en[v]);
				dist = max(dist, ldist);
			}
		}
	ll ans = min(dist, st.back());

	cout << ans << endl;
}


int main() {
//	viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}
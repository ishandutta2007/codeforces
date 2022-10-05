#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 
typedef pair<pll, int> pp;
ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
const int K = 18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
vector<vector<int>> e, re;
bool viv = false;

void Dij1() {
	vector<pll> d(2 * n, {mod, mod});
	d[0] = {0, 0};
	d[1] = {1, 0};
	set<pair<pll, int>> st;
	for (int i = 0; i < 2 * n; i++) 
		st.insert({d[i], i});

	while (st.size()) {
		auto p = *st.begin();
		st.erase(p);
		int fv = p.S;
		int v = fv / 2;
		int tp = fv & 1;
		if (viv)	
			cout << "work " << fv << " dp = " << d[fv].F << ' ' << d[fv].S << endl;
		for (auto s : e[v]) {
			auto can = d[fv];
			can.S++;
			int fs = 2 * s;
			if (tp)
				can.F++;
			if (st.find({d[fs], fs}) != st.end()) {
				st.erase({d[fs], fs});
				d[fs] = min(d[fs], can);
				st.insert({d[fs], fs});
			}
		}
		for (auto s : re[v]) {
			auto can = d[fv];
			can.S++;
			int fs = 2 * s + 1;
			if (!tp)
				can.F++;
			if (st.find({d[fs], fs}) != st.end()) {
				st.erase({d[fs], fs});
				d[fs] = min(d[fs], can);
				st.insert({d[fs], fs});
			}
		}
	}
	if (viv) {
		for (auto p : d) {
			cout << p.F << ' ' << p.S << endl;
		}
	}

	if (min(d[2 * n - 2].F, d[2 * n - 1].F) >= K) {
		auto p = min(d[2 * n - 2], d[2 * n - 1]);
		ll ans = p.S;
		ll add = 1;
		for (int i = 0; i < p.F; i++) {
			add <<= 1;
			if (add >= mod)
				add -= mod;
		}
		add--;
		if (add < 0)
			add += mod;
		ans += add;
		ans += mod;
		ans %= mod;
		cout << ans << '\n';
		exit(0);
	}
}

void Dij2() {
	int V = K * n;
	vector<int> d(V, mod);
	for (int i = 0; i < K; i++) 
		d[i] = (1 << i) - 1;
	priority_queue<pii> st;
	for (int i = 0; i < V; i++)
		st.push({d[i], i});
	while (st.size()) {
		auto p = st.top();
		st.pop();
		int fv = p.S;
		int v = fv / K;
		int used = fv % K;
		if (d[fv] == p.F) {
			for (auto s : e[v]) {
				auto can = d[fv];
				can++;	
				auto fs = s * K + used;
				bool need = true;
				if (used & 1) {
					fs++;
					can += (1 << used);
					if (used + 1 == K)
						need = false;
				}
				if (need && can < d[fs]) {
					// st.erase({d[fs], fs});
					d[fs] = can;
					st.push({d[fs], fs});
				}
			}
			for (auto s : re[v]) {
				auto can = d[fv];
				can++;
				auto fs = s * K + used;
				bool need = true;
				if (!(used & 1)) {
					fs++;
					can += (1 << used);
					if (used + 1 == K)
						need = false;
				}
				if (need && can < d[fs]) {
					// st.erase({d[fs], fs});
					d[fs] = can;
					st.push({d[fs], fs});
				}
			}
		}
	}
	int ans = mod;
	for (int i = 0; i < K; i++)
		ans = min(ans, d[K * (n - 1) + i]);
	cout << ans << '\n';
}

void Dij3() {
	int V = K * n;
	vector<int> d(V, mod);
	for (int i = 0; i < K; i++) 
		d[i] = (1 << i) - 1;
	vector<vector<int>> q(n + (1 << (K + 1)) + 3);
	for (int i = 0; i < K; i++) 
		q[d[i]].push_back(i);

	for (int sl = 0; sl < q.size(); sl++) {
		for (auto fv : q[sl]) 
			if (d[fv] == sl) {
				int v = fv / K;
				int used = fv % K;
				for (auto s : e[v]) {
					auto can = d[fv];
					can++;	
					auto fs = s * K + used;
					bool need = true;
					if (used & 1) {
						fs++;
						can += (1 << used);
						if (used + 1 == K)
							need = false;
					}
					if (need && can < d[fs]) {
						// st.erase({d[fs], fs});
						d[fs] = can;
						// st.push({d[fs], fs});
						q[d[fs]].push_back(fs);
					}
				}
				for (auto s : re[v]) {
					auto can = d[fv];
					can++;
					auto fs = s * K + used;
					bool need = true;
					if (!(used & 1)) {
						fs++;
						can += (1 << used);
						if (used + 1 == K)
							need = false;
					}
					if (need && can < d[fs]) {
						// st.erase({d[fs], fs});
						d[fs] = can;
						// st.push({d[fs], fs});
						q[d[fs]].push_back(fs);
					}
				}
		}
	}
	int ans = mod;
	for (int i = 0; i < K; i++)
		ans = min(ans, d[K * (n - 1) + i]);
	cout << ans << '\n';
}

void work() {
	Dij1();
	// Dij2();
	Dij3();
}

void solve() {
	cin >> n >> m;
	e.resize(n);
	re.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		re[b].push_back(a);
	}
	work();	
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}
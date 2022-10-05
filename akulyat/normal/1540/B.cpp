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

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<vector<int>> e;
bool viv = false;

ll bpow(ll val, ll mod, ll st = -1) {
	if (st == -1)
		st = mod - 2;
	if (st == 0)
		return 1;
	ll res = bpow(val, mod, st >> 1);
	res = res * res, res %= mod;
	if (st & 1)
		res *= val, res %= mod;
	return res;
}

ll inv(ll val) {
	val %= mod;
	return bpow(val, mod, -1);
}

vector<int> d, q;
vector<vector<int>> sons;
ll ans[600][600];
void DFS(int v, int c = 0) {
	d[v] = c;
	for (auto u : e[v])
		if (d[u] == -1)
			DFS(u, c + 1);
	q.push_back(v);
}

ll worker(int v) {
	vector<int> now;
	ll res = 0;
	for (auto u : e[v]) {
		if (d[u] > d[v]) {
			for (auto p1 : sons[u]) {
				for (auto p2 : now) {
					int s1 = p1;
					int s2 = p2;
					if (s1 < s2) {
						swap(s1, s2);
					}
					int d1 = d[s1] - d[v];
					int d2 = d[s2] - d[v];					
					res += ans[d1][d2];
				}
			}
			for (auto son: sons[u]) 
				now.push_back(son);
		}
	}
	now.push_back(v);
	sons[v] = now;
	for (auto son : sons[v])
		res += (son < v);
	res %= mod;
	return res;
}

ll work(int root) {
	d.assign(n, -1);
	q.clear();
	sons.assign(n, {});
	DFS(root);

	ll res = 0;
	for (auto v : q)
		res += worker(v);

	res %= mod;
	return res;
}

void d2(ll &val) {
	if (val & 1)
		val += mod;
	val /= 2;
}

vector<ll> f, fi;
ll C(int n, int k) {
	if (n < 0 || k < 0 || n < k)
		return 0;
	ll res = f[n];
	res *= fi[k];
	res %= mod;
	res *= fi[n - k];
	res %= mod;
	return res;
}

void prepare() {
	f.push_back(1);
	for (int i = 1; i <= 600; i++)
		f.push_back(f.back() * i), f.back() %= mod;
	for (auto val : f)
		fi.push_back(inv(val));

	int vars = 1;
	for (int sum = 1; sum <= 2 * n; sum++) {
		for (int j = 1; j <= sum; j++) {
			int i = sum - j;
			ans[i][j] = ans[i + 1][j - 1];
			ll loc = C(i + j - 1, i);
			loc *= inv(vars);
			ans[i][j] += loc;
			ans[i][j] %= mod;
		}
		vars *= 2;
		vars %= mod;
	}
}

void solve() {
	cin >> n;
	prepare();
	e.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += work(i);
	ans %= mod;
	ans *= inv(n);
	ans %= mod;
	cout << ans << '\n';
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
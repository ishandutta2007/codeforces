#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 998244353;
const int maxn = 1e5 + 42;

int add(int a, int b) {
	return (a + b) % mod;
}
int mul(int a, int b) {
	return a * b % mod;
}
int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2)  : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

void prepr(vector<int> *g, int *in, int *out, int &t, int v = 0) {
	in[v] = t++;
	for(auto u: g[v]) {
		prepr(g, in, out, t, u);
	}
	out[in[v]] = t;
}

void solve() {
	int n;
	cin >> n;
	int a[n], b[n];
	vector<int> g1[n], g2[n];
	for(int i = 1; i < n; i++) {
		cin >> a[i];
		a[i]--;
		g1[a[i]].push_back(i);
	}
	for(int i = 1; i < n; i++) {
		cin >> b[i];
		b[i]--;
		g2[b[i]].push_back(i);
	}
	int in[n], out[n];
	int t = 0;
	prepr(g2, in, out, t);
	auto is_par = [&](int x, int y) {
		return x <= y && out[y] <= out[x];
	};
	set<int> st;
	int ans = 0;
	function<void(int)> dfs = [&](int v) {
		auto it = st.insert(in[v]).first;
		optional<int> rem;
		if(it != begin(st) && is_par(*prev(it), *it)) {
			rem = *prev(it);
			st.erase(prev(it));
		} else if(next(it) != end(st) && is_par(*it, *next(it))) {
			st.erase(it);
		}
		ans = max<int>(ans, st.size());
		for(auto u: g1[v]) {
			dfs(u);
		}
		st.erase(in[v]);
		if(rem) {
			st.insert(*rem);
		}
	};
	dfs(0);
	cout << ans << "\n";
}

signed main() {
	//ignore = freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
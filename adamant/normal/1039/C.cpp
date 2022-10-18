#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 1e9 + 7;

int bpow(int x, int n) {
	return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

map<pair<int, int>, int> par;
map<pair<int, int>, int> sz;
int get(int key, int v) {
	auto it = par.find({key, v});
	if(it == end(par)) {
		return par[{key, v}] = v;
	} else if(it->second != v) {
		return it->second = get(key, it->second);
	} else {
		return v;
	}
}

int get_sz(int key, int v) {
	auto it = sz.find({key, v});
	if(it == end(sz)) {
		return sz[{key, v}] = 1;
	} else {
		return it->second;
	}
}

int uni(int key, int a, int b) {
	a = get(key, a);
	b = get(key, b);
	if(a == b) {
		return 0;
	}
	if(get_sz(key, a) < get_sz(key, b)) {
		swap(a, b);
	}
	par[{key, b}] = a;
	sz[{key, a}] += sz[{key, b}];
	return 1;
}



signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int c[n];
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	map<int, int> bad_keys;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		int x = c[u] ^ c[v];
		int t = uni(x, u, v);
		bad_keys[x] += t;
	}
	int ans = 0;
	int pw1 = bpow(2, n);
	for(auto it: bad_keys) {
		ans += pw1 - bpow(2, n - it.second) + mod;
		if(ans >= mod) {
			ans -= mod;
		}
	}
	ans = bpow(2, k) * pw1 + mod - ans;
	cout << ans % mod << endl;
	return 0;
}
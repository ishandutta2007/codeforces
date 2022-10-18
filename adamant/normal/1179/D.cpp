#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int maxn = 5e5 + 42;

struct func {
	function<int(int)> inn = [&](int){return 1e16;};
};

func F[4 * maxn];

vector<int> to_clean;

void add(func f, int v = 1, int l = 0, int r = maxn) {
	to_clean.push_back(v);
    int m = (l + r) / 2;
    bool lef = f.inn(l) < F[v].inn(l);
    bool mid = f.inn(m) < F[v].inn(m);
    if(mid) {
        swap(F[v], f);
    }
    if(r - l == 1) {
        return;
    } else if(lef != mid) {
        add(f, 2 * v, l, m);
    } else {
        add(f, 2 * v + 1, m, r);
    }
}

int get(int x, int v = 1, int l = 0, int r = maxn) {
    int m = (l + r) / 2;
    if(r - l == 1) {
        return F[v].inn(x);
    } else if(x < m) {
        return min(F[v].inn(x), get(x, 2 * v, l, m));
    } else {
        return min(F[v].inn(x), get(x, 2 * v + 1, m, r));
    }
}

void clean() {
	for(auto it: to_clean) {
		F[it] = func();
	}
	to_clean.clear();
}

int n;
int sz[maxn];
vector<int> g[maxn];

void dfs1(int v, int p) {
	sz[v] = 1;
	for(auto u: g[v]) {
		if(u != p) {
			dfs1(u, v);
			sz[v] += sz[u];
		}
	}
}

int ans = 0;

int pars(int n) {
	return n * (n - 1) / 2;
}

func gen_func(int aj, int szj, int n) {
	return {[n, aj, szj](int szi){return aj + pars(n - szi - szj);}};
}

int dfs2(int v, int p, int x) {
	vector<int> tops;
	int res = 1e16;
	for(auto u: g[v]) {
		if(u != p) {
			int t = dfs2(u, v, x + pars(sz[v] - sz[u]));
			res = min(res, t);
			tops.push_back(t - x - pars(sz[v] - sz[u]));
		}
	}
	int idx = 0;
	clean();
	for(auto u: g[v]) {
		if(u != p) {
			ans = max(ans, pars(n) - tops[idx] - get(sz[u]));
			add(gen_func(tops[idx], sz[u], n));
			idx++;
		}
	}
	if(g[v].size() == 1) {
		return x;
	} else {
		return res;
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	if(n == 2) {
		cout << 2 << endl;
		return 0;
	}
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 0; i < n; i++) {
		if(g[i].size() != 1) {
			dfs1(i, i);
			dfs2(i, i, 0);
			cout << pars(n) + ans << endl;
			return 0;
		}
	}
	return 0;
}
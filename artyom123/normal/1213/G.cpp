#include <bits/stdc++.h>
 
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

struct edge{
	int u, v, w;
	edge(){}
	edge(int _u, int _v, int _w) {
		u = _u;
		v = _v;
		w = _w;
	}
	bool operator< (const edge &e) {
		return w < e.w;
	}
};

long long cur_ans = 0;

vector<int> p;
vector<long long> sz;

int get_parent(int v) {
	if (v == p[v]) return v;
	return p[v] = get_parent(p[v]);
}

void merge(int v, int u) {
	v = get_parent(v);
	u = get_parent(u);
	if (sz[v] < sz[u]) swap(v, u);
	cur_ans -= sz[v] * (sz[v] - 1) / 2;
	cur_ans -= sz[u] * (sz[u] - 1) / 2;
	sz[v] += sz[u];
	cur_ans += sz[v] * (sz[v] - 1) / 2;
	p[u] = v;
}	

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    p.resize(n);
    for (int i = 0; i < n; i++) p[i] = i;
    sz.assign(n, 1);
    vector<edge> e;
    for (int i = 0; i < n - 1; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	e.pb(u - 1, v - 1, w);
    }
    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; i++) {
    	cin >> q[i].fi;
    	q[i].se = i;
    }
    sort(all(q));
	sort(all(e));
	int i = 0;
	vector<long long> ans(m);
	for (auto &c : q) {
		while (i < n - 1 && e[i].w <= c.fi) {
			merge(e[i].u, e[i].v);
			i++;
		}
		ans[c.se] = cur_ans;
	}
	for (auto &c : ans) cout << c << " ";
    return 0;
}
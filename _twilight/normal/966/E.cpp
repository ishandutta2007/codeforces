#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5, C = 900;

#define pii pair<int, int>

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

#ifdef local
FILE* fin = fopen("holiday.in", "r");
#else
FILE* fin = stdin;
#endif

int n, m;
vector<int> g[N];
int fa[N], t[N], a[N];

inline void init() {
	fscanf(fin, "%d%d", &n, &m);
	for (int i = 2; i <= n; i++) {
		fscanf(fin, "%d", fa + i);
		g[fa[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		fscanf(fin, "%d", t + i);
	}
	for (int i = 1; i <= m; i++) {
		fscanf(fin, "%d", a + i);
	}
}

int ans;
int ans_vac;
boolean on_vac[N];
boolean v_node[N];
vector<pii> ev[N];
int bel[N], vfa[N], del[N], dem[N];

int dfs1(int p) {
	vector<int> vson;
	int &id = bel[p], _id;
	id = -1; 
	for (auto e : g[p]) {
		_id = dfs1(e);
		if (~_id) {
			vson.push_back(_id);
			id = _id;	
		}
	}
	if (vson.size() >= 2) {
		v_node[p] = true;
	}
	if (v_node[p]) {
		id = p;
		for (auto e : vson) {
			vfa[e] = p;
		}
	}
	if (~id) {
		bel[p] = id;
	}
	return id;
}

void build_tree(vector<int>& key) {
	static int cnt[N];
	static vector<pii> _v_neg, _v_pos;
	static vector<pii> v_neg, v_pos;
	for (auto e : key) {
		v_node[e] = true;
	}
	dfs1(1);
	
	v_neg.clear();
	v_pos.clear();
	ans = ans_vac = 0;
	for (int i = 1; i <= n; i++) {
		boolean flag = on_vac[i] && v_node[i];
		ans += (t[i] < 0 && (!on_vac[i] || flag));
		ans_vac += (t[i] < 0 && flag);
		if (v_node[i] || bel[i] == -1 || on_vac[i]) {
			continue;
		}
		((t[i] < 0) ? (v_neg) : (v_pos)).push_back(pii(t[i], i));
	}

	// sort pos
	_v_pos.resize(v_pos.size());
	pfill(cnt, cnt + n + 1, 0);
	for (auto& par : v_pos)
		cnt[par.first]++;
	for (int i = 1; i <= n; i++)
		cnt[i] += cnt[i - 1];
	for (auto& par : v_pos)
		_v_pos[--cnt[par.first]] = par;
	v_pos.swap(_v_pos);
	
	// sort neg
	_v_neg.resize(v_neg.size());
	pfill(cnt, cnt + n + 1, 0);
	for (auto& par : v_neg)
		cnt[-par.first]++;
	for (int i = n - 1; ~i; i--)
		cnt[i] += cnt[i + 1];
	for (auto& par : v_neg)
		_v_neg[--cnt[-par.first]] = par;
	v_neg.swap(_v_neg);

	for (auto& par : v_neg) {
		if (bel[par.second] != -1) {
			vector<pii>& vec = ev[bel[par.second]];
			if (!vec.empty() && vec.back().first == par.first) {
				vec.back().second++;
			} else {
				vec.emplace_back(par.first, 1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (v_node[i]) {
			dem[i] = ev[i].size();
		}
	}
	for (auto& par : v_pos) {
		if (bel[par.second] != -1) {
			vector<pii> &vec = ev[bel[par.second]];
			if (!vec.empty() && vec.back().first == par.first) {
				vec.back().second++;
			} else {
				vec.emplace_back(par.first, 1);
			}
		}
	}
}

void modify(int p, int v) {
	int u = p;
	do {
		int& q = dem[p];
		vector<pii>& vec = ev[p];
		ans -= (t[p] < del[p]);
		ans_vac -= (t[p] < del[p] && on_vac[p]);
		if (p == u) {
			on_vac[p] = (v > 0);
		}
		del[p] += v;
		ans += (t[p] < del[p]);
		ans_vac += (t[p] < del[p] && on_vac[p]);
		while (q < (signed) vec.size() && vec[q].first < del[p])
			ans += vec[q++].second;
		while (q && vec[q - 1].first >= del[p])
			ans -= vec[--q].second;
		p = vfa[p];
	} while (p);
}

void dfs2(int p) {
	int id = bel[p];
	if (v_node[p]) {
		ev[p].clear();
	}
	if (~id) {
		t[p] -= del[id];
	}
	for (auto e : g[p]) {
		dfs2(e);
	}
}

void push_down() {
	dfs2(1);
	pfill(del, del + n + 1, 0);
	pfill(vfa, vfa + n + 1, 0);
}

inline void solve() {
	for (int i = 1, _i; i <= m; i = _i) {
		vector<int> key;
		_i = min(m + 1, i + C);
		for (int j = i; j < _i; j++) {
			key.push_back((a[j] < 0) ? (-a[j]) : (a[j]));
		}
		build_tree(key);
//		cerr << ans << " " << ans_vac << '\n';
		for (int j = i; j < _i; j++) {
			if (a[j] < 0) {
				modify(-a[j], -1);
			} else {
				modify(a[j], 1);
			}
			printf("%d ", ans - ans_vac);
		}
		push_down();
//		cerr << ans << " " << ans_vac << '\n';
//		for (int i = 1; i <= n; i++) {
//			cerr << t[i] << ((on_vac[i]) ? ("_") : ("")) << ((v_node[i]) ? ("&") : ("")) << ' ';
//		}
//		cerr << '\n';
		pfill(v_node, v_node + n + 1, false);
	}
}

int main() {
	init();
	solve();
	return 0;
}
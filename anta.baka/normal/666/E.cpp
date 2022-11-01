#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
using ZYABL = unsigned short;
using ZYABLS = pair<ZYABL, ZYABL>;

struct Node {
	map<char, int> to;
	int mxln;
	int lk;
	Node() : to(), mxln(0), lk(-1) {}
	Node(int mxln) : to(), mxln(mxln), lk(-1) {}
	Node(const map<char, int>& to, int mxln, int lk) : to(to), mxln(mxln), lk(lk) {}
};

vector<Node> au(1);
int lst;
vector<int> who(1, -1);

int append(char ch, int id) {
	int cur = au.size();
	au.emplace_back(au[lst].mxln + 1);
	who.push_back(id);
	int pv = lst;
	for (; pv != -1 && !au[pv].to.count(ch); pv = au[pv].lk) {
		au[pv].to[ch] = cur;
	}
	if (pv == -1) {
		au[cur].lk = 0;
	}
	else {
		int nxt = au[pv].to[ch];
		if (au[nxt].mxln == au[pv].mxln + 1) {
			au[cur].lk = nxt;
		}
		else {
			int cl = au.size();
			au.emplace_back(au[nxt].to, au[pv].mxln + 1, au[nxt].lk);
			who.push_back(-1);
			au[cur].lk = au[nxt].lk = cl;
			for (; pv != -1 && au[pv].to[ch] == nxt; pv = au[pv].lk) {
				au[pv].to[ch] = cl;
			}
		}
	}
	lst = cur;
	return cur;
}

ZYABLS comb(const ZYABLS& a, const ZYABLS& b) {
	if (a.first != b.first) {
		return max(a, b);
	}
	return min(a, b);
}

struct SegTree {
	int n;
	vector<ZYABLS> t;
	SegTree(const vector<ZYABL>& ids) : n(ids.size()), t(2 * ids.size()) {
		for (int i = 0; i < n; i++) {
			t[i + n] = { 0, ids[i] + 1 };
		}
		for (int i = n - 1; i > 0; i--) {
			t[i] = comb(t[i << 1], t[i << 1 | 1]);
		}
	}
	void upd(int v, ZYABL delta) {
		t[v += n].first += delta;
		for (v >>= 1; v; v >>= 1) {
			t[v] = comb(t[v << 1], t[v << 1 | 1]);
		}
	}
	ZYABLS get(int l, int r) {
		ZYABLS ret = { 0, 55555 };
		for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
			if (l & 1) {
				ret = comb(ret, t[l]);
			}
			if (!(r & 1)) {
				ret = comb(ret, t[r]);
			}
		}
		return ret;
	}
};

#define where nowhere

int n;
string s;
vector<int> where;
int m;
vector<vector<int>> g;
const int LG = 20;
vector<vector<int>> up;
vector<vector<int>> sum;
int q;

struct ZALUPA {
	int id, l, r;
};

vector<vector<ZALUPA>> qs;

void dfs(int v) {
	up[v][0] = max(0, au[v].lk);
	sum[v][0] = (au[v].lk != -1 ? au[v].mxln - au[au[v].lk].mxln : 0);
	for (int i = 1; i < LG; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
		sum[v][i] = sum[v][i - 1] + sum[up[v][i - 1]][i - 1];
	}
	for (int to : g[v]) {
		dfs(to);
	}
}

vector<int> lk;
vector<set<ZYABL>> setik;

void dfs1(int v) {
	int kid = -1;
	for (int to : g[v]) {
		dfs1(to);
		if (kid == -1 || setik[lk[kid]].size() < setik[lk[to]].size()) {
			kid = to;
		}
	}
	if (kid == -1) {
		lk[v] = v;
	}
	else {
		lk[v] = lk[kid];
	}
	if (who[v] != -1) {
		setik[lk[v]].insert(who[v]);
	}
	for (int to : g[v]) {
		if (to != kid) {
			for (ZYABL x : setik[lk[to]]) {
				setik[lk[v]].insert(x);
			}
		}
	}
}

vector<vector<ZYABL>> sbt;
vector<SegTree> t;
vector<pair<int, int>> ans;

void add(ZYABL wut, ZYABL cnt, const vector<ZYABL>& me, SegTree& t) {
	int pos = lower_bound(me.begin(), me.end(), wut) - me.begin();
	t.upd(pos, cnt);
}

void dfs2(int v) {
	for (int to : g[v]) {
		dfs2(to);
	}
	if (who[v] != -1) {
		add(who[v], 1, sbt[lk[v]], t[lk[v]]);
	}
	for (int to : g[v]) {
		if (lk[to] != lk[v]) {
			for (int i = 0; i < sbt[lk[to]].size(); i++) {
				add(sbt[lk[to]][i], t[lk[to]].get(i, i).first, sbt[lk[v]], t[lk[v]]);
			}
		}
	}
	for (auto q : qs[v]) {
		int L = lower_bound(sbt[lk[v]].begin(), sbt[lk[v]].end(), q.l) - sbt[lk[v]].begin();
		int R = upper_bound(sbt[lk[v]].begin(), sbt[lk[v]].end(), q.r) - sbt[lk[v]].begin() - 1;
		if (L > R) {
			ans[q.id] = { q.l + 1, 0 };
		}
		else {
			auto kek = t[lk[v]].get(L, R);
			if (kek.first == 0) {
				kek.second = q.l + 1;
			}
			ans[q.id] = { kek.second, kek.first };
		}
	}
}

const int PODKEK = 2200228;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> m;
	int n = s.size();
	where.resize(n);
	au.reserve(PODKEK);
	who.reserve(PODKEK);
	for (int i = 0; i < n; i++) {
		where[i] = append(s[i], -1);
	}
	append('#', -1);
	for (int i = 0; i < m; i++) {
		string t;
		cin >> t;
		for (auto c : t) {
			append(c, i);
		}
		append('#', -1);
	}
	g.resize(au.size());
	for (int i = 1; i < au.size(); i++) {
		g[au[i].lk].push_back(i);
	}
	up.resize(g.size(), vector<int>(LG));
	sum.resize(g.size(), vector<int>(LG));
	dfs(0);
	au.shrink_to_fit();
	qs.resize(au.size());
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r, pl, pr;
		cin >> l >> r >> pl >> pr;
		--l; --r; --pl; --pr;
		int u = where[pr];
		int rem = pl;
		for (int i = LG - 1; i >= 0; i--) {
			if (rem >= sum[u][i]) {
				rem -= sum[u][i];
				u = up[u][i];
			}
		}
		qs[u].push_back({ i, l, r });
	}
	up.shrink_to_fit();
	sum.shrink_to_fit();
	lk.resize(au.size());
	setik.resize(au.size());
	dfs1(0);
	sbt.reserve(PODKEK);
	t.reserve(PODKEK);
	for (int u = 0; u < au.size(); u++) {
		sbt.emplace_back(setik[u].begin(), setik[u].end());
		t.emplace_back(sbt.back());
	}
	setik.shrink_to_fit();
	ans.resize(q);
	dfs2(0);
	for (int i = 0; i < q; i++) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef unordered_map <int, int> umap;

const int MAXN = 1.5e5 + 5;
const int LOG = 19;

struct Change {
	int who, prv, curr;
};

class Fenwick {
	int tot;
	int f[MAXN];
	public:
		Fenwick() {
			memset(f, 0, sizeof f);
			tot = 0;
		}
		void update(int x, int val) {
			tot += val;
			for (x++; x < MAXN; x += x & -x)
				f[x] += val;
		}
		int get(int x) const {
			int res = tot;
			for (x++; x; x -= x & -x)
				res -= f[x];
			return res;
		}
};

class UnionFind {
	vector <int> idx;
	vector <vector <int>> comp;
	stack <pair <int, Change>> ch;
	public:
		vector <int> dad;
		vector <umap> cnt;
		UnionFind(int n, vector <int> _idx) {
			idx = _idx;
			dad.resize(n);
			comp.resize(n);
			cnt.resize(n);
			for (int i = 0; i < n; i++) {
				comp[i].push_back(i);
				dad[i] = i;
			}
		}
		vector <Change> revert(int lvl) {
			vector <Change> res;
			for (; !ch.empty() && ch.top().first < lvl; ch.pop()) {
				Change tmp = ch.top().second;
				dad[tmp.who] = tmp.prv;
				tmp.who = idx[tmp.who];
				res.push_back(tmp);
			}
			return res;
		}
		void modify(int lvl, int who, int val) {
			ch.push({lvl, {who, dad[who], val}});
			dad[who] = val;
		}
		ll join(int x, int y, int lvl) {
			x = dad[x];
			y = dad[y];
			if (comp[x].size() > comp[y].size())
				swap(x, y);
			ll res = 0;
			for (auto it : cnt[x]) {
				int &ref = cnt[y][it.first];
				res += (ll)it.second * ref;
				ref += it.second;
			}
			for (auto it : comp[x]) {
				comp[y].push_back(it);
				modify(lvl, it, y);
			}
			return res;
		}
		ll sweep(const vector <int> &v, UnionFind &other, int k) {
			int n = v.size() + 1;
			vector <pii> events;
			for (int i = 0; i < n - 1; i++)
				events.push_back({v[i], i});
			sort(events.begin(), events.end(), greater <pii> ());
			ll res = 0;
			for (auto it : events) {
				if (k) {
					vector <Change> tmp = other.revert(k - it.first);
					for (auto it : tmp) {
						cnt[dad[it.who]][it.curr]--;
						cnt[dad[it.who]][it.prv]++;
					}
				}
				res += join(it.second, it.second + 1, it.first);
			}
			return res;
		}
};

int N, M, K;
int pos[MAXN];
int s[MAXN], t[MAXN], l[MAXN];
int downLft[MAXN], downRig[MAXN];
vector <int> adj[MAXN];
vector <int> toDo[MAXN];
vector <int> toAdd[MAXN], queries[MAXN];
int disc[MAXN], dep[MAXN];
int anc[MAXN][LOG];
Fenwick byDepth;
int timer;

void load() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < M; i++)
		scanf("%d%d", s + i, t + i);
}

void dfs(int x, int p) {
	anc[x][0] = p;
	disc[x] = timer++;
	for (auto it : adj[x])
		if (it != p) {
			dep[it] = dep[x] + 1;
			dfs(it, x);
		}	
}

int jmp(int x, int k) {
	if (k < 0)
		return 0;
	for (int i = 0; i < LOG; i++)
		if (k >> i & 1)
			x = anc[x][i];
	return x;
}

int lca(int x, int y) {
	if (dep[x] < dep[y])
		swap(x, y);
	x = jmp(x, dep[x] - dep[y]);
	if (x == y)
		return x;
	for (int i = LOG - 1; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	return anc[x][0];
}

ll same_lca() {
	ll res = 0;
	for (int i = 1; i <= N; i++) {
		if (toDo[i].size() <= 1)
			continue;
		vector <pii> st, en;
		umap specLft, specRig;
		for (auto it : toDo[i]) {
			st.push_back({disc[s[it]], it});		
			en.push_back({disc[t[it]], it});
			if (downLft[it])
				specRig[downLft[it]]++;
			if (downRig[it])
				specLft[downRig[it]]++;
		}
		sort(st.begin(), st.end());
		sort(en.begin(), en.end());
		vector <int> lft, rig, perm;
		for (int j = 0; j < st.size(); j++) {
			pos[st[j].second] = j;
			if (j)
				lft.push_back(dep[lca(s[st[j - 1].second], s[st[j].second])] - dep[i]);
		}
		for (int j = 0; j < en.size(); j++) {
			perm.push_back(pos[en[j].second]);
			if (j) 
				rig.push_back(dep[lca(t[en[j - 1].second], t[en[j].second])] - dep[i]);
		}
		int n = perm.size();
		UnionFind L(n, {});
		UnionFind R(n, perm);
		R.sweep(rig, L, 0);
		for (int j = 0; j < n; j++)
			L.cnt[perm[j]][R.dad[j]]++;
		res += L.sweep(lft, R, K);
		for (auto it : specLft)
			res += (ll)it.second * specRig[it.first];
	}
	
	return res;
}

ll different_lca(int x, int p) {
	for (auto it : toAdd[x])
		byDepth.update(dep[it], 1);
	ll res = 0;
	for (auto it : queries[x])
		res += byDepth.get(dep[it]);
	for (auto it : adj[x])
		if (it != p)
			res += different_lca(it, x);
	for (auto it : toAdd[x])
		byDepth.update(dep[it], -1);
	return res;
}

void calc_down(int x, int node, int &ref) {
	queries[node].push_back(l[x]);
	int len = dep[node] - dep[l[x]];
	ref = jmp(node, len - K);
	toAdd[ref].push_back(l[x]);
}

ll solve() {
	dfs(1, 0);
	
	for (int j = 1; j < LOG; j++)
		for (int i = 1; i <= N; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
			
	for (int i = 0; i < M; i++) {
		if (disc[s[i]] > disc[t[i]])
			swap(s[i], t[i]);
		l[i] = lca(s[i], t[i]);
		toDo[l[i]].push_back(i);
		calc_down(i, s[i], downLft[i]);
		calc_down(i, t[i], downRig[i]);
	}
	
	return same_lca() + different_lca(1, 0);
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;

int N;
vector <int> adj[MAXN];
vector <pii> ch[MAXN];
int mx1[MAXN], mx2[MAXN];
int up[MAXN];
int ans[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int dfs_down(int x, int p) {
	for (auto it : adj[x])
		if (it != p) {
			int tmp = dfs_down(it, x) + 1;
			ch[x].push_back({it, tmp});
			if (tmp >= mx1[x]) {
				mx2[x] = mx1[x];
				mx1[x] = tmp;
			}
			else if (tmp > mx2[x])
				mx2[x] = tmp;
		}
	return mx1[x];
}

void dfs_up(int x) {
	for (auto it : ch[x]) {
		up[it.first] = max(up[x], it.second == mx1[x] ? mx2[x] : mx1[x]) + 1;
		dfs_up(it.first);
	}
}

inline void update(int x, int val) {
	if (x <= N && val > 1 && val > ans[x])
		ans[x] = val;
}

void dfs_calc(int x, int above, const vector <pii> &par) {
	map <int, int> tmp;
	tmp[0]++;
	tmp[up[x]]++;
	for (auto it : ch[x])
		tmp[it.second]++;
	
	vector <pii> imp;
	for (auto it = tmp.rbegin(); it != tmp.rend(); it++)
		imp.push_back(*it);
		
	int geq = 0;
	for (auto it : imp) {
		geq += it.second;
		update(2 * it.first, geq);
		update(2 * it.first - 1, geq);
		update(2 * it.first + 1, geq - it.second + 1);
	}
	
	for (auto it : ch[x])
		dfs_calc(it.first, it.second, imp);
	
	vector <pii> nxt(imp.size() + par.size());
	merge(imp.begin(), imp.end(), par.begin(), par.end(), nxt.begin(), greater <pii> ());
	imp.clear();
	for (int i = 0; i < nxt.size(); i++)
		if (i < (int)nxt.size() - 1 && nxt[i].first == nxt[i + 1].first) {
			imp.push_back({nxt[i].first, nxt[i].second + nxt[i + 1].second});
			i++;
		}
		else
			imp.push_back(nxt[i]);
	
	geq = 0;
	for (auto it : imp) {
		geq += it.second;
		update(2 * it.first, geq - (above >= it.first) - (up[x] >= it.first));
	}
}

void solve() {
	dfs_down(1, 0);
	dfs_up(1);
	dfs_calc(1, 0, {});
	
	for (int i = N; i; i--)
		ans[i] = max(ans[i], ans[i + 2]);
	
	for (int i = 1; i <= N; i++)
		printf("%d ", max(ans[i], 1));
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}
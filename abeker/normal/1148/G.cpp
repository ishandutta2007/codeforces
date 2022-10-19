#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int MAXV = 1e7 + 5;
const int LOG = 17;

int N, K;
int a[MAXN];
int f[MAXN];
bool bio[MAXN];
vector <int> ch[MAXN];
int prime[MAXV], cnt[MAXV];
vector <pii> divs[MAXN];
vector <int> adj[MAXN];
int lo[MAXN][2], mid[MAXN][2], hi[MAXN][2];
pii two[MAXV];
int rad[MAXN];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

void precompute() {
	for (int i = 2; i < MAXV; i++)
		if (!prime[i])
			for (int j = i; j < MAXV; j += i)
				if (!prime[j])
					prime[j] = i;
}

void find_coprime() {
	vector <int> imp;
	for (int i = 1; i <= N; i++) {
		rad[i] = 1;
		vector <int> factors;
		for (int x = a[i]; x > 1; ) {
			int tmp = prime[x];
			rad[i] *= tmp;
			while (!(x % tmp))
				x /= tmp;
			factors.push_back(tmp);
		}
		if (!two[rad[i]].first) {
			int sz = factors.size();
			for (int j = 0; j < 1 << sz; j++) {
				int prod = 1;
				for (int k = 0; k < sz; k++)
					if (j >> k & 1)
						prod *= factors[k];
				divs[imp.size()].push_back({prod, __builtin_popcount(j) & 1});
			}
			imp.push_back(i);
			two[rad[i]].first = imp.size();
		}
		else if (!two[rad[i]].second)
			two[rad[i]].second = i;
	}
	
	int sz = imp.size();
	for (int i = 0; i < sz; i++)
		hi[i][0] = hi[i][1] = sz;
	
	for (int k = 0; k < LOG; k++) {
		vector <vector <pii>> queries(sz + 1);
		for (int i = 0; i < sz; i++) 
			for (int j = 0; j < 2; j++) { 
				mid[i][j] = (lo[i][j] + hi[i][j]) / 2;
				queries[mid[i][j]].push_back({i, j});
			}
		for (int i = 0; i < sz; i++) {
			for (auto it : divs[i])
				cnt[it.first]++;
			for (auto it : queries[i]) {
				int coprime = 0;
				for (auto d : divs[it.first])
					coprime += d.second ? -cnt[d.first] : cnt[d.first];
				if (coprime >= it.second + 1)
					hi[it.first][it.second] = i;
				else
					lo[it.first][it.second] = i + 1;
			}
		}
		for (int i = 0; i < sz; i++)
			for (auto it : divs[i])
				cnt[it.first]--;
	}
	
	for (int i = 1; i <= N; i++) 
		for (int j = 0; j < 2; j++) {
			int pos = lo[two[rad[i]].first - 1][j];
			if (pos >= sz)
				continue;
			if (adj[i].size() < 2)
				adj[i].push_back(imp[pos]);
			if (two[rad[imp[pos]]].second && adj[i].size() < 2)
				adj[i].push_back(two[rad[imp[pos]]].second);
		}
}

void output() {
	for (int i = 1; i <= N; i++) {
		printf("%d: ", i);
		for (auto it : adj[i])
			printf("%d ", it);
		puts("");
	}
}

void finish(vector <int> v) {
	assert(v.size() >= K);
	v.resize(K);
	for (auto it : v)
		printf("%d ", it);
	puts("");
	exit(0);
}

void indep_set() {
	vector <int> ans;
	vector <bool> used(N + 1, false);
	for (int i = 1; i <= N; i++)
		if (!used[i]) {
			ans.push_back(i);
			for (auto it : adj[i])
				used[it] = true;
		}
	finish(ans);
}

void dfs(int x, vector <int> &v) {
	bio[x] = true;
	v.push_back(x);
	for (auto it : ch[x])
		dfs(it, v);
}

vector <int> find_comp(int x) {
	while (1) {
		bio[x] = true;
		if (bio[f[x]]) {
			for (int i = 0; i < ch[f[x]].size(); i++)
				if (ch[f[x]][i] == x) {
					ch[f[x]].erase(ch[f[x]].begin() + i);
					break;
				}
			vector <int> res;
			dfs(x, res);
			return res;
		}
		x = f[x];
	}
}

void functional_graph() {
	for (int i = 1; i <= N; i++)
		ch[f[i]].push_back(i);
		
	vector <vector <int>> comps;
	for (int i = 1; i <= N; i++)
		if (f[i] && !bio[i])
			comps.push_back(find_comp(i));
	
	int sz = comps.size();
	vector <int> lim(sz, 2);
	lim[0] += K % 2;
	for (int i = 0; i < sz; i++)
		if (comps[i].size() >= 3) {
			swap(comps[i], comps[0]);
			break;
		}
	
	assert(comps[0].size() >= 3);
	
	vector <int> ans;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < lim[i]; j++)
			ans.push_back(comps[i][j]);
	for (int i = 0; i < sz; i++)
		for (int j = lim[i]; j < comps[i].size(); j++)
			ans.push_back(comps[i][j]);
	
	finish(ans);
}

void solve() {
	precompute();
	find_coprime();
	
	int large = 0;
	vector <int> iso;
	for (int i = 1; i <= N; i++)
		if (adj[i].empty())
			iso.push_back(i);
		else if (adj[i].size() > 1)
			large = i;
		
	if (iso.size() >= K)
		finish(iso);
	if (!large)
		indep_set();
		
	int neigh = adj[large][0];
	f[large] = adj[large][1];
	f[neigh] = large;
	for (int i = 1; i <= N; i++)
		if (!adj[i].empty() && i != large && i != neigh)
			f[i] = adj[i][0];
	
	functional_graph();
}

int main() {
	load();
	solve();
	return 0;
}
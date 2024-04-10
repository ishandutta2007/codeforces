#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;

int N, M, Q;
vector <int> E[MAXN];
bool bio[MAXN];
int comp[MAXN];
vector < vector <int> > paths;
vector < vector <ll> > suff;
int dp_down[MAXN], dp_up[MAXN];
multiset <int> S[MAXN];
vector <int> curr;
map <pii, double> memo;

void load() {
	scanf("%d%d%d", &N, &M, &Q);
	while (M--) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
}

void dfs_down(int x, int p) {
	bio[x] = true;
	comp[x] = paths.size();
	for (auto it : E[x])
		if (it != p) {
			dfs_down(it, x);
			S[x].insert(dp_down[it] + 1);
		}
	if (!S[x].empty())
		dp_down[x] = *S[x].rbegin();
}

void dfs_up(int x, int p) {
	if (p) {
		S[p].erase(S[p].find(dp_down[x] + 1));
		dp_up[x] = max(dp_up[p], S[p].empty() ? 0 : *S[p].rbegin()) + 1;
		S[p].insert(dp_down[x] + 1);
	}
	curr.push_back(max(dp_up[x], dp_down[x]));
	for (auto it : E[x])
		if (it != p)
			dfs_up(it, x);
}

double query(int u, int v) {
	u = comp[u];
	v = comp[v];
	if (u == v)
		return -1;
	if (paths[u].size() > paths[v].size())
		swap(u, v);
	double &ref = memo[{min(u, v), max(u, v)}];
	if (ref > 0)
		return ref; 
	int diam = max(paths[u].back(), paths[v].back());
	ll res = 0;
	for (auto it : paths[u]) {
		int pos = lower_bound(paths[v].begin(), paths[v].end(), diam - it) - paths[v].begin();
		res += (ll)pos * diam + (ll)(paths[v].size() - pos) * (it + 1) + suff[v][pos];
	}
	return ref = (double)res / ((double)paths[u].size() * paths[v].size());
}

void solve() {
	for (int i = 1; i <= N; i++)
		if (!bio[i]) {
			curr.clear();
			dfs_down(i, 0);
			dfs_up(i, 0);
			sort(curr.begin(), curr.end());
			paths.push_back(curr);
			vector <ll> tmp(curr.size() + 1);
			for (int i = (int)curr.size() - 1; i >= 0; i--)
				tmp[i] = tmp[i + 1] + curr[i];
			suff.push_back(tmp);
		}
	
	while (Q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%.10lf\n", query(u, v)); 
	}
}

int main() {
	load();
	solve();
	return 0;
}
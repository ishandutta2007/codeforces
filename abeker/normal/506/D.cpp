#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;
const int SQRT = 405;

int N, M, Q;
vector <int> adj[MAXN];
vector <pii> edges[MAXN];
vector <int> tmp, comp;
map <pii, int> cnt;
bool is[MAXN][SQRT];
bool bio[MAXN];
int sz;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edges[c].push_back({a, b});
	}
}

void add_edge(int a, int b) {
	adj[a].push_back(b);
	adj[b].push_back(a);
	bio[a] = bio[b] = false;
	tmp.push_back(a);
	tmp.push_back(b);
}

void dfs(int x) {
	bio[x] = true;
	comp.push_back(x);
	for (int it : adj[x])
		if (!bio[it])
			dfs(it);
}

void update_large() {
	for (int it : comp)
		is[it][sz] = true;
	sz++;
}

void update_small() {
	sort(comp.begin(), comp.end());
	for (int i = 0; i < comp.size(); i++)
		for (int j = i + 1; j < comp.size(); j++) 
			cnt[{comp[i], comp[j]}]++;
}

int solve() {
	for (int i = 1; i <= M; i++) {
		for (int it : tmp)
			adj[it].clear();
		tmp.clear();
		for (auto it : edges[i]) 
			add_edge(it.first, it.second);
		for (int it : tmp)
			if (!bio[it]) {
				comp.clear();
				dfs(it);
				if (comp.size() > SQRT)
					update_large();
				else
					update_small();
			}
	}
	
	scanf("%d", &Q);
	while (Q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (u > v)
			swap(u, v);
		int sol = cnt[{u, v}];
		for (int i = 0; i < sz; i++)
			sol += is[u][i] && is[v][i];
		printf("%d\n", sol);
	}
}

int main() {
	load(); 
	solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;

int N, M;
vector <int> adj[MAXN];
map <pii, int> idx;
unordered_set <int> all;
int deg[MAXN];
bool bio[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= 3 * N; i++) {
		bio[i] = false;
		adj[i].clear();
	}
	for (int i = 1; i <= M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		idx[{u, v}] = idx[{v, u}] = i;
	}
}

void remove(int x) {
	all.erase(x);
	for (auto it : adj[x]) {
		deg[it]--;
		if (!deg[it])
			all.erase(it);
	}
}

void finish() {
	puts("IndSet");
	vector <int> ans;
	for (int j = 1; j <= 3 * N; j++)
		if (!bio[j])
			ans.push_back(j);
	for (int j = 0; j < N; j++)
		printf("%d ", ans[j]);
	puts("");
}

void solve() {
	all.clear();
	for (int i = 1; i <= 3 * N; i++) {
		deg[i] = adj[i].size();
		if (deg[i])
			all.insert(i);
	}
	
	vector <int> matching;
	for (int i = 0; i < N; i++) {
		if (all.empty()) {
			finish();
			return;
		}
		int node = *all.begin();
		int neigh = 0;
		for (auto it : adj[node])
			if (!bio[it]) {
				neigh = it;
				break;
			}
		matching.push_back(idx[{node, neigh}]);
		bio[node] = bio[neigh] = true;
		remove(node);
		remove(neigh);
	}
	
	puts("Matching");
	for (int i = 0; i < N; i++)
		printf("%d ", matching[i]);
	puts("");
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}
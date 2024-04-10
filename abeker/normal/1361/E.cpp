#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 5;
const int ITER = 100;

int N, M;
vector <int> ch[MAXN];
vector <int> adj[MAXN];
int bio[MAXN], disc[MAXN];
int mn1[MAXN], mn2[MAXN];
vector <int> ans;
int timer;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		adj[i].clear();
	while (M--) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
}

void update(int x, int y) {
	if (disc[y] <= disc[mn1[x]]) {
		mn2[x] = mn1[x];
		mn1[x] = y;
	}
	else if (disc[y] < disc[mn2[x]])
		mn2[x] = y;
}

bool dfs(int x) {
	bio[x] = 1;
	disc[x] = timer++;
	for (auto it : adj[x])
		if (bio[it] == 2)
			return false;
		else if (bio[it] == 1) 
			update(x, it);
		else {
			if (!dfs(it))
				return false;
			update(x, mn1[it]);
			update(x, mn2[it]);
		}
	bio[x] = 2;
	return true;
}

void go(int x) {
	ans.push_back(x);
	for (auto it : ch[x])
		go(it);
}

bool check(int root) {
	timer = 0;
	disc[0] = MAXN;
	ans.clear();
	for (int i = 1; i <= N; i++) {
		ch[i].clear();
		mn1[i] = mn2[i] = 0;
		bio[i] = 0;
	}
	if (!dfs(root))
		return false;
	for (int i = 1; i <= N; i++) {
		if (i == root)
			continue;
		assert(disc[mn1[i]] < disc[i]);
		if (disc[mn2[i]] >= disc[i])
			ch[mn1[i]].push_back(i);
	}
	go(root);
	if (5 * ans.size() < N) {
		puts("-1");
		return true;
	}
	sort(ans.begin(), ans.end());
	for (auto it : ans)
		printf("%d ", it);
	puts("");
	return true;
}

void solve() {
	for (int i = 0; i < ITER; i++)
		if (check(uniform_int_distribution <int> (1, N)(rng)))
			return;
	puts("-1");
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
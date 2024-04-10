#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e2 + 5;
const int INF = 1e9;

int N;
int a[MAXN];
int edge[MAXN][MAXN];
vector <int> adj[MAXN], fin[MAXN];
vector < vector <int> > ans;
vector <int> comp;
bool bio[MAXN];
int cnt[MAXN];
int flow;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

bool prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (!(x % i))
			return false;
	return true;
}

void add(int x, int y) {
	adj[x].push_back(y);
	adj[y].push_back(x);
	if (a[x] % 2)
		swap(x, y);
	edge[x][y] = 1;
}

int dfs(int x, int cap) {
	if (cap <= 0)
		return 0;
	bio[x] = true;
	if (x == N + 1) {
		flow += cap;
		return cap;
	}
	for (auto it : adj[x])
		if (!bio[it]) {
			int tmp = dfs(it, min(cap, edge[x][it]));
			if (tmp > 0) {
				edge[x][it] -= tmp;
				edge[it][x] += tmp;
				return tmp;
			}
		}
	return 0;
}

void go(int x) {
	bio[x] = true;
	comp.push_back(x);
	for (auto it : fin[x])
		if (!bio[it])
			go(it);
}

bool check(const vector <int> &v) {
	if (v.size() < 3)
		return false;
	for (int i = 0; i < v.size(); i++) {
		if (!prime(a[v[i]] + a[v[(i + 1) % v.size()]]))
			return false;
		cnt[v[i]]++;
	}
	return true;
}

void solve() {
	for (int i = 1; i <= N; i++) {
		adj[0].push_back(i);
		adj[i].push_back(N + 1);
		if (a[i] % 2) 
			edge[i][N + 1] = 2;
		else
			edge[0][i] = 2;
	}
	
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
			if (prime(a[i] + a[j])) 
				add(i, j);
				
	do 
		memset(bio, false, sizeof bio);
	while (dfs(0, INF));

	if (flow != N) {
		puts("Impossible");
		return;
	}
	
	for (int i = 1; i <= N; i++)
		if (!(a[i] % 2))
			for (auto it : adj[i])
				if (it >= 1 && it <= N && !edge[i][it]) {
					fin[i].push_back(it);
					fin[it].push_back(i);
				}
	
	memset(bio, false, sizeof bio);
	for (int i = 1; i <= N; i++)
		if (!bio[i]) {
			comp.clear();
			go(i);
			ans.push_back(comp);
		}
	
	printf("%d\n", ans.size());
	for (auto cyc : ans) {
		assert(check(cyc));
		printf("%d", cyc.size());
		for (auto it : cyc)
			printf(" %d", it);
		puts("");
	}
	
	for (int i = 1; i <= N; i++)
		assert(cnt[i] == 1);
}

int main() {
	load();
	solve();
	return 0;
}
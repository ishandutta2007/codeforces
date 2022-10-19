#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;
const int offset = 1 << 19;
const int INF = 0x3f3f3f3f;

int N, K, M;
int a[MAXN], b[MAXN];
int u[MAXN], v[MAXN], w[MAXN];
int dad[MAXN], rnk[MAXN];
vector <int> adj[MAXN];
int disc[MAXN], fin[MAXN];
vector <int> lft[MAXN], rig[MAXN];
int tour[2 * offset];
vector <pii> Q[MAXN];
int ans[MAXN];
int timer;

void load() {
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 0; i < K; i++)
		scanf("%d%d", a + i, b + i);
	for (int i = 0; i < M; i++)
		scanf("%d%d%d", u + i, v + i, w + i);
}

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

bool join(int x, int y) {
	int dx = find(x);
	int dy = find(y);
	if (dx == dy)
		return false;
	if (rnk[dx] > rnk[dy])
		swap(dx, dy);
	dad[dx] = dy;
	rnk[dy] += rnk[dx] == rnk[dy];
	adj[x].push_back(y);
	adj[y].push_back(x);
	return true;
}

void dfs(int x, int p) {
	disc[x] = timer++;
	for (auto it : adj[x])
		if (it != p)
			dfs(it, x);
	fin[x] = timer;
}

void update(int x, int val) {
	x += offset;
	tour[x] = min(tour[x], val);
	for (x /= 2; x; x /= 2)
		tour[x] = min(tour[2 * x], tour[2 * x + 1]);
}

int query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from)
		return INF;
	if (lo >= from && hi <= to)
		return tour[x];
	int mid = (lo + hi) / 2;
	return min(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

int query(int from, int to) {
	return query(1, 0, offset, from, to);
}

ll solve() {
	for (int i = 1; i <= N; i++)
		dad[i] = i;
	
	for (int i = 0; i < K; i++)
		join(a[i], b[i]);
	
	vector <int> rest;
	for (int i = 0; i < M; i++)
		if (!join(u[i], v[i])) 
			rest.push_back(i);
	
	dfs(a[0], 0);
	
	for (auto it : rest) {
		Q[disc[u[it]]].push_back({v[it], w[it]});
		Q[disc[v[it]]].push_back({u[it], w[it]});
	}
	
	for (int i = 0; i < K; i++) {
		if (disc[a[i]] < disc[b[i]])
			swap(a[i], b[i]);
		lft[disc[a[i]]].push_back(i);
		rig[fin[a[i]]].push_back(i);
	}
	
	memset(tour, INF, sizeof tour);
	memset(ans, INF, sizeof ans);
	
	for (int i = 0; i < N; i++) {
		for (auto it : lft[i]) 
			ans[it] = min(ans[it], query(disc[a[it]], fin[a[it]]));
		for (auto it : Q[i])
			update(disc[it.first], it.second);
	}
	
	memset(tour, INF, sizeof tour);
	
	for (int i = N - 1; i >= 0; i--) {
		for (auto it : Q[i])
			update(disc[it.first], it.second);
		for (auto it : rig[i])
			ans[it] = min(ans[it], query(disc[a[it]], fin[a[it]]));
	}
	
	ll sol = 0;
	for (int i = 0; i < K; i++) {
		if (ans[i] == INF)
			return -1;
		sol += ans[i];
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}
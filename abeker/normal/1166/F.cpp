#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int MAXBIG = 6e3;
const int DEG = 35;

struct edge {
	int u, v, clr;
};

int N, M, C, Q;
char cmd[MAXN];
int deg[MAXN], idx[MAXN];
vector <edge> roads;
vector <pii> queries;
int dad[MAXN], rnk[MAXN];
bitset <MAXBIG> has[MAXN];
unordered_map <int, int> who[MAXN];
vector <int> adj[MAXN];

void add_road(int x, int y, int z) {
	roads.push_back({x, y, z});
	deg[x]++;
	deg[y]++;	
}

void load() {
	scanf("%d%d%d%d", &N, &M, &C, &Q);
	for (int i = 0; i < M; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add_road(x, y, z);
	}
	for (int i = 0; i < Q; i++) {
		int x, y, z;
		scanf(" %c%d%d", cmd + i, &x, &y);
		if (cmd[i] == '+') {
			scanf("%d", &z);
			add_road(x, y, z);
		}
		else
			queries.push_back({x, y});		
	}
}

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (rnk[x] > rnk[y])
		swap(x, y);
	dad[x] = y;
	rnk[y] += rnk[x] == rnk[y];
	has[y] |= has[x];
}

void merge(int x, int y, int c) {
	for (int i = 0; i < 2; i++) {
		adj[x].push_back(y);
		if (deg[y] > DEG)
			has[find(x)].set(idx[y]);
		int &ref = who[x][c];
		if (ref)
			join(ref, y);
		else
			ref = y;
		swap(x, y);
	}
}

void advance() {
	merge(roads.back().u, roads.back().v, roads.back().clr);
	roads.pop_back();
}

bool query(int x, int y) {
	int comp = find(x);
	if (find(y) == comp)
		return true;
	if (deg[y] > DEG)
		return has[comp].test(idx[y]);
	for (auto it : adj[y])
		if (find(it) == comp)
			return true;
	return false;
}

void solve() {
	reverse(roads.begin(), roads.end());
	reverse(queries.begin(), queries.end());
	
	int ptr = 0;
	for (int i = 1; i <= N; i++) {
		dad[i] = i;
		if (deg[i] > DEG) {
			idx[i] = ptr++;
			has[i].set(idx[i]);
		}
	}
	
	while (M--) 
		advance();
	
	for (int i = 0; i < Q; i++)
		if (cmd[i] == '?') {
			puts(query(queries.back().first, queries.back().second) ? "Yes" : "No");
			queries.pop_back();
		}
		else 
			advance();
}

int main() {
	load();
	solve();
	return 0;
}
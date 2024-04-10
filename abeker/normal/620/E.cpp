#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 400005;
const int offset = 1 << 19;

int N, M;
int color[MAXN];
vector <int> E[MAXN];
int disc[MAXN], fin[MAXN];
int timer = 1;
ll t[2 * offset];
int lazy[2 * offset];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)	
		scanf("%d", color + i);
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
}

void dfs(int x, int p) {
	disc[x] = timer++;
	for (int i = 0; i < E[x].size(); i++)
		if (E[x][i] != p) dfs(E[x][i], x);
	fin[x] = timer;
}

void prop(int x) {
	if (!lazy[x]) return;
	t[x] = 1ll << lazy[x];
	if (x < offset) 
		lazy[2 * x] = lazy[2 * x + 1] = lazy[x];
	lazy[x] = 0;
}

void update(int x, int lo, int hi, int from, int to, int val) {
	prop(x);
	if (lo >= to || hi <= from) return;
	if (lo >= from && hi <= to) {
		t[x] = 1ll << val;
		if (x < offset) 
			lazy[2 * x] = lazy[2 * x + 1] = val;
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, val);
	update(2 * x + 1, mid, hi, from, to, val);
	t[x] = t[2 * x] | t[2 * x + 1];
}

ll query(int x, int lo, int hi, int from, int to) {
	prop(x);
	if (lo >= to || hi <= from) return 0;
	if (lo >= from && hi <= to) return t[x];
	int mid = (lo + hi) / 2;
	return query(2 * x, lo, mid, from, to) | query(2 * x + 1, mid, hi, from, to);	
}

void solve() {
	dfs(1, 0);
	
	for (int i = 1; i <= N; i++)
		t[disc[i] + offset] = 1ll << color[i];
	for (int i = offset - 1; i >= 0; i--) 
		t[i] = t[2 * i] | t[2 * i + 1];
		
	while (M--) {
		int t, v, c;
		scanf("%d%d", &t, &v);
		if (t == 1) {
			scanf("%d", &c);
			update(1, 0, offset, disc[v], fin[v], c);
		}
		else printf("%d\n", __builtin_popcountll(query(1, 0, offset, disc[v], fin[v])));
	}
}

int main() {
	load();
	solve();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define x first
#define y second

const int N = 500005;

int n, m, q;
int p[N];
ii edge[N], que[N];
bool erased[N];
int par[N];
int current;
vector<int> g[N];
int root_ans[N];
int tin[N], tout[N], timer = 0;
int eulerTour[N];
int it[4 * N];
int fa[N];


int root(int x) {
	return (par[x] == x ? x : par[x] = root(par[x]));
}

int merge(int x, int y) {

	x = root(x);
	y = root(y);

	if (x == y) 
		return 0;

	current++;

	g[current].push_back(x);
	g[current].push_back(y);


	par[x] = current;
	par[y] = current;
	fa[x] = current;
	fa[y] = current;

	return current;
}


void dfs(int u) {
	tin[u] = ++timer;

	for (int e : g[u]) {
		dfs(e);
	}

	tout[u] = timer;
}

void build(int k, int l, int r) {
	if (l == r) {
		it[k] = l;
		return;
	}

	int mid = (l + r) / 2;
	build(2 * k, l, mid);
	build(2 * k + 1, mid + 1, r);
	it[k] = (eulerTour[it[2 * k]] > eulerTour[it[2 * k + 1]] ? it[2 * k] : it[2 * k + 1]);
}

void update(int k, int l, int r, int id) {
	if (r < id || l > id)
		return;

	if (l == r && l == id) {
		return;
	}

	int mid = (l + r) / 2;

	update(2 * k, l, mid, id);
	update(2 * k + 1, mid + 1, r, id);

	it[k] = (eulerTour[it[2 * k]] > eulerTour[it[2 * k + 1]] ? it[2 * k] : it[2 * k + 1]);
}

int get(int k, int l, int r, int u, int v) {
	if (l > v || r < u) 
		return 0;
	if (l >= u && r <= v)
		return it[k];
	int mid = (l + r) / 2;
	int g1 = get(2 * k, l, mid, u, v);
	int g2 = get(2 * k + 1, mid + 1, r, u, v);
	return (eulerTour[g1] > eulerTour[g2] ? g1 : g2);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> q;
	current = n;

	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 1; i <= m; i++)
		cin >> edge[i].x >> edge[i].y;

	for (int i = 1; i <= q; i++) {
		cin >> que[i].x >> que[i].y;
		if (que[i].x == 2) 
			erased[que[i].y] = 1;
	}



	for (int i = 1; i <= 2 * n; i++)
		par[i] = i;


	for (int i = 1; i <= m; i++) {
		if (!erased[i])
			merge(edge[i].x, edge[i].y);
	}


	for (int i = q; i >= 1; i--) {
		if (que[i].x == 1) {
			root_ans[i] = root(que[i].y);
		} else {
			merge(edge[que[i].y].x, edge[que[i].y].y);
		}
	}

	for (int i = 1; i <= current; i++) {
		if (fa[i] == 0) dfs(i);
	}

	for (int i = 1; i <= n; i++) {
		eulerTour[tin[i]] = p[i];
	}

	build(1, 1, current);


	for (int i = 1; i <= q; i++) {
		if (que[i].x == 1) {
			int foo = root_ans[i];
			int id = get(1, 1, current, tin[foo], tout[foo]);
			cout << eulerTour[id] << '\n';
			eulerTour[id] = 0;
			update(1, 1, current, id);
		}
	}

	return 0;
}
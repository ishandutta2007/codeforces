#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

#define ll long long

const ll inf = 1e9;

int n;
vector<int> G[N];
vector<bool> ban[N];

#define pii pair<int, int>

ll f[N][2];
//vector<int> g[N][2];
vector<int> h[N][2];

void dfs(int p, int fa) {
	f[p][0] = 0, f[p][1] = -inf;
	for (auto e : G[p]) {
		if (e == fa) continue;
		dfs(e, p);
		int idf = f[p][1] > f[p][0], ide = f[e][1] > f[e][0];
		ll f1 = f[p][1];
		f[p][1] = f[p][idf] + f[e][ide];
		h[p][1].emplace_back((idf << 1 | ide) << 1);
		if (f1 + f[e][1] + 1 > f[p][1]) {
			f[p][1] = f1 + f[e][1] + 1;
			h[p][1].back() = 7;
		}

		f[p][0] = f[p][0] + f[e][1] + 1;
		h[p][0].emplace_back(3);
	}
//	cerr << p << " " << f[p][0] << " " << f[p][1] << '\n';
}

vector<int> ord;
void get_cut(int p, int idf, int fa) {
	int deg = G[p].size();	
	ban[p].resize(deg, false);
	int j = h[p][0].size();
	ord.push_back(p);
	for (int i = deg; i--; ) {
		int e = G[p][i];
		if (e == fa) {
			continue;
		}
		int dec = h[p][idf][--j];
		int nf = dec >> 2 & 1;
		int ng = dec >> 1 & 1;
		int tp = dec & 1;
		get_cut(e, ng, p);
		if (tp == 1) {
			ban[p][i] = true;
//			cerr << p << " " << e << '\n';
		}
		idf = nf;
	}
}

vector<int> tour;
bool vis[N];
int res[N];
void dfs(int p) {
	if (vis[p])
		return;
	vis[p] = true;
	tour.push_back(p);
	int deg = (signed) G[p].size();
	for (int i = 0; i < deg; i++) {
		if (!ban[p][i]) {
			dfs(G[p][i]);
		}
	}
}
void work(int p) {
	if (vis[p])
		return;
	tour.clear();
	dfs(p);
	int l = tour.size();
	assert(tour.size() > 1u);
	for (int i = 0; i < l; i++) {
		res[tour[i]] = tour[(i + 1) % l];
	}
}

int main() {
	scanf("%d", &n);
//	srand((unsigned) time (NULL));
//	n = 100000;
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
//		u = i + 1;
//		v = rand() % i + 1;			
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	get_cut(1, 1, 0);
	for (auto p : ord)
		work(p);
	int ans = 2 * (n - 1) - f[1][1] * 2;
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		printf("%d ", res[i]);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;
const int bzmax = 18;

#define pii pair<int, int>

int n, q;

typedef class Tree {
	public:
		int rt;
		vector<int> L;
		vector<pii> *G;
		
		int dep[N];
		int hei[N], lson[N];
		int top[N], bot[N], fa[N];
		
		int s[N];
		int bz[bzmax][N];
		vector<int> covt[N];
		
		void dfs1(int p, int Fa, int fw) {
			int &mx = hei[p], &id = lson[p];
			fa[p] = Fa, mx = id = 0, dep[p] = dep[Fa] + fw;
			for (auto par : G[p]) {
				int e = par.first;
				if (e ^ Fa) {
					dfs1(e, p, par.second);
					if (hei[e] > mx) {
						mx = hei[e];
						id = e;	
					}
				}
			}
			mx += fw;
		}
		
		void dfs2(int p, boolean ontop) {
			if (ontop) {
				top[p] = p;
				bot[p] = p;
				L.push_back(p);
			} else {
				top[p] = top[fa[p]];
				bot[top[p]] = p;
			}
			if (lson[p]) {
				dfs2(lson[p], false);
			}
			for (auto par : G[p]) {
				int e = par.first;
				if ((e ^ fa[p]) && (e ^ lson[p])) {
					dfs2(e, true);
				}
			}		
		}

		void init(int rt, vector<pii>* G) {
			this->rt = rt;
			this->G = G;
			dfs1(rt, 0, 0);
			dfs2(rt, true);
			sort(L.begin(), L.end(), [&] (int x, int y) {
						return hei[x] > hei[y];
					});
			s[0] = 0;
			L.insert(L.begin(), -142857);
			for (int i = 1; i < (signed) L.size(); i++) {
				int tp = L[i];
				int bt = bot[tp];
				s[i] = s[i - 1] + hei[tp];
				for (int p = bt; ; p = fa[p]) {
					covt[p].push_back(i);
					if (p == tp)
						break;
				}
				covt[fa[tp]].push_back(i);
			}
			for (int i = 1; i <= n; i++)
				bz[0][i] = fa[i];
			for (int b = 1; b < bzmax; b++) {
				for (int i = 1; i <= n; i++) {
					bz[b][i] = bz[b - 1][bz[b - 1][i]];
				}
			}
		}

		int query(int x, int y) {
			y <<= 1;
			y = min(y - 1, (signed) L.size() - 1);
			int res = s[y];
			if (*covt[x].begin() <= y)
				return res;
			int p = x;
			for (int i = bzmax - 1, q; ~i; i--) {
				q = bz[i][p];
				if (q && *covt[q].begin() > y) {
					p = q;
				}
			}
			p = fa[p];
			int gain = dep[fa[x]] - dep[p] + hei[x];
			int t = *--upper_bound(covt[p].begin(), covt[p].end(), y);
			int bt = bot[L[t]];
			return res + gain - min(s[y] - s[y - 1], dep[bt] - dep[p]);
		}
} Tree;

Tree t1, t2;
vector<pii> G[N];

void find_farthest(int p, int fa, int dist, int& mx, int& id) {
	if (dist > mx) {
		mx = dist;
		id = p;
	}
	for (auto par : G[p]) {
		int e = par.first;
		if (e ^ fa) {
			find_farthest(e, p, dist + par.second, mx, id);
		}
	}
}

int find_farthest(int p) {
	int mx = -1, id = -1;
	find_farthest(p, 0, 0, mx, id);
	return id;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1, u, v, w; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	int u = find_farthest(1);
	int v = find_farthest(u);
	t1.init(u, G);
	t2.init(v, G);
	int lastans = 0;
	while (q--) {
		scanf("%d%d", &u, &v);
		u = (u + lastans - 1) % n + 1;
		v = (v + lastans - 1) % n + 1;
		lastans = max(t1.query(u, v), t2.query(u, v));
		printf("%d\n", lastans);
	}
	return 0;
}
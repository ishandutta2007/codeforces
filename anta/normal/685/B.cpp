#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

vector<int> t_parent;
vi t_ord;

void tree_getorder(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();

	vector<int> stk; stk.push_back(root);
	while(!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for(int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if(t_parent[c] == -1 && c != root)
				stk.push_back(c);
			else
				t_parent[i] = c;
		}
	}
}

int main() {
	int n; int q;
	while(~scanf("%d%d", &n, &q)) {
		vector<vi> g(n);
		for(int i = 0; i < n - 1; ++ i) {
			int p;
			scanf("%d", &p), -- p;
			g[p].push_back(i + 1);
			g[i + 1].push_back(p);
		}
		tree_getorder(g, 0);
		vector<int> subtsize(n, 1);
		for(int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtsize[p] += subtsize[i];
		}
		vector<int> color(n, -1);
		int C = 0;
		for(int ix = 0; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			if(color[i] == -1)
				color[i] = C ++;
			pair<int, int> a(-1, -1);
			for(int j : g[i]) if(j != p)
				amax(a, make_pair(subtsize[j], j));
			if(a.second != -1)
				color[a.second] = color[i];
		}
		vector<vi> paths(C);
		for(int ix = 0; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			paths[color[i]].push_back(i);
		}
		rep(ii, q) {
			int u;
			scanf("%d", &u), -- u;
			const vi &path = paths[color[u]];
			int lo = 0, up = (int)path.size() - 1;
			while(up - lo > 0) {
				int mid = (lo + up + 1) / 2;
				int v = path[mid];
				if((subtsize[u] - subtsize[v]) * 2 > subtsize[u])
					up = mid - 1;
				else
					lo = mid;
			}
			int ans = path[lo];
			printf("%d\n", ans + 1);
		}
	}
	return 0;
}
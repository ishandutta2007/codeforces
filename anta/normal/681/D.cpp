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
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<vector<int> > g(n + 1);
		vector<int> cnt(n);
		for(int i = 0; i < m; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
			++ cnt[v];
		}
		rep(i, n) if(cnt[i] == 0) {
			g[i].push_back(n);
			g[n].push_back(i);
		}
		tree_getorder(g, n);
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]), -- a[i];
		vector<int> sum(n + 1), num(n);
		rep(i, n) ++ num[a[i]], ++ sum[a[i]];
		for(int ix = 1; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			sum[i] += sum[p];
		}
		bool ok = true;
		rep(i, n)
			ok &= sum[i] - sum[a[i]] == 0;
		if(!ok) {
			puts("-1");
		} else {
			vector<int> ans;
			for(int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
				int i = t_ord[ix], p = t_parent[i];
				if(num[i] > 0)
					ans.push_back(i);
			}
			printf("%d\n", (int)ans.size());
			for(int i = 0; i < (int)ans.size(); ++ i)
				printf("%d\n", ans[i] + 1);
		}
	}
	return 0;
}
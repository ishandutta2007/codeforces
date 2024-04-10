#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

vector<int> t_parent;
vector<int> t_ord;

void tree_getorder(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();

	vector<int> stk; stk.push_back(root);
	while (!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for (int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if (t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				stk.push_back(c);
			}
		}
	}
}

template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x%y); }

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> as(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &as[i]);
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_getorder(g, 0);
		vector<int> sum(n);
		vector<vi> values(n);
		vector<int> ans(n);
		sum[0] = as[0];
		values[0] = { 0 };
		ans[0] = as[0];
		for (int ix = 1; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i], a = as[i];
			sum[i] = gcd(sum[p], a);
			values[i].push_back(sum[p]);
			for (int x : values[p])
				values[i].push_back(gcd(x, a));
			sort(values[i].begin(), values[i].end());
			values[i].erase(unique(values[i].begin(), values[i].end()), values[i].end());
			ans[i] = values[i].back();
		}
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}
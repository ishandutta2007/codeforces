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

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> xs(n);
		vector<vi> g(n);
		int root = -1;
		rep(i, n) {
			int p; int x;
			scanf("%d%d", &p, &x), -- p;
			if (p != -1) {
				g[p].push_back(i);
				g[i].push_back(p);
			} else {
				root = i;
			}
			xs[i] = x;
		}
		tree_getorder(g, root);
		vector<int> subtsum(xs.begin(), xs.end());
		for (int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtsum[p] += subtsum[i];
		}
		if (subtsum[root] % 3 != 0) {
			puts("-1");
			continue;
		}
		int sum_3 = subtsum[root] / 3;
		vector<int> split(n, -1);
		for (int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			if (subtsum[i] == sum_3)
				split[i] = i;
			if(split[p] == -1)
				split[p] = split[i];
		}
		pair<int, int> ans(-1, -1);
		vector<int> children;
		for (int ix = 0; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			children.clear();
			for (int j : g[i]) if (j != p && split[j] != -1)
				children.push_back(split[j]);
			if ((int)children.size() >= 2)
				ans = { children[0], children[1] };
			if (p != -1 && subtsum[i] == sum_3 * 2 && (int)children.size() >= 1)
				ans = { i, children[0] };
		}
		if (ans.first == -1)
			puts("-1");
		else
			printf("%d %d\n", ans.first + 1, ans.second + 1);
	}
	return 0;
}
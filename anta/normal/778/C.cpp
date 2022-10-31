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

const int A = 26;
int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<vector<pair<int, int>>> trie(n);
		vector<vi> g(n);
		rep(i, n - 1) {
			int u; int v;
			scanf("%d%d", &u, &v), -- u, -- v;
			char buf[101];
			scanf("%s", buf);
			trie[u].emplace_back(*buf - 'a', v);
			g[u].push_back(v);
		}
		tree_getorder(g, 0);

		vector<int> depth(t_ord.size());
		for (int ix = 1; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			depth[i] = depth[p] + 1;
		}

		vector<int> subtsize(t_ord.size(), 1);
		for (int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtsize[p] += subtsize[i];
		}

		function<int(const vi&)> merge = [&](const vi &vertices) -> int {
			if (vertices.size() == 1)
				return subtsize[vertices[0]];
			assert(!vertices.empty());
			vi children[A];
			for (int i : vertices) {
				for (auto &&e : trie[i])
					children[e.first].push_back(e.second);
			}
			int r = 1;
			rep(a, A) if (!children[a].empty())
				r += merge(children[a]);
			return r;
		};

		vector<int> sums(n, 0);
		for (int ix = 0; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix];
			if (g[i].empty()) continue;
			vi children(g[i].begin(), g[i].end());
			int t = merge(children);
			int saved = subtsize[i] - t;
			sums[depth[i]] += saved;
		}

		pair<int, int> ans(n, 0);
		rep(d, n)
			amin(ans, make_pair(n - sums[d], d));
		printf("%d\n%d\n", ans.first, ans.second + 1);
	}
	return 0;
}
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
		for (int j = (int)g[i].size() - 1; j >= 0; j--) {
			int c = g[i][j];
			if (t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				stk.push_back(c);
			}
		}
	}
}

int main() {
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%d%d", &u, &v), --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int> home(k * 2), team(n, -1);
		rep(i, k * 2) {
			int c;
			scanf("%d", &c), --c;
			home[i] = c;
			team[c] = i;
		}
		int root = -1;
		{
			tree_getorder(g, 0);
			vector<int> subtsum(n);
			rep(i, n) subtsum[i] = team[i] != -1;
			for (int ix = (int)t_ord.size() - 1; ix > 0; --ix) {
				int i = t_ord[ix], p = t_parent[i];
				subtsum[p] += subtsum[i];
			}
			vi cnts;
			rep(i, n) {
				int p = t_parent[i];
				cnts.clear();
				for (int j : g[i]) if (j != p)
					cnts.push_back(subtsum[j]);
				if (p != -1)
					cnts.push_back(k * 2 - subtsum[i]);
				bool ok = true;
				for (int x : cnts)
					ok &= x <= k;
				if (!ok) continue;
				root = i;
				break;
			}
		}
		assert(root != -1);
		tree_getorder(g, root);
		vector<int> group(n, -1);
		group[root] = root;
		for (int ix = 1; ix < (int)t_ord.size(); ++ix) {
			int i = t_ord[ix], p = t_parent[i];
			group[i] = p == root ? i : group[p];
		}
		vector<vi> groups(n);
		rep(i, n) if (team[i] != -1)
			groups[group[i]].push_back(team[i]);
		priority_queue<pii> pq;
		rep(i, n)
			pq.push(make_pair((int)groups[i].size(), i));
		vpii pairs;
		rep(kk, k) {
			int a = pq.top().second; pq.pop();
			int b = pq.top().second; pq.pop();
			assert(!groups[a].empty() && !groups[b].empty());
			int x = groups[a].back();
			int y = groups[b].back();
			pairs.emplace_back(x, y);
			groups[a].pop_back();
			groups[b].pop_back();
			pq.push(make_pair((int)groups[a].size(), a));
			pq.push(make_pair((int)groups[b].size(), b));
		}
		printf("1\n%d\n", root + 1);
		for (auto p : pairs)
			printf("%d %d %d\n", home[p.first] + 1, home[p.second] + 1, root + 1);
	}
	return 0;
}
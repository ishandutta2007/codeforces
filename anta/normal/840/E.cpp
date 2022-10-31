#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")


using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct HLD {
	vector<vi> paths;
	vector<pair<int, int> > pathParent;
	vector<pair<int, int> > nodePos;
	vector<int> nodeDepth;

	void build(const vector<vi> &g, int root) {
		int N = g.size();
		vector<int> t_ord, t_parent(N, -1);
		nodeDepth.assign(N, 0);
		{
			vector<int> stk;
			stk.push_back(root);
			while (!stk.empty()) {
				int i = stk.back();
				stk.pop_back();
				t_ord.push_back(i);
				for (int j : g[i]) if (j != root && t_parent[j] == -1) {
					t_parent[j] = i;
					nodeDepth[j] = nodeDepth[i] + 1;
					stk.push_back(j);
				}
			}
		}
		vector<int> subtsize(N, 1);
		for (int ix = N - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtsize[p] += subtsize[i];
		}
		paths.clear();
		paths.push_back(vi());
		pathParent.emplace_back(-1, 0);
		dfs(root, -1, g, subtsize);
		assert(paths.back().empty());
		paths.pop_back();
		assert(paths.size() == pathParent.size());

		nodePos.assign(N, { -1, -1 });
		rep(c, paths.size()) rep(p, paths[c].size())
			nodePos[paths[c][p]] = { c, p };
	}

	void get(int u, int &c, int &p) const {
		tie(c, p) = nodePos[u];
	}

	bool go_up(int &c, int &p) const {
		tie(c, p) = pathParent[c];
		return c != -1;
	}

	typedef tuple<int, int, int> SubPath;

	void getPath1(int u, int v, vector<SubPath> &path) const {
		path.clear();
		int uc, up, vc, vp;
		get(u, uc, up);
		get(v, vc, vp);
		while (uc != vc) {
			path.emplace_back(vc, 0, vp + 1);
			go_up(vc, vp);
		}
		path.emplace_back(vc, up, vp + 1);
	}

private:
	void dfs(int i, int p, const vector<vi> &g, const vector<int> &subtsize) {
		int color = (int)paths.size() - 1;
		int pos = paths.back().size();
		paths.back().push_back(i);

		int c = -1;
		for (int j : g[i]) if (j != p) {
			if (c == -1 || subtsize[c] < subtsize[j])
				c = j;
		}

		if (c == -1) {
			paths.push_back(vi());
			return;
		}

		dfs(c, i, g, subtsize);

		for (int j : g[i]) if (j != p && j != c) {
			pathParent.emplace_back(color, pos);
			dfs(j, i, g, subtsize);
		}
	}
};

int main() {
	int n; int q;
	while (~scanf("%d%d", &n, &q)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		HLD hld;
		hld.build(g, 0);
		map<pii, int> memo;
		vector<tuple<int, int, int>> path;
		vector<int> offsets(hld.paths.size() + 1);
		const int W = 8;
		rep(i, hld.paths.size())
			offsets[i + 1] = offsets[i] + (hld.paths[i].size() / W + 1) * W;
		vector<uint16_t> values(offsets.back());
		rep(i, hld.paths.size()) rep(j, hld.paths[i].size())
			values[offsets[i] + j] = a[hld.paths[i][hld.paths[i].size() - 1 - j]];
		ll anssum = 0;
		rep(ii, q) {
			int u; int v;
			scanf("%d%d", &u, &v), -- u, -- v;
			auto &ans = memo.emplace(make_pair(make_pair(u, v), -1)).first->second;
			if (ans != -1) {
				printf("%d\n", ans);
				continue;
			}
			hld.getPath1(u, v, path);
			int add = 0;
			int maxi = 0;
			for (auto t : path) {
				int c, L, R;
				tie(c, L, R) = t;
				auto x = values.data() + offsets[c] + (hld.paths[c].size() - R);
				int len = R - L;
				for (int i = 0; i < len; ++ i)
					amax(maxi, x[i] ^ (add + i));
				add += len;
			}
			ans = maxi;
			printf("%d\n", ans);
		}
	}
	return 0;
}
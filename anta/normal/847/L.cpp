#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

vector<vector<vi>> makeList(const vector<pair<int, int>> &edges) {
	int n = (int)edges.size() + 1;
	vector<vi> g(n);
	for (auto e : edges) {
		g[e.first].push_back(e.second);
		g[e.second].push_back(e.first);
	}
	vector<int> curList;
	function<void(int, int)> dfs = [&](int i, int p) {
		curList.push_back(i);
		for (int j : g[i]) if (j != p)
			dfs(j, i);
	};
	vector<vector<vi>> res(n);
	rep(i, n) {
		auto &lists = res[i];
		for (int j : g[i]) {
			dfs(j, i);
			sort(curList.begin(), curList.end());
			lists.push_back(move(curList));
		}
		sort(lists.begin(), lists.end());
	}
	return res;
}


int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<vector<vi>> orgLists(n);
		vector<set<int>> lists;
		vector<int> listi;
		vector<set<int>> adj(n);
		vector<vector<int>> invg(n);
		rep(i, n) {
			char buf[100001];
			scanf("%s", buf);
			for (char *p = buf; *p; ++ p)
				if (!isdigit(*p))
					*p = ' ';
			stringstream ss(buf);
			int k;
			while (ss >> k) {
				orgLists[i].emplace_back();
				rep(j, k) {
					int x;
					ss >> x; -- x;
					orgLists[i].back().push_back(x);
				}
			}

			for (const auto &list : orgLists[i]) {
				int li = (int)lists.size();
				adj[i].insert(li);
				lists.emplace_back(list.begin(), list.end());
				listi.push_back(i);
				for (int x : list)
					invg[x].push_back(li);
			}
		}
		vpii ans;
		vector<int> que;
		vector<bool> vis(n);
		rep(i, n) if (adj[i].size() == 1) {
			vis[i] = true;
			que.push_back(i);
		}
		for (int qh = 0; qh != que.size() && qh < n - 1; ++ qh) {
			int i = que[qh];
			for(int li : invg[i]) {
				lists[li].erase(i);
				int j = listi[li];
				if (lists[li].empty()) {
					ans.emplace_back(i, j);
					adj[j].erase(li);
					if (adj[j].size() == 1 && !vis[j]) {
						vis[j] = true;
						que.push_back(j);
					}
				}
			}
		}
		bool ok = true;
		ok &= ans.size() == n - 1;
		UnionFind uf; uf.init(n);
		for (auto e : ans)
			ok &= uf.unionSet(e.first, e.second);
		if (ok) {
			rep(i, n) {
				auto &org = orgLists[i];
				for (auto &list : org)
					sort(list.begin(), list.end());
				sort(org.begin(), org.end());
			}
			auto lists = makeList(ans);
			ok &= orgLists == lists;
		}
		if (!ok) {
			puts("-1");
		} else {
			printf("%d\n", n - 1);
			for (int i = 0; i < (int)ans.size(); ++ i)
				printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		}
	}
	return 0;
}
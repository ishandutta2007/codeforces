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

//Sum combine(Sum x, Sum y);
//Sum calc(int from, int to, Sum sum);
template<typename Sum, typename Combine, typename Calc>
void freeTreeDP(const vector<int> &t_ord, const vector<int> &t_parent, vector<Sum> &downsum, vector<Sum> &upsum, Sum identity, Combine combine, Calc calc) {
	int n = (int)t_ord.size();
	vector<int> children(n, 0), childid(n, -1);
	for(int ix = 1; ix < (int)t_ord.size(); ++ ix) {
		int i = t_ord[ix], p = t_parent[i];
		childid[i] = children[p] ++;
	}
	vector<vector<Sum>> prefix(n), suffix(n);
	for(int i = 0; i < n; ++ i) {
		prefix[i].assign(children[i] + 1, identity);
		suffix[i].assign(children[i] + 1, identity);
	}
	downsum.assign(n, identity);
	upsum.assign(n, identity);
	for(int ix = (int)t_ord.size() - 1; ix >= 0; -- ix) {
		int i = t_ord[ix], p = t_parent[i];
		for(int j = 0; j < children[i]; ++ j)
			prefix[i][j + 1] = combine(prefix[i][j], prefix[i][j + 1]);
		for(int j = children[i]; j > 0; -- j)
			suffix[i][j - 1] = combine(suffix[i][j - 1], suffix[i][j]);
		if(p != -1) {
			downsum[i] = calc(p, i, suffix[i][0]);
			prefix[p][childid[i] + 1] = downsum[i];
			suffix[p][childid[i]] = downsum[i];
		}
	}
	downsum[t_ord[0]] = suffix[t_ord[0]][0];
	for(int ix = 1; ix < (int)t_ord.size(); ++ ix) {
		int i = t_ord[ix], p = t_parent[i];
		Sum sum = suffix[p][childid[i] + 1];
		sum = combine(sum, upsum[p]);
		sum = combine(sum, prefix[p][childid[i]]);
		upsum[i] = calc(i, p, sum);
	}
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<vector<int> > g(n);
		for(int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_getorder(g, 0);

		vector<int> subtsize(n, 1);
		for(int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			subtsize[p] += subtsize[i];
		}
		int half = n / 2;
		vector<int> down, up;
		auto getsubtsize = [&](int from, int to) {
			return from == t_parent[to] ? subtsize[to] : n - subtsize[from];
		};
		freeTreeDP(t_ord, t_parent, down, up,
			-INF,
			[](int x, int y) { return max(x, y); },
			[&](int from, int to, int sum) {
			int val = getsubtsize(from, to);
			if(val > half) val = -INF;
			return max(val, sum);
		});
		vector<int> ans(n, -1);
		rep(i, n) {
			ans[i] = 1;
			int num = 0;
			int p = t_parent[i];
			for(int j : g[i]) if(j != p) {
				int s = getsubtsize(i, j);
				if(s > half)
					ans[i] &= s - down[j] <= half;
			}
			if(p != -1) {
				int s = getsubtsize(i, p);
				ans[i] &= s - up[i] <= half;
			}
		}
		for(int i = 0; i < n; ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}
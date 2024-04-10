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
vector<int> t_ord;

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
			if(t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				stk.push_back(c);
			}
		}
	}
}

struct Eccentricity {
	int dist;
	int i;
	Eccentricity() : dist(-INF), i(-1) {}
	Eccentricity(int dist_, int i_) : dist(dist_), i(i_) {}
	//
	bool operator<(const Eccentricity &that) {
		return dist != that.dist ? dist < that.dist : i > that.i;
	}
	Eccentricity operator+(int c) const {
		return Eccentricity(dist + c, i);
	}
};

void treeEccentricities(const vector<vi> &gw, vector<Eccentricity> &res) {
	int n = gw.size();

	vector<pair<Eccentricity, Eccentricity> > dp(n);
	for(int ix = n - 1; ix >= 0; -- ix) {
		int i = t_ord[ix], p = t_parent[i];
		dp[i].first = dp[i].second = Eccentricity(0, i);
		for(int j : gw[i]) if(j != p) {
			Eccentricity v = dp[j].first + 1;
			if(dp[i].first < v) {
				dp[i].second = dp[i].first;
				dp[i].first = v;
			} else if(dp[i].second < v) {
				dp[i].second = v;
			}
		}
	}
	res.assign(n, Eccentricity());
	res[0] = Eccentricity(0, 0);
	reu(ix, 1, n) {
		int i = t_ord[ix], p = t_parent[i];
		int pw = 0;
		for(int j : gw[i]) if(j == p)
			pw = 1;
		res[i] = res[p] + pw;
		if(dp[p].first.i == dp[i].first.i)
			amax(res[i], dp[p].second + pw);
		else
			amax(res[i], dp[p].first + pw);
	}
	rep(i, n)
		amax(res[i], dp[i].first);
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> color(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &color[i]);
		vector<vector<int> > g(n);
		for(int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_getorder(g, 0);
		vector<int> cc(n, -1);
		int C = 0;
		cc[0] = C ++;
		for(int ix = 1; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			if(color[p] == color[i])
				cc[i] = cc[p];
			else
				cc[i] = C ++;
		}
		vector<vi> gg(C);
		for(int ix = 1; ix < (int)t_ord.size(); ++ ix) {
			int i = t_ord[ix], p = t_parent[i];
			if(cc[i] != cc[p]) {
				gg[cc[p]].push_back(cc[i]);
				gg[cc[i]].push_back(cc[p]);
			}
		}
		tree_getorder(gg, 0);
		vector<Eccentricity> ecc;
		treeEccentricities(gg, ecc);
		int ans = INF;
		rep(i, C)
			amin(ans, (int)ecc[i].dist);
		printf("%d\n", ans);
	}
	return 0;
}
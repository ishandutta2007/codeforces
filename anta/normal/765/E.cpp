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

template<typename Sum, typename Combine, typename Calc>
void freeTreeDP(const vector<int> &t_ord, const vector<int> &t_parent, vector<Sum> &downsum, vector<Sum> &upsum, Sum identity, Combine combine, Calc calc) {
	int n = (int)t_ord.size();
	vector<int> children(n, 0), childid(n, -1);
	for (int ix = 1; ix < (int)t_ord.size(); ++ ix) {
		int i = t_ord[ix], p = t_parent[i];
		childid[i] = children[p] ++;
	}
	vector<vector<Sum>> prefix(n), suffix(n);
	for (int i = 0; i < n; ++ i) {
		prefix[i].assign(children[i] + 1, identity);
		suffix[i].assign(children[i] + 1, identity);
	}
	downsum.assign(n, identity);
	upsum.assign(n, identity);
	for (int ix = (int)t_ord.size() - 1; ix >= 0; -- ix) {
		int i = t_ord[ix], p = t_parent[i];
		for (int j = 0; j < children[i]; ++ j)
			prefix[i][j + 1] = combine(prefix[i][j], prefix[i][j + 1]);
		for (int j = children[i]; j > 0; -- j)
			suffix[i][j - 1] = combine(suffix[i][j - 1], suffix[i][j]);
		if (p != -1) {
			downsum[i] = calc(p, i, suffix[i][0]);
			prefix[p][childid[i] + 1] = downsum[i];
			suffix[p][childid[i]] = downsum[i];
		}
	}
	downsum[t_ord[0]] = suffix[t_ord[0]][0];
	for (int ix = 1; ix < (int)t_ord.size(); ++ ix) {
		int i = t_ord[ix], p = t_parent[i];
		Sum sum = suffix[p][childid[i] + 1];
		sum = combine(sum, upsum[p]);
		sum = combine(sum, prefix[p][childid[i]]);
		upsum[i] = calc(i, p, sum);
	}
}

struct Sum {
	int values[2];
	int k;
	Sum() : k(0) {}
	void insert(int x) {
		rep(i, k) if (values[i] == x)
			return;
		if (k == 2) {
			k = INF;
		} else {
			values[k ++] = x;
		}
	}
	Sum operator+(const Sum &that) const {
		if (k == INF) return *this;
		if (that.k == INF) return that;
		Sum res;
		res = *this;
		rep(i, that.k)
			res.insert(that.values[i]);
		return res;
	}
};

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_getorder(g, 0);
		vector<Sum> downsum, upsum;
		freeTreeDP(t_ord, t_parent, downsum, upsum, Sum(), plus<Sum>(), [](int from, int to, Sum sum) -> Sum {
			Sum res = sum;
			if (sum.k == 0) {
				res.insert(1);
				return res;
			}
			if (res.k >= 2) {
				res.k = INF;
				return res;
			}
			rep(i, res.k)
				++ res.values[i];
			return res;
		});
		int ans = n - 1;
		rep(i, n) {
			if ((int)g[i].size() >= 3) {
				if (ans == n - 1)
					ans = INF;
				
				Sum sum;
				int p = t_parent[i];
				for (int j : g[i]) if (j != p)
					sum = sum + downsum[j];
				if (p != -1)
					sum = sum + upsum[i];
				if (sum.k != INF) {
					int total = 0;
					rep(i, sum.k)
						total += sum.values[i];
					amin(ans, total);
				}
			}
		}
		if (ans != INF) {
			while (ans % 2 == 0)
				ans /= 2;
		}
		if (ans == INF) {
			puts("-1");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
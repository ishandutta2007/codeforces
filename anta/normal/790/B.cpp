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

struct Count {
	ll cnt0;
	ll cnt1;
	Count() : cnt0(0), cnt1(0) {}
};

int main() {
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_getorder(g, 0);
		vector<vector<Count>> cnt(n, vector<Count>(k));
		rep(i, n)
			cnt[i][0].cnt0 += 1;
		vector<Count> total(k);
		for (int ix = (int)t_ord.size() - 1; ix > 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			rep(a, k) rep(b, k) {
				const auto &x = cnt[p][a];
				const auto &y = cnt[i][b];
				auto &z = total[(a + b + 1) % k];
				z.cnt0 += x.cnt0 * y.cnt0;
				z.cnt1 += x.cnt1 * y.cnt0 + x.cnt0 * y.cnt1 + x.cnt0 * y.cnt0;
			}
			rep(j, k) {
				auto &x = cnt[p][(j + 1) % k];
				const auto &y = cnt[i][j];
				x.cnt1 += y.cnt1 + y.cnt0;
				x.cnt0 += y.cnt0;
			}
		}
		ll ans = 0;
		rep(j, k) {
			const auto &x = total[j];
			ll t = x.cnt1 + x.cnt0 * ((k - j) % k);
			assert(t % k == 0);
			ans += t / k;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
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
vi t_ord;
vector<int> t_left, t_right;

void tree_eulertour(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();
	t_left.assign(n, -1);
	t_right.assign(n, -1);

	vector<int> stk; stk.push_back(root);
	while (!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		if (i < 0) {
			i = -i - 1;
			t_right[i] = t_ord.size();
			continue;
		}
		t_left[i] = t_ord.size();
		t_ord.push_back(i);
		stk.push_back(-(i + 1));
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
	int n;
	while (~scanf("%d", &n)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%d%d", &u, &v), --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_eulertour(g, 0);
		vector<ll> sum(a.begin(), a.end());
		for (int ix = (int)t_ord.size() - 1; ix > 0; --ix) {
			int i = t_ord[ix], p = t_parent[i];
			sum[p] += sum[i];
		}
		vector<vi> Ls(n + 1), Rs(n + 1);
		rep(i, n) {
			Ls[t_left[i]].push_back(i);
			Rs[t_right[i]].push_back(i);
		}
		vector<ll> maxL(n + 1), maxR(n + 1);
		{
			ll cur = -INFL;
			rer(mid, 0, n) {
				for (int i : Rs[mid])
					amax(cur, sum[i]);
				maxR[mid] = cur;
			}
		}
		{
			ll cur = -INFL;
			for (int mid = n; mid >= 0; --mid) {
				for (int i : Ls[mid])
					amax(cur, sum[i]);
				maxL[mid] = cur;
			}
		}
		ll ans = -INFL;
		rer(mid, 0, n) if(maxL[mid] > -INFL && maxR[mid] > -INFL)
			amax(ans, maxL[mid] + maxR[mid]);
		if (ans == -INFL)
			puts("Impossible");
		else
			printf("%lld\n", ans);
	}
	return 0;
}
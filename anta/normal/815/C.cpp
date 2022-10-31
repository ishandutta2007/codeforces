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
	int n; int B;
	while (~scanf("%d%d", &n, &B)) {
		vector<int> cs(n), ds(n);
		vector<vi> g(n);
		rep(i, n) {
			int c; int d;
			scanf("%d%d", &c, &d);
			cs[i] = c, ds[i] = d;
			if (i != 0) {
				int p;
				scanf("%d", &p), -- p;
				g[p].push_back(i);
			}
		}
		tree_eulertour(g, 0);
		function<pair<vi,vi>(int,int)> rec = [&](int i, int j) -> pair<vi,vi> {
			if (j == g[i].size()) {
				vi v = { INF, cs[i] - ds[i] };
				vi w = { 0, INF };
				return make_pair(v, w);
			}
			int c = g[i][j];
			vi A0, A1, B0, B1;
			tie(A0, A1) = rec(c, 0);
			tie(B0, B1) = rec(i, j + 1);
			vector<int> res0(A0.size() + B0.size() - 1, INF);
			vector<int> res1(res0.size(), INF);
			rep(k, (int)res0.size()) {
				int aL = max(0, k - ((int)B0.size() - 1));
				int aR = min((int)A0.size() - 1, k);
				int x0 = INF;
				rer(a, aL, aR) {
					int b = k - a;
					amin(x0, min(A0[a], A1[a]) + B0[b]);
				}
				amin(res0[k], x0);
			}
			if (j == 0) {
				vector<int> sorted(t_right[i] - t_left[i]);
				rep(k, sorted.size())
					sorted[k] = cs[t_ord[t_left[i] + k]];
				sort(sorted.begin(), sorted.end());
				int sum = 0;
				amin(res1[0], 0);
				rep(k, sorted.size()) {
					sum += sorted[k];
					if (sum > INF) break;
					amin(res1[k + 1], sum);
				}
			}
			return make_pair(res0, res1);
		};
		vi v, w;
		tie(v, w) = rec(0, 0);
		vi A(v.size());
		rep(i, v.size())
			A[i] = min(v[i], w[i]);
		assert(A.size() == n + 1);
		int ans = 0;
		rep(k, A.size()) if(A[k] <= B)
			amax(ans, k);
		printf("%d\n", ans);
	}
	return 0;
}
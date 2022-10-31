#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

using Weight = int;
const Weight InfWeight = INF;
Weight hungarianMin(const vector<vector<Weight> > &A) {
	if (A.empty()) return 0;
	int h = A.size(), n = A[0].size();
	if (h > n) return InfWeight;
	vector<Weight> fx(h), fy(n);
	vector<int> x(h, -1), y(n, -1);
	vector<int> t(n), s(h + 1);
	for (int i = 0; i < h; ) {
		fill(t.begin(), t.end(), -1);
		s[0] = i;
		int q = 0;
		for (int p = 0; p <= q; ++ p) {
			for (int k = s[p], j = 0; j < n; ++ j) {
				if (fx[k] + fy[j] == A[k][j] && t[j] < 0) {
					s[++ q] = y[j];
					t[j] = k;
					if (s[q] < 0) {
						for (p = j; p >= 0; j = p) {
							y[j] = k = t[j];
							p = x[k];
							x[k] = j;
						}
						++ i;
						goto continue_;
					}
				}
			}
		}
		if (0) {
		continue_:;
		} else {
			Weight d = InfWeight;
			for (int j = 0; j < n; j++) if (t[j] < 0) {
				for (int k = 0; k <= q; ++ k) if (A[s[k]][j] != InfWeight)
					d = min(d, A[s[k]][j] - fx[s[k]] - fy[j]);
			}
			if (d == InfWeight)
				return InfWeight;
			for (int j = 0; j < n; ++ j) {
				if (t[j] >= 0)
					fy[j] -= d;
			}
			for (int k = 0; k <= q; ++ k)
				fx[s[k]] += d;
		}
	}
	Weight res = 0;
	for (int i = 0; i < h; ++ i)
		res += A[i][x[i]];
	return res;
}

int main() {
	int n; int q;
	while (~scanf("%d%d", &n, &q)) {
		vector<int> lo(n, 1), up(n, n);
		rep(qi, q) {
			int t; int l; int r; int v;
			scanf("%d%d%d%d", &t, &l, &r, &v), -- l;
			if (t == 1) {
				reu(i, l, r)
					amax(lo[i], v);
			} else {
				reu(i, l, r)
					amin(up[i], v);
			}
		}
		bool ok = true;
		rep(i, n)
			ok &= lo[i] <= up[i];
		if (!ok) {
			puts("-1");
			continue;
		}
		vector<vector<int>> A(n, vector<int>(n * n, INF));
		rep(i, n) {
			rer(x, lo[i], up[i]) {
				rep(k, n)
					A[i][(x - 1) * n + k] = 2 * k + 1;
			}
		}
		int ans = hungarianMin(A);
		printf("%d\n", ans);
	}
	return 0;
}
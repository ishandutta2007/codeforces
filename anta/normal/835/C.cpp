#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

template<typename T>
struct RectangeSum {
	vector<vector<T> > sum;
	template<typename U>
	void init(int h, int w, U &a) {
		sum.assign(h + 1, vector<T>(w + 1));
		rer(y, 0, h) rer(x, 0, w) sum[y][x] = (y == 0 || x == 0) ? 0 :
			sum[y - 1][x] + sum[y][x - 1] - sum[y - 1][x - 1] + a[y - 1][x - 1];
	}
	//[l, r), [t, b)
	inline T get(int t, int l, int b, int r) const {
		return sum[b][r] - sum[b][l] - sum[t][r] + sum[t][l];
	}
};

int main() {
	int n; int q; int c;
	while (~scanf("%d%d%d", &n, &q, &c)) {
		++ c;
		const int X = 100;
		vector<vector<vi>> cnts(c, vector<vi>(X, vi(X)));
		rep(i, n) {
			int x; int y; int s;
			scanf("%d%d%d", &x, &y, &s), -- x, -- y;
			++ cnts[s][x][y];
		}
		vector<RectangeSum<int>> sums(c);
		rep(k, c)
			sums[k].init(X, X, cnts[k]);
		rep(ii, q) {
			int t;
			scanf("%d", &t);
			int x1; int y1; int x2; int y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2), -- x1, -- y1;
			int ans = 0;
			rep(k, c) {
				int a = sums[k].get(x1, y1, x2, y2);
				ans += a * ((k + t) % c);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
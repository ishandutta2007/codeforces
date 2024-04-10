#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int H; int W;
	while (~scanf("%d%d", &H, &W)) {
		vector<vector<int> > A(H, vector<int>(W));
		for (int i = 0; i < H; ++ i) for (int j = 0; j < W; ++ j)
			scanf("%d", &A[i][j]);
		vector<int> row(H), col(W);
		rep(i, H) {
			int x = *min_element(A[i].begin(), A[i].end());
			row[i] += x;
			rep(j, W)
				A[i][j] -= x;
		}

		rep(j, W) {
			int x = INF;
			rep(i, H)
				amin(x, A[i][j]);
			col[j] += x;
			rep(i, H)
				A[i][j] -= x;
		}
		if(H >= W) {
			int x = *min_element(row.begin(), row.end());
			rep(i, H)
				row[i] -= x;
			rep(j, W)
				col[j] += x;
		} else {
			int x = *min_element(col.begin(), col.end());
			rep(j, W)
				col[j] -= x;
			rep(i, H)
				row[i] += x;
		}

		bool ok = true;
		rep(i, H) rep(j, W)
			ok &= A[i][j] == 0;
		if (ok) {
			vpii ans;
			rep(i, H) rep(k, row[i])
				ans.emplace_back(0, i);
			rep(j, W) rep(k, col[j])
				ans.emplace_back(1, j);
			printf("%d\n", (int)ans.size());
			for (int i = 0; i < (int)ans.size(); ++ i)
				printf("%s %d\n", ans[i].first == 0 ? "row" : "col", ans[i].second + 1);
		} else {
			puts("-1");
		}
	}
	return 0;
}
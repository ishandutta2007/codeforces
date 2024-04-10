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
	int n;
	while (~scanf("%d", &n)) {
		vector<int> next(n, -1);
		vector<int> roots;
		rep(i, n) {
			int l; int r;
			scanf("%d%d", &l, &r), -- l, -- r;
			next[i] = r;
			if (l == -1)
				roots.push_back(i);
		}
		vector<int> seq;
		for (int i : roots) {
			for (int j = i; j != -1; j = next[j])
				seq.push_back(j);
		}
		vector<pair<int, int>> ans(n, make_pair(-1, -1));
		rep(ix, n)
			ans[seq[ix]] = { ix == 0 ? -1 : seq[ix - 1], ix == n - 1 ? -1 : seq[ix + 1] };
		for (int i = 0; i < (int)ans.size(); ++ i)
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}
	return 0;
}
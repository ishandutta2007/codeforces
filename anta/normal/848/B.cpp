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
	//t + x = u + y
	int n; int W; int H;
	while (~scanf("%d%d%d", &n, &W, &H)) {
		map<int, array<vector<pair<int, int>>, 2>> groups;
		rep(i, n) {
			int g; int p; int t;
			scanf("%d%d%d", &g, &p, &t), -- g;
			groups[t - p][g].emplace_back(p, i);
		}
		vpii ans(n);
		for (auto &&group : groups) {
			vpii ord;
			vpii poses;
			rep(k, 2) {
				auto &v = group.second[k];
				sort(v.begin(), v.end());
				if (k == 0) reverse(v.begin(), v.end());
				ord.insert(ord.end(), v.begin(), v.end());
			}
			for (int k = 1; k >= 0; -- k) {
				auto &v = group.second[k];
				for (auto p : v) {
					if (k == 0)
						poses.emplace_back(p.first, H);
					else
						poses.emplace_back(W, p.first);
				}
			}
			rep(ix, ord.size())
				ans[ord[ix].second] = poses[ix];
		}
		for (int i = 0; i < (int)ans.size(); ++ i)
			printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
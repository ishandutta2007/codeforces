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
	int n; int k; int m; int a;
	while (~scanf("%d%d%d%d", &n, &k, &m, &a)) {
		vector<pair<int, int>> cur(n, make_pair(0, INF));
		auto vote = [](pair<int, int> p, int i) {
			return make_pair(p.first + 1, -i);
		};
		rep(i, a) {
			int g;
			scanf("%d", &g), -- g;
			cur[g] = vote(cur[g], i);
		}
		if (n == 1) {
			puts("1");
			continue;
		}
		vector<int> ans(n, 0);
		rep(i, n) {
			auto p = cur[i];
			reu(k, a, m) p = vote(p, k);
			int num = 0;
			rep(j, n) if(i != j)
				num += p < cur[j];
			if (num < k && p.first > 0)
				ans[i] |= 2;
		}
		rep(i, n) if(cur[i].first > 0) {
			int num = 0;
			vi v;
			rep(j, n) if(i != j) {
				if (cur[i] < cur[j]) {
					++ num;
				} else {
					v.push_back(cur[j].first);
				}
			}
			sort(v.rbegin(), v.rend());
			int rem = m - a;
			for (int x : v) {
				int t = cur[i].first - x + 1;
				if (rem < t) break;
				rem -= t;
				++ num;
			}
			if (num < k)
				ans[i] |= 1;
		}
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%c", "3?21"[ans[i]]);
		}
		puts("");
	}
	return 0;
}
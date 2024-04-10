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
	mt19937 re;
	int n; int m; int k;
	while (~scanf("%d%d%d", &n, &m, &k)) {
		vector<int> f(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &f[i]);
		vector<pii> s(m);
		for (int i = 0; i < m; ++ i) {
			scanf("%d", &s[i].first);
			s[i].second = i;
		}
		sort(f.begin(), f.end());
		sort(s.begin(), s.end());
		int D = 0;
		rep(i, n)
			amax(D, f[i] + 1);
		rep(i, m)
			amax(D, s[i].first + 1);
		vector<int> nums(D);
		vector<int> sL(D + 1, 0);
		{
			int fi = 0, si = 0;
			int num = 0;
			rep(d, D) {
				for (; fi < n && f[fi] == d; ++ fi)
					++ num;
				nums[d] = num;
				for (; si < m && s[si].first == d; ++ si);
				sL[d + 1] = si;
			}
		}
		vector<int> ans;
		bool ok = true;
		int margin = INF;
		for (int d = D - 1; d >= 0; -- d) {
			amin(margin, (ll)(d + 1) * k - nums[d]);
			int cnt = min(sL[d + 1] - sL[d], margin);
			if (cnt < 0) {
				ok = false;
				break;
			}
			margin -= cnt;
			rep(i, cnt)
				ans.push_back(s[sL[d] + i].second);
		}
		if (!ok) {
			puts("-1");
		} else {
			printf("%d\n", (int)ans.size());
			sort(ans.begin(), ans.end());
			for (int i = 0; i < (int)ans.size(); ++ i) {
				if (i != 0) putchar(' ');
				printf("%d", ans[i] + 1);
			}
			puts("");
		}
	}
	return 0;
}
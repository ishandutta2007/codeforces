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
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		if (count(a.begin(), a.end(), 0) == n) {
			puts("NO");
			continue;
		}
		vpii ans;
		if (accumulate(a.begin(), a.end(), 0) != 0) {
			ans.emplace_back(0, n);
		} else {
			int i = 0;
			while (a[i] == 0) ++i;
			ans.emplace_back(0, i + 1);
			ans.emplace_back(i + 1, n);
		}
		puts("YES");
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); ++i)
			printf("%d %d\n", ans[i].first + 1, ans[i].second);
	}
	return 0;
}
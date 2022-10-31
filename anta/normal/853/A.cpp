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
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<int> c(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &c[i]);
		vector<int> ans(n, -1);
		priority_queue<pair<int, int>> pq;
		int j = 0;
		rer(t, k + 1, k + n) {
			for (; j + 1 <= t && j < n; ++ j)
				pq.push(make_pair(c[j], j));
			int i = pq.top().second;
			ans[i] = t;
			pq.pop();
		}
		ll cost = 0;
		rep(i, n)
			cost += (ll)c[i] * (ans[i] - (i + 1));
		printf("%lld\n", cost);
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}
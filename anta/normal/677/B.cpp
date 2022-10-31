#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n; int h; int k;
	while(~scanf("%d%d%d", &n, &h, &k)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		int i = 0, cur = 0;
		ll ans = 0;
		while(i < n || cur > 0) {
			for(; i < n && cur + a[i] <= h; ++ i)
				cur += a[i];
			int t = max(1, (i == n ? cur : cur - (h - a[i])) / k);
			ans += t;
			cur = max(0, cur - t * k);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
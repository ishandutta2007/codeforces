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
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		ll ans = -INFL;
		rep(p, 2) {
			ll sum = 0, minSum = 0;
			for (int i = p; i + 1 < n; ++ i) {
				int x = abs(a[i + 1] - a[i]);
				if ((i - p) % 2 == 0)
					sum += x;
				else
					sum -= x;
				amax(ans, sum - minSum);
				if ((i - p) % 2 == 1)
					amin(minSum, sum);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n; int a;
	while(~scanf("%d%d", &n, &a)) {
		vector<int> x(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &x[i]);
		int ans = INF;
		if(n == 1) {
			ans = 0;
		} else {
			sort(x.begin(), x.end());
			rep(lr, 2) {
				vi y = x;
				y.erase(lr == 0 ? y.begin() : y.end() - 1);
				int L = min(y.front(), a);
				int R = max(y.back(), a);
				amin(ans, (R - a) + (R - L));
				amin(ans, (a - L) + (R - L));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
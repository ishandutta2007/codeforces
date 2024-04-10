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
	int n; int x; int y;
	while(~scanf("%d%d%d", &n, &x, &y)) {
		vector<ll> ans(n + 1);
		ans[1] = x;
		rer(i, 2, n) {
			ans[i] = ans[i - 1] + x;
			if(i % 2 == 0)
				amin(ans[i], ans[i / 2] + y);
			else
				amin(ans[i], ans[i / 2 + 1] + y + x);
		}
		printf("%lld\n", ans[n]);
	}
	return 0;
}
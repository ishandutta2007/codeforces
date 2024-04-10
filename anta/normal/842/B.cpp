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
	int R; int D;
	while (~scanf("%d%d", &R, &D)) {
		int n;
		scanf("%d", &n);
		int ans = 0;
		rep(i, n) {
			int x; int y; int r;
			scanf("%d%d%d", &x, &y, &r);
			auto t = hypot(x, y);
			//sqrt(t) + r <= R
			ans += R - D - 1e-8 <= t - r && t + r <= R + 1e-8;
		}
		printf("%d\n", ans);
	}
	return 0;
}
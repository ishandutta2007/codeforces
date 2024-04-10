#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct Point {
	int x, y, z;
};

int main() {
	int n; int X; int Y; int Z;
	while (~scanf("%d%d%d%d", &n, &X, &Y, &Z)) {
		vector<Point> points(n);
		vector<int> minZ(Y, 0);
		rep(i, n) {
			int x; int y; int z;
			scanf("%d%d%d", &x, &y, &z), -- x, -- y, -- z;
			points[i] = Point{ x,y,z };
			amax(minZ[y], z + 1);
		}
		for (int j = Y - 2; j >= 0; -- j)
			amax(minZ[j], minZ[j + 1]);
		vector<ll> minZsum(Y + 1);
		rep(j, Y)
			minZsum[j + 1] = minZsum[j] + minZ[j];
		sort(points.begin(), points.end(), [](Point a, Point b) { return a.x < b.x; });
		ll ans = 0;
		int pi = (int)points.size() - 1;
		int yL = 0, zL = 0;
		for (int i = X - 1; i >= 0; -- i) {
			for (; pi >= 0 && i <= points[pi].x; -- pi) {
				Point p = points[pi];
				amax(yL, p.y + 1);
				amax(zL, p.z + 1);
			}
			int bound = (int)(lower_bound(minZ.begin() + yL, minZ.end(), zL, greater<int>()) - minZ.begin());
			ans += (ll)(Y - yL) * Z;
			ans -= minZsum[bound] - minZsum[yL];
			ans -= (ll)zL * (Y - bound);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
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
	int n;
	while(~scanf("%d", &n)) {
		int l; int v1; int v2; int k;
		scanf("%d%d%d%d", &l, &v1, &v2, &k);
		double lo = 0, up = l;
		rep(ii, 60) {
			double mid = (lo + up) / 2;
			double t = 0;
			double lastpos = 0;
			rep(i, (n + k - 1) / k) {
				double x = t * v1;
				//lastpos - z * v2 <= x + z * v1
				//lastpos - x <= z * (v1 + v2)
				double z = (lastpos - x) / (v1 + v2);
				x += z * v1;
				t += z;
				//(mid - t - y) * v1 >= l - x - y * v2
				//((mid - t) * v1 - l + x) / (v2 - v1) <= y
				double y = max(0., ((mid - t) * v1 - l + x) / (v1 - v2));
				t += y;
				lastpos = x + y * v2;
			}
			if(t <= mid)
				up = mid;
			else
				lo = mid;
		}
		printf("%.10f\n", (lo + up) / 2);
	}
	return 0;
}
#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

template<typename T>
void fastWalshTransform(T *a, int k) {
	if(k == 0)
		return;
	int n = 1 << (k - 1);
	fastWalshTransform(a, k - 1);
	fastWalshTransform(a + n, k - 1);
	rep(i, n) {
		T x = a[i], y = a[n + i];
		a[i] = x - y;
		a[n + i] = x + y;
	}
}
template<typename T>
void inverseFastWalshTransform(T *a, int k) {
	if(k == 0)
		return;
	int n = 1 << (k - 1);
	inverseFastWalshTransform(a, k - 1);
	inverseFastWalshTransform(a + n, k - 1);
	rep(i, n) {
		T x = a[i], y = a[n + i];
		a[i] = y + x;
		a[n + i] = y - x;
	}
}

int main() {
	int n; int x;
	while(~scanf("%d%d", &n, &x)) {
		double a[128] = {};
		rep(i, x + 1) {
			double P;
			scanf("%lf", &P);
			a[i] = P;
		}
		fastWalshTransform(a, 7);
		rep(i, 1 << 7)
			a[i] = pow(a[i], n);
		inverseFastWalshTransform(a, 7);
		double ans = 1 - a[0] / 128;
		printf("%.10f\n", ans);
	}
	return 0;
}
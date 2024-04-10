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
	int n; int p;
	while (~scanf("%d%d", &n, &p)) {
		vector<int> a(n);
		vector<int> b(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d%d", &a[i], &b[i]);
		double lo = 0, up = 5e18;
		rep(kk, 100) {
			double t = (lo + up) / 2;
			double total = 0;
			rep(i, n)
				total += -min(0., b[i] - t * a[i]) / p;
			if (total <= t)
				lo = t;
			else
				up = t;
		}
		if (lo > 4e18)
			puts("-1");
		else
			printf("%.10f\n", lo);
	}
	return 0;
}
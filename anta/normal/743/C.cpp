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
	// (xy + xz + yz) * n = 2xyz
	int n;
	while (~scanf("%d", &n)) {
		if (n == 1) {
			puts("-1");
			continue;
		}
		for (int x = n; ; x += n) {
			for (int y = x - 1; y >= 1; --y) {
				ll num = (ll)x * y * n;
				ll den = 2LL * x * y - (ll)(x + y) * n;
				if (den > 0 && num % den == 0) {
					ll z = num / den;
					if (0 < z && z != y && z != x && z <= (int)1e9) {
						int a[3] = { x, y, (int)z };
						sort(a, a + 3);
						printf("%d %d %d\n", a[0], a[1], a[2]);
						goto brk;
					}
				}
			}
		}
	brk:;
	}
	return 0;
}
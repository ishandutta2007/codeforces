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
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		const int B = 19;
		vector<vi> cnts(B);
		rep(i, B)
			cnts[i].assign(1 << (B - i), 0);
		rep(i, n) {
			int x;
			scanf("%d", &x);
			if (cnts[0][x] != 0) continue;
			rep(j, B)
				++ cnts[j][x >> j];
		}
		int sum = 0;
		rep(ii, m) {
			int x;
			scanf("%d", &x);
			sum ^= x;
			int ans = 0;
			for (int j = B - 1; j >= 0; -- j) {
				if (cnts[j][(ans ^ sum) >> j] == 1 << j)
					ans |= 1 << j;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
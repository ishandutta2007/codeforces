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
	int n; int k; int x;
	while (~scanf("%d%d%d", &n, &k, &x)) {
		const int X = 1 << 10;
		vector<int> cnt(X, 0), ncnt;
		rep(i, n) {
			int a;
			scanf("%d", &a);
			++ cnt[a];
		}
		rep(kk, k) {
			ncnt.assign(X, 0);
			int num = 0;
			rep(i, X) {
				int t = cnt[i];
				int a = (t + (1 - num % 2)) / 2, b = t - a;
				ncnt[i] += b;
				ncnt[i ^ x] += a;
				num += t;
			}
			cnt.swap(ncnt);
		}
		pii ans(INF, -INF);
		rep(i, X) if(cnt[i] != 0) {
			amin(ans.first, i);
			amax(ans.second, i);
		}
		printf("%d %d\n", ans.second, ans.first);
	}
	return 0;
}
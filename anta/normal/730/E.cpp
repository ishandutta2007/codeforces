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
		vector<int> a(n);
		vector<int> d(n);
		rep(i, n)
			scanf("%d%d", &a[i], &d[i]);
		const int Base = 100;
		rep(i, n) {
			a[i] = a[i] * Base + (n - 1 - i);
			d[i] *= Base;
		}
		vpii ord(n);
		rep(i, n)
			ord[i] = { d[i] >= 0 ? a[i] : -a[i], i };
		sort(ord.begin(), ord.end());
		vector<int> cur = a;
		auto getrank = [&](int x) {
			int r = 0;
			rep(i, n)
				r += cur[i] > cur[x];
			return r;
		};
		int ans = 0;
		rep(k, n) {
			int i = ord[k].second;
			int x = getrank(i);
			cur[i] += d[i];
			int y = getrank(i);
			ans += abs(x - y);
		}
		printf("%d\n", ans);
	}
	return 0;
}
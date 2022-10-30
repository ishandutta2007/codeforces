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
	int n; int s;
	while(~scanf("%d%d", &n, &s)) {
		-- s;
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> cnt(n, 0);
		rep(i, n) if(i != s)
			++ cnt[a[i]];
		int ans = n - 1;
		{
			int bad = n - 1;
			int no = 0;
			rer(i, 1, n - 1) {
				bad -= cnt[i];
				no += cnt[i] == 0;
				int x = min(bad, no);
				amin(ans, bad + (no - x));
			}
		}
		ans += a[s] != 0;
		printf("%d\n", ans);
	}
	return 0;
}
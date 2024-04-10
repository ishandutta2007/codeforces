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
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		vector<int> c(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &c[i]);
		typedef bitset<512> BitSet;
		vector<vector<BitSet>> dp(n + 1, vector<BitSet>(k + 1));
		dp[0][0].set(0);
		rep(i, n) rer(j, 0, k) {
			BitSet x = dp[i][j];
			if(!x.any()) continue;
			dp[i + 1][j] |= x;
			if(j + c[i] <= k)
				dp[i + 1][j + c[i]] |= x | x << c[i];
		}
		vi ans;
		rep(x, k + 1) if(dp[n][k][x])
			ans.push_back(x);
		printf("%d\n", (int)ans.size());
		for(int i = 0; i < (int)ans.size(); ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}
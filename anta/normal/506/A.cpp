#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <unordered_map>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n, d;
	scanf("%d%d", &n, &d);
	const int W = 30000;
	vector<int> cnt(W+1, 0);
	rep(i, n) {
		int p;
		scanf("%d", &p);
		++ cnt[p];
	}
	int L, U;
	{	int x;
		for(L = d, x = d; x <= W; x += L)
			L = max(1, L - 1);
		for(U = d, x = d; x <= W; x += U)
			U = U + 1;
	}
	assert(L <= d && d <= U);
//	cerr << L << ", " << U << endl;
	vector<vi> dp(W+1, vi(U - L + 1, -1));
	dp[d][d - L] = 0;
	int ans = 0;
	rer(i, 0, W) {
		rer(j, L, U) {
			int x = dp[i][j - L];
			if(x == -1) continue;
			x += cnt[i];
			amax(ans, x);
			if(j - 1 > 0 && i + j - 1 <= W) amax(dp[i + j - 1][j - 1 - L], x);
			if(i + j <= W) amax(dp[i + j][j - L], x);
			if(i + j + 1 <= W) amax(dp[i + j + 1][j + 1 - L], x);
		}
	}
	printf("%d\n", ans);
	return 0;
}
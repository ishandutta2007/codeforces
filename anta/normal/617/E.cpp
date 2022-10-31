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
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

vector<int> sqrtSort(const vector<pair<int, int> > &q, const int S) {
	int n = q.size();
	vector<long long> pack(n);
	for(int i = 0; i < n; i ++) {
		pack[i] =
			(long long)(q[i].first / S) << 50 |
			(long long)((q[i].first / S & 1) == 0 ? q[i].second : (1 << 25) - 1 - q[i].second) << 25 |
			i;
	}
	sort(all(pack));
	vector<int> res(n);
	for(int i = 0; i < n; i ++)
		res[i] = pack[i] & ((1 << 25) - 1);
	return res;
}

int main() {
	int n; int m; int K;
	while(~scanf("%d%d%d", &n, &m, &K)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vi sum(n + 1);
		rep(i, n)
			sum[i + 1] = sum[i] ^ a[i];
		vpii queries(m);
		rep(i, m) {
			int l; int r;
			scanf("%d%d", &l, &r), -- l, -- r;
			//l <= i <= j <= r, sum[j+1] ^ sum[i] = K
			queries[i] = mp(l, r);
		}
		vi ord = sqrtSort(queries, 300);
		vi cntL(1 << 20, 0), cntR(1 << 20, 0);
		ll curAns = 0;
		vector<ll> ans(m);
		int L = 0, R = -1;
		for(int ii = 0; ii < m; ii ++) {
			int q = ord[ii];
			int qL = queries[q].first, qR = queries[q].second;
			while(R < qR) {
				R ++;
				//R
				//
				++ cntL[sum[R]], ++ cntR[sum[R + 1]];
				curAns += cntL[K ^ sum[R + 1]];
			}
			while(L > qL) {
				L --;
				//L
				//
				++ cntL[sum[L]], ++ cntR[sum[L + 1]];
				curAns += cntR[K ^ sum[L]];
			}
			while(R > qR) {
				//R
				curAns -= cntL[K ^ sum[R + 1]];
				-- cntL[sum[R]], -- cntR[sum[R + 1]];
				//
				R --;
			}
			while(L < qL) {
				//L
				curAns -= cntR[K ^ sum[L]];
				-- cntL[sum[L]], -- cntR[sum[L + 1]];
				//
				L ++;
			}
			ans[q] = curAns;
		}
		for(int i = 0; i < m; ++ i)
			printf("%I64d\n", ans[i]);
	}
	return 0;
}
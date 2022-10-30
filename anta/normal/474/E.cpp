#define _CRT_SECURE_NO_WARNINGS
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct DynamicRMQ {
	typedef pii Val;
	int n;
	vector<Val> d;
	void init(int nmin) {
		for(n = 1; n < nmin; n *= 2);
		d.assign(n * 2, mp(INF, -1));
	}
	void update(int i, Val x) {
		d[n+i] = x;
		for(int k = (n+i)/2; k > 0; k >>= 1) 
			d[k] = min(d[k * 2], d[k * 2 + 1]);
	}
	Val get(int i) const { return d[n+i]; }
	//[l, r)
	Val query(int l, int r) const {
		Val m = mp(INF, -1);
		for(; l && l + (l&-l) <= r; l += l&-l)
			m = min(m, d[(n+l) / (l&-l)]);
		for(; l < r; r -= r&-r)
			m = min(m, d[(n+r) / (r&-r) - 1]);
		return m;
	}
};



int main() {
	int n, d;
	scanf("%d%d", &n, &d);
	vector<long long> h(n);
	rep(i, n) cin >> h[i];
	vector<long long> values = h;
	sort(all(values));
	values.erase(unique(all(values)), values.end());
	DynamicRMQ rmq; rmq.init(values.size());
	vector<int> dp(n, -1), dpprev(n, -1);
	rep(i, n) {
		dp[i] = 1, dpprev[i] = -1;
		int R = upper_bound(all(values), h[i] - d) - values.begin();
		int L = lower_bound(all(values), h[i] + d) - values.begin();
		{	pii p = rmq.query(0, R);
			if(p.second != -1) {
				int t = dp[p.second];
				if(dp[i] < t + 1) {
					dp[i] = t + 1;
					dpprev[i] = p.second;
				}
			}
		}
		{	pii p = rmq.query(L, values.size());
			if(p.second != -1) {
				int t = dp[p.second];
				if(dp[i] < t + 1) {
					dp[i] = t + 1;
					dpprev[i] = p.second;
				}
			}
		}
		int k = lower_bound(all(values), h[i]) - values.begin();
		rmq.update(k, min(rmq.get(k), mp(-dp[i], i)));
	}
	int ans = -1, k = -1;
	rep(i, n) {
		if(ans < dp[i]) {
			ans = dp[i];
			k = i;
		}
	}
	vector<int> v;
	while(k != -1) {
		v.push_back(k);
		k = dpprev[k];
	}
	reverse(all(v));
	printf("%d\n", ans);
	rep(i, v.size()) {
		if(i != 0) putchar(' ');
		printf("%d", v[i] + 1);
	}
	puts("");
	return 0;
}
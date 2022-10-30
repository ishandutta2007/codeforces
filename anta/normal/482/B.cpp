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
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long, long long> pll; typedef vector<pair<long long, long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	const int B = 30;
	vector<vector<int> > add(B, vector<int>(n+1, 0));
	vector<pair<pii,int> > queries(m);
	rep(i, m) {
		int l, r, q;
		scanf("%d%d%d", &l, &r, &q), -- l;
		queries[i] = mp(mp(l, r), q);
		rep(b, B) if(q >> b & 1) {
			++ add[b][l];
			-- add[b][r];
		}
	}
	vector<int> ans(n, 0);
	vector<vector<int> > sum(B, vector<int>(n+1, 0));
	rep(b, B) {
		rep(i, n) add[b][i+1] += add[b][i];
		rep(i, n) {
			if(add[b][i] > 0)
				ans[i] |= 1 << b;
			sum[b][i+1] = sum[b][i] + (add[b][i] > 0);
		}
	}
	bool ok = true;
	rep(i, m) {
		pii p = queries[i].first;
		int l = p.first, r = p.second, q = queries[i].second;
		rep(b, B) if(~q >> b & 1)
			ok &= sum[b][r] - sum[b][l] != (r - l);
	}
	if(!ok) {
		puts("NO");
	}else {
		puts("YES");
		rep(i, n) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}
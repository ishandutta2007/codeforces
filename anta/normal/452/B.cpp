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

inline unsigned long long nextCombination(unsigned long long comb) {
	unsigned long long x = comb & -comb, y = comb + x;
	return (((comb & ~y) / x) >> 1) | y;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vpii candidates;
	rep(y, 2) rep(x, 2) rer(dy, -2, 2) rer(dx, -2, 2) {
		int yy = y * n + dy, xx = x * m + dx;
		if(yy < 0 || yy > n || xx < 0 || xx > m) continue;
		candidates.push_back(mp(yy, xx));
	}
	sort(all(candidates));
	candidates.erase(unique(all(candidates)), candidates.end());
	int K = candidates.size();
	pair<double,vpii> ans(-1, vpii());
	for(unsigned long long comb = (1ULL << 4) - 1; comb < (1ULL << K); comb = nextCombination(comb)) {
		vpii poses(4);
		int k = 0;
		rep(i, K) if(comb >> i & 1) {
			poses[k ++] = candidates[i];
		}
		do {
			double len = 0;
			rep(i, 3)
				len += hypot(poses[i+1].first-poses[i].first+0., poses[i+1].second-poses[i].second);
			if(ans.first <= len) amax(ans, mp(len, poses));
		}while(next_permutation(all(poses)));
	}
	rep(i, 4)
		printf("%d %d\n", ans.second[i].first, ans.second[i].second);
	return 0;
}
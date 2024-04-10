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
#include <iterator>
#include <bitset>
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

int main() {
	const char *colors = "RGBYW";
	int n;
	scanf("%d", &n);
	int cards = 0;
	rep(i, n) {
		char s[3];
		scanf("%s", s);
		int c = strchr(colors, s[0]) - colors;
		int k = s[1] - '1';
		cards |= 1 << (c * 5 + k);
	}
	int ans = INF;
	rep(colorhint, 1 << 5) rep(valuehint, 1 << 5) {
		vi values(25, 0);
		int cnt = 0;
		rep(i, 5) if(colorhint >> i & 1) {
			cnt ++;
			rep(j, 5)
				values[i * 5 + j] |= 1 << i;
		}
		rep(j, 5) if(valuehint >> j & 1) {
			cnt ++;
			rep(i, 5)
				values[i * 5 + j] |= 1 << (5+j);
		}
		vi s;
		rep(i, 25) if(cards >> i & 1)
			s.push_back(values[i]);
		sort(all(s));
		if(unique(all(s)) == s.end()) {
			amin(ans, cnt);
		}
	}
	printf("%d\n", ans);
	return 0;
}
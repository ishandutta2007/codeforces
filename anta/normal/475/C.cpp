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

int main() {
	int n1, m1;
	while(~scanf("%d%d", &n1, &m1)) {
	int N = max(n1, m1);
	vector<char*> s(N), t(N);
	rep(i, N) {
		s[i] = new char[N+1];
		t[i] = new char[N+1];
	}
	rep(i, n1) scanf("%s", s[i]);
	reu(i, n1, N) rep(j, m1) s[i][j] = '.';
	rep(i, N) {
		reu(j, m1, N) s[i][j] = '.';
		s[i][N] = 0;
	}
	int ans = INF;
	rep(xy, 2) {
		do {
		bool ok = true;
		vpii intervals(N, mp(-1,-1));
		rep(i, N) {
			rep(j, N) if(s[i][j] == 'X') {
				int k = j;
				while(k < N && s[i][k] == 'X') ++ k;
				intervals[i] = mp(j, k);
				reu(l, k, N)
					ok &= s[i][l] == '.';
				break;
			}
			if(!ok) break;
		}
		int sy = 0;
		while(sy < N && intervals[sy].first == -1) ++ sy;
		int ey = sy;
		while(ey < N && intervals[ey].first != -1) ++ ey;
		reu(i, ey, N)
			ok &= intervals[i].first == -1;
		reu(i, sy+1, ey) {
			ok &= intervals[i-1].first <= intervals[i].first;
			ok &= intervals[i-1].second <= intervals[i].second;
		}
		if(!ok)
			break;
		if(sy == -1) {
			ans = 0;
			break;
		}
		int total = 0;
		rep(i, N) total += intervals[i].second - intervals[i].first;
		int w = intervals[sy].second - intervals[sy].first;
		rer(h, 1, ey - sy) {
			int y = sy, x = intervals[sy].first;
			bool b = true;
			int bottom = y;
			while(y + h <= ey) {
				int dx = intervals[y].second - x - w;
				while(bottom < y + h) {
					b &= intervals[bottom].first == x;
					++ bottom;
				}
				++ y, x += dx;
			}
			reu(i, y, ey)
				b &= intervals[i].second == x + w;
			if(b) {
//				cerr << xy << ": " << h << " * " << w << endl;
				amin(ans, h * w);
			}
		}

		}while(0);
		rep(i, N) rep(j, N)
			t[j][i] = s[i][j];
		rep(i, N) rep(j, N)
			s[i][j] = t[i][j];
	}
	if(ans == INF)
		puts("-1");
	else
		printf("%d\n", ans);
	}
	return 0;
}
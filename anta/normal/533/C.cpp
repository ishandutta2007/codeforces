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
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

char memo[2][101][11][11][11][11];

char rec(bool b, int t, int xp, int yp, int xv, int yv) {
	if(xp<0||yp<0||xv<0||yv<0||tie(xp,yp)==tie(xv,yv))
		return 1;
	char &r = memo[b][t][xp][yp][xv][yv];
	if(r != -1) return r;
	if((xp==0&&yp==0)||(xv==0&&yv==0)) return r = 0;
	if(t == 100) return r = 0;
	r = 0;
	if(!b) {
		r |= !rec(!b, t+1, xp-1, yp, xv, yv);
		r |= !rec(!b, t+1, xp, yp-1, xv, yv);
	}else {
		r |= !rec(!b, t+1, xp, yp, xv-1, yv);
		r |= !rec(!b, t+1, xp, yp, xv, yv-1);
		r |= !rec(!b, t+1, xp, yp, xv-1, yv-1);
	}
	return r;
}

bool solve(int xp, int yp, int xv, int yv) {
	if(xp + yp <= max(xv, yv)) {
		return true;
	}else {
		int T = max(xv,yv);
		rep(t, T) {
			if(abs(xp-(xv-t)) + abs(yp-(yv-t)) <= t)
				return true;
		}
		return false;
	}
}

int main() {
	/*
	mset(memo, -1);
	rer(xp,0,10)rer(yp,0,10)if(xp||yp)rer(xv,0,10)rer(yv,0,10)if((xv||yv)&&tie(xp,yp)!=tie(xv,yv)){
		bool ans = rec(false,0,xp,yp,xv,yv) != 0;
		bool s = solve(xp,yp,xv,yv);
		if(ans != s) {
			cerr << xp<<", "<<yp<<", "<<xv<<", "<<yv<<": " << ans << ", " << s << endl;
		}
	}*/
	int xp,yp,xv,yv;
	cin>>xp>>yp>>xv>>yv;
	bool ans = solve(xp,yp,xv,yv);
	puts(ans ? "Polycarp" : "Vasiliy");
	return 0;
}
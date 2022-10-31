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

int memo[102][3];
int ds[102];
int w;
int rec(int i, int t) {
	int &r = memo[i][t+1];
	if(r != -1) return r;
	if(i == 101) return r = t == 0 ? 1 : 0;
	r = 0;
	int d = ds[i];
	rep(a, 2) rep(b, 2) if(a == 0 || b == 0) {
		if((d + t + a) % w == b)
			r |= rec(i+1, (d + t + a) / w);
	}
	return r;
}

int main() {
	int m;
	while(cin >> w >> m) {
		{	int x = m;
			rep(i, 101) {
				ds[i] = x % w;
				x /= w;
			}
		}
		mset(memo, -1);
		int ans = rec(0, 0);
		puts(ans != 0 ? "YES" : "NO");
	}
	return 0;
}
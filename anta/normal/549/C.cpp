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

int memo[101][2][101][101];
int rec(int t, int b, int e, int o) {
	int &r = memo[t][b][e][o];
	if(r != -1) return r;
	if(t == 0) return r = o % 2 == (1 - b);
	r = 0;
	if(e > 0) r |= !rec(t-1, 1-b, e-1, o);
	if(o > 0) r |= !rec(t-1, 1-b, e, o-1);
	return r;
}

bool solve(int t, int e, int o) {
	if(t == 0)
		return o % 2 != 0;
	else if(e <= t / 2 && o <= t / 2)
		return t == e * 2 && t == o * 2 ? false : true;
	else if(e <= t / 2)
		return (e + o + t + 1) % 2 == 0;
	else if(o <= t / 2)
		return false;
	else
		return t % 2 != 0;
}

int main() {
	/*
	mset(memo, -1);
	rer(t,0,10)rer(e,0,10)rer(o,0,10)if(e+o>=t){
		bool a = rec(t, 0, e, o) != 0;
		bool b = solve(t, e, o);
		if(a != b)
			cerr<<t<<", "<<e<<", "<<o<<": " << a << ", " << b << endl;
	}*/
	int n, k;
	while(~scanf("%d%d", &n, &k)) {
		int cnt[2] = {};
		rep(i, n) {
			int a;
			scanf("%d", &a);
			++ cnt[a % 2];
		}
		bool ans = solve(n - k, cnt[0], cnt[1]);	//rec(n - k, 0, cnt[0], cnt[1]) != 0;
		puts(ans ? "Stannis" : "Daenerys");
	}
	return 0;
}
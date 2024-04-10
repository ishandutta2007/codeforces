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

int memo[201][201][201];

int rec(int B, int G, int R) {
	int &r = memo[B][G][R];
	if(r != -1) return r;
	r = 0;
	if(B == 0 && G == 0)
		return r = 1 << 2;
	if(B == 0 && R == 0)
		return r = 1 << 1;
	if(G == 0 && R == 0)
		return r = 1 << 0;
	if(B >= 2) r |= rec(B - 1, G, R);
	if(G >= 2) r |= rec(B, G - 1, R);
	if(R >= 2) r |= rec(B, G, R - 1);
	if(B >= 1 && G >= 1) r |= rec(B - 1, G - 1, R + 1);
	if(B >= 1 && R >= 1) r |= rec(B - 1, G + 1, R - 1);
	if(G >= 1 && R >= 1) r |= rec(B + 1, G - 1, R - 1);
	return r;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		mset(memo, -1);
		string s;
		cin >> s;
		int mask = rec(count(all(s), 'B'), count(all(s), 'G'), count(all(s), 'R'));
		string ans;
		if(mask >> 0 & 1) ans += 'B';
		if(mask >> 1 & 1) ans += 'G';
		if(mask >> 2 & 1) ans += 'R';
		puts(ans.c_str());
	}
	return 0;
}
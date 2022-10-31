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

const int M = 8;
int memo[102][2][M];
string s;

int rec(int i, bool lz, int x) {
	int &r = memo[i][lz][x];
	if(r != -1) return r;
	r = 0;
	if(!lz && x == 0)
		r |= 1;
	reu(j, i+1, s.size())
		r |= rec(j, false, (x * 10 + (s[j] - '0')) % M);
	return r;
}

string anss;
void rec2(int i, bool lz, int x) {
	if(i != 0) anss += s[i];
	if(!lz && x == 0) {
		return;
	}
	reu(j, i+1, s.size()) {
		if(rec(j, false, (x * 10 + (s[j] - '0')) % M)) {
			rec2(j, false, (x * 10 + (s[j] - '0')) % M);
			return;
		}
	}
}

int main() {
	while(cin >> s) {
		s = string("0") + s;
		mset(memo, -1);
		bool ans = rec(0, true, 0) != 0;
		if(!ans) {
			puts("NO");
		}else {
			anss = "";
			rec2(0, true, 0);
			puts("YES");
			cout << anss << endl;
		}
	}
	return 0;
}
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

char *s, *ans;
int n, p;

char memo[1002][26][26][2];
char rec(int i, int a1, int a2, bool gt) {
	char &r = memo[i][a1][a2][gt];
	if(r != -1) return r;
	if(i == n) return r = gt ? 1 : 0;
	r = 0;
	int b = s[i] - 'a';
	rep(a, p) if(gt || a >= b) {
		if((i == 0 || a != a1) && (i <= 1 || a != a2))
			r |= rec(i+1, a, a1, gt || a > b);
	}
	return r;
}
void rec_hukugen(int i, int a1, int a2, bool gt) {
	if(i == n) { ans[n] = 0; return; }
	int b = s[i] - 'a';
	rep(a, p) if(gt || a >= b) {
		if((i == 0 || a != a1) && (i <= 1 || a != a2)) {
			if(rec(i+1, a, a1, gt || a > b)) {
				ans[i] = 'a' + a;
				rec_hukugen(i+1, a, a1, gt || a > b);
				return;
			}
		}
	}
}


int main() {
	scanf("%d%d", &n, &p);
	s = new char[n+1];
	ans = new char[n+1];
	scanf("%s", s);
	mset(memo, -1);
	if(!rec(0,0,0,false)) {
		puts("NO");
	}else {
		rec_hukugen(0,0,0,false);
		puts(ans);
	}
	return 0;
}
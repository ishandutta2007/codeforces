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
#include <functional>
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
	char *s = new char[100001];
	scanf("%s", s);
	int n = strlen(s);
	int addneed = -1, lasti = -1;
	{	int minLv = 0, maxLv = 0;
		rep(i, n) {
			if(s[i] == '(') {
				++ minLv, ++ maxLv;
			}else if(s[i] == ')') {
				-- minLv, -- maxLv;
				amax(minLv, 0);
				if(maxLv < 0) {
					puts("-1");
					return 0;
				}
			}else if(s[i] == '#') {
				minLv = 0;
				-- maxLv;
				if(maxLv < 0) {
					puts("-1");
					return 0;
				}
				lasti = i;
			}
		}
		if(minLv > 0) {
			puts("-1");
			return 0;
		}
		addneed = maxLv;
	}
 	{	int lv = 0;
		rep(i, n) {
			if(s[i] == '(') {
				++ lv;
			}else if(s[i] == ')') {
				-- lv;
			}else if(s[i] == '#') {
				int t = 1 + (i == lasti ? addneed : 0);
				printf("%d\n", t);
				lv -= t;
			}
		}
	}
	return 0;
}
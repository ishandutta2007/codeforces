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

char field[2000][2001];
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	rep(i, n) scanf("%s", field[i]);
	vi spiders(m);
	rep(i, n) rep(j, m) {
		char c = field[i][j];
		if(c == 'L') {
			int x = j - i;
			if(0 <= x && x < m) spiders[x] ++;
		}else if(c == 'R') {
			int x = j + i;
			if(0 <= x && x < m) spiders[x] ++;
		}else if(c == 'U') {
			if(i % 2 == 0) spiders[j] ++;
		}else if(c == 'D') {

		}
	}
	rep(i, m) {
		if(i != 0) putchar(' ');
		printf("%d", spiders[i]);
	}
	puts("");
	return 0;
}
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

int a[100000], b[100000];
long long asum[100001], bsum[100001];
int values[200000];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, m) scanf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + m);
	rep(i, n) asum[i+1] = asum[i] + a[i];
	rep(i, m) bsum[i+1] = bsum[i] + b[i];
	int X = 0;
	rep(i, n) values[X ++] = a[i];
	rep(i, m) values[X ++] = b[i];
	//Sum_{a[i]x} (x - a[i]) + Sum_{xb[i]} (b[i] - x)
	//a[i]b[i]linear
	long long ans = INFL;
	rep(ix, X) {
		int x = values[ix];
		int apos = lower_bound(a, a + n, x) - a - 1;	//a[apos] < x
		int bpos = upper_bound(b, b + m, x) - b;		//b[bpos] > x
		long long cost = 0;
		cost += (ll)x * (apos + 1) - asum[apos+1];
		cost += (bsum[m] - bsum[bpos]) - (ll)x * (m - bpos);
		amin(ans, cost);
	}
	cout << ans << endl;
	return 0;
}
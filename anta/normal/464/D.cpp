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

int main() {
	//()
	int n, k;
	scanf("%d%d", &n, &k);
	const int MaxLv = 900;
	vector<vector<long double> > dp(2, vector<long double>(MaxLv+1, 0));
	rer(j, 1, MaxLv) dp[n&1][j] = 0;
	for(int i = n-1; i >= 0; -- i) rer(j, 1, MaxLv) {
		long double r = 0;
		long double selectedProb = 1.L / k;
		r += (1 - selectedProb) * (dp[i+1&1][j] + 0);
		long double levelupProb = 1.L / (j+1);
		if(j + 1 <= MaxLv)
			r += (dp[i+1&1][j+1] + j * k) / (k * (j+1));
		//Sum [1..j] / j = (j+1)/2
		r += (1-levelupProb) * (dp[i+1&1][j] + (j + 1) * k / 2.L) / k;
		dp[i&1][j] = r;
	}
	long double ans = dp[0&1][1];
	printf("%.15f\n", (double)ans);
	return 0;
}
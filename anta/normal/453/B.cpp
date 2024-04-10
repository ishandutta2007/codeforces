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

template<typename T>T gcd(T x, T y){if(y==0)return x;else return gcd(y,x%y);}

const int primes[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59 };
const int P = sizeof(primes) / sizeof(*primes);
int main() {
	//59
	//1
	//
	//111
	//bitmaskbitDP?
	const int M = 59;
	vector<int> masks(M+1);
	masks.assign(M+1, 0);
	rer(i, 1, M) {
		rep(j, P) if(i % primes[j] == 0)
			masks[i] |= 1 << j;
	}
	vector<vector<char> > values(1 << P);
	rep(i, 1 << P) rer(j, 1, M) if((masks[j] & i) == 0)
		values[i].push_back(j);
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	vector<vector<int> > dp(n+1, vector<int>(1 << P, INF));
	dp[0][0] = 0;
	rep(i, n) {
		int t = a[i];
		rep(j, 1 << P) {
			int x = dp[i][j];
			each(k, values[j])
				amin(dp[i+1][j | masks[*k]], x + abs(*k - t));
		}
	}
	vector<int> ans;
	pair<int,int> p = mp(INF, -1);
	rep(j, 1 << P) amin(p, mp(dp[n][j], j));
	for(int i = n-1; i >= 0; i --) {
		rer(j, 1, M) if((masks[j] & p.second) == masks[j]) {
			int t = p.second & ~masks[j];
			if(p.first == dp[i][t] + abs(j - a[i])) {
				ans.push_back(j);
				p = mp(dp[i][t], t);
				break;
			}
		}
	}
	reverse(all(ans));
	rep(i, n) {
		if(i != 0) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
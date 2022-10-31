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
	int n, p;
	scanf("%d%d", &n, &p), -- p;
	char *s = new char[n+1];
	scanf("%s", s);
	vector<int> costsum(n+1, 0);
	rep(i, n) {
		int a = s[i], b = s[n-1-i];
		if(a > b) swap(a, b);
		int c = min(b - a, a + 26 - b);
		costsum[i+1] = costsum[i] + c;
	}
	if(p >= n / 2) p = n - 1 - p;
	int left = 0, right = (n + 1) / 2 - 1;
	while(left < p && s[left] == s[n-1-left]) ++ left;
	while(p < right && s[right] == s[n-1-right]) -- right;
//	cerr << left <<", " << p << ", " << right << endl;
	int ans = 0;
	ans += costsum[right+1] - costsum[left];
	ans += min(p - left, right - p) + (right - left);
	printf("%d\n", ans);
	return 0;
}
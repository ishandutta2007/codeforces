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

template<typename T>
vector<pair<T,int> > runLength(const T a[], int n) {
	vector<pair<T,int> > r;
	if(n <= 0) return r;
	int cnt = 0;
	for(int i = 0; i <= n; i ++) {
		if(i == n || (i != 0 && a[i] != a[i-1])) {
			r.push_back(make_pair(a[i-1], cnt));
			cnt = 0;
		}
		cnt ++;
	}
	return r;
}

ll sq(int x) { return (ll)x * x; }

int main() {
	char *s = new char[100001];
	scanf("%s", s);
	int n = strlen(s);

	vector<vector<long long> > dp(n+1, vector<long long>(2, 0));
	rer(i, 1, n) rep(b, 2) {
		long long x = 0;
		x += dp[i-1][b];
		x += (i + b) / 2;
		dp[i][b] = x;
//		cerr << i << ", " << b << ": " << x << endl;
	}

	vector<pair<char,int> > runs = runLength(s, n);
	int m = runs.size();
	//head = last 
	long long ans[2] = {};
	long long cnts[2][2] = {};
	int offset = 0;
	rep(i, m) {
		int c = runs[i].first - 'a';
		int len = runs[i].second;

		ans[0] += dp[len][0];
		ans[1] += dp[len][1];

		//x = 
		long long x = len / 2, y = (len + 1) / 2;

		ans[0] += cnts[c][offset % 2] * x + cnts[c][1 - offset % 2] * y;
		ans[1] += cnts[c][offset % 2] * y + cnts[c][1 - offset % 2] * x;

		offset += len;
		cnts[c][    offset % 2] += x;
		cnts[c][1 - offset % 2] += y;
	}
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}
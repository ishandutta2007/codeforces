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

int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int> > a(n, vector<int>(n));
	rep(i, n) rep(j, n) scanf("%d", &a[i][j]);
	pair<long long, pii> eo[2] = { mp(-1,mp(-1,-1)), mp(-1,mp(-1,-1)) };
	vector<long long> md(n + n - 1, 0), sd(n + n - 1, 0);
	rep(i, n) rep(j, n) {
		md[i - j + (n-1)] += a[i][j];
		sd[i + j] += a[i][j];
	}
	rep(i, n) rep(j, n) {
		long long s = md[i - j + (n-1)] + sd[i + j] - a[i][j];
		amax(eo[(i + j) % 2], mp(s, mp(i, j)));
	}
	cout << eo[0].first + eo[1].first << endl;
	cout << eo[0].second.first + 1 << " " << eo[0].second.second + 1 << " ";
	cout << eo[1].second.first + 1 << " " << eo[1].second.second + 1 << endl;
	return 0;
}
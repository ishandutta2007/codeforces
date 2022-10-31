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
#include <list>
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
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

int n, m, i, j, a, b;
int solve(int y, int x) {
	int t = abs(y-i), u = abs(x-j);
	if(t % a != 0 || u % b != 0) return INF;
	t /= a, u /= b;
	if(t % 2 != u % 2) return INF;
	return max(t, u);
}
int main() {
	cin >> n >> m >> i >> j >> a >> b;
	int r = INF;
	r = min(r, solve(1, m));
	r = min(r, solve(n, 1));
	r = min(r, solve(n, m));
	r = min(r, solve(1, 1));
	if(a >= n || b >= m) {
		if(r != 0) r = INF;
	}
	if(r == INF) puts("Poor Inna and pony!");
	else cout << r << endl;
	return 0;
}
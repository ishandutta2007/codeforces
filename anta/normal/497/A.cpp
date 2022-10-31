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
#include <complex>
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
	int n, m;
	scanf("%d%d", &n, &m);
	vector<char*> s(n);
	rep(i, n) s[i] = new char[m+1];
	rep(i, n)
		scanf("%s", s[i]);
	int ans = 0;
	vi v;
	v.push_back(0);
	v.push_back(n);
	rep(j, m) {
		vi w;
		w.push_back(0);
		bool gt = false;
		rep(i, (int)v.size() - 1) {
			int l = v[i], u = v[i+1];
			reu(k, l, u-1) {
				if(s[k][j] > s[k+1][j]) {
					gt = true;
					break;
				}else if(s[k][j] < s[k+1][j]) {
					w.push_back(k+1);
				}
			}
			w.push_back(u);
			if(gt) break;
		}
		if(gt)
			++ ans;
		else
			v = w;
	}
	printf("%d\n", ans);
	return 0;
}
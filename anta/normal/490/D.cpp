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

void solve(int x, map<int,int> &aa) {
	aa.clear();
	rer(cnt2, 0, 31) rer(cnt3, 0, 52) {
		int a = x, m;
		rep(j, cnt3) {
			if(a % 3 != 0) goto fail;
			a = a / 3 * 2;
		}
		rep(j, cnt2) {
			if(a % 2 != 0) goto fail;
			a /= 2;
		}
		m = cnt2 + cnt3;
		if(!aa.count(a))
			aa[a] = m;
		else
			amin(aa[a], m);
		fail:;
	}
}

int main() {
	int a[4];
	rep(i, 4) cin >> a[i];
	map<long long,pair<int,pii> > tt;
	map<int,int> t[4];
	rep(i, 4)
		solve(a[i], t[i]);
	each(i, t[0]) each(j, t[1]) {
		ll x = (ll)i->first * j->first;
		int y = i->second + j->second;
		auto p = mp(y, mp(i->first, j->first));
		if(!tt.count(x))
			tt[x] = p;
		else
			amin(tt[x], p);
	}
	int ansm = INF;
	pii ansp, ansq;
	each(i, t[2]) each(j, t[3]) {
		ll x = (ll)i->first * j->first;
		int y = i->second + j->second;
		if(tt.count(x)) {
			int m = y + tt[x].first;
			if(ansm > m) {
				ansm = m;
				ansp = tt[x].second;
				ansq = mp(i->first, j->first);
			}
		}
	}
	if(ansm == INF) {
		puts("-1");
	}else {
		printf("%d\n%d %d\n%d %d\n",
			ansm, ansp.first, ansp.second, ansq.first, ansq.second);
	}
	return 0;
}
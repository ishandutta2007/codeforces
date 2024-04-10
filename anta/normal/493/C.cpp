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
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	int m;
	scanf("%d", &m);
	vector<int> b(m);
	rep(i, m) scanf("%d", &b[i]);
	vpii v;
	rep(i, n) v.push_back(mp(a[i], 0));
	rep(i, m) v.push_back(mp(b[i], 1));
	sort(all(v));
	vi ds;
	ds.push_back(0);
	each(i, v) ds.push_back(i->first);
	ds.push_back(2000000001);
	sort(all(ds));
	ds.erase(unique(all(ds)), ds.end());
	long long s[2] = { 3LL * n, 3LL * m };
	int k = 0;
	pair<ll,pll> ans = mp(-INFL,mp(-1,-1));
	each(d, ds) {
		while(k < (int)v.size() && v[k].first <= *d) {
			s[v[k].second] -= 1;
			++ k;
		}
		amax(ans, mp(s[0] - s[1], mp(s[0], s[1])));
	}
	cout << ans.second.first << ":" << ans.second.second << endl;
	return 0;
}
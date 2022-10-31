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
	int n;
	scanf("%d", &n);
	vector<int> a(n), b(n);
	rep(i, n)
		scanf("%d%d", &a[i], &b[i]);
	int m;
	scanf("%d", &m);
	vector<int> c(m), d(m), k(m);
	rep(i, m)
		scanf("%d%d%d", &c[i], &d[i], &k[i]);
	vector<pair<int,int> > events;
	rep(i, m)
		events.push_back(mp(2 * c[i] + 0, i));
	rep(i, n)
		events.push_back(mp(2 * a[i] + 1, i));
	sort(all(events));
	multiset<pii> s;
	vi ans(n, -1);
	each(e, events) {
		int i = e->second;
		if(e->first % 2 == 0) {
			s.insert(mp(d[i], i));
		}else {
			multiset<pii>::iterator it = s.lower_bound(mp(b[i], 0));
			if(it == s.end()) {
				puts("NO");
				return 0;
			}
			int j = it->second;
			ans[i] = j;
			if((-- k[j]) == 0)
				s.erase(it);
		}
	}
	puts("YES");
	rep(i, n) {
		if(i != 0) putchar(' ');
		printf("%d", ans[i] + 1);
	}
	puts("");
	return 0;
}
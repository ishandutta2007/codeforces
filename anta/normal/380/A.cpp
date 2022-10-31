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

struct Interval {
	ll right;
	int x, l, c;
	Interval() { }
	Interval(ll ri, int x_, int l_, int c_):
		right(ri), x(x_), l(l_), c(c_) { }
};

const int N = 100010;
int a[N];
int main() {
	int m;
	scanf("%d", &m);
	vector<Interval> intervals;
	ll cntsize = 0;
	rep(i, m) {
		int t;
		scanf("%d", &t);
		if(t == 1) {
			int x;
			scanf("%d", &x);
			if(cntsize < N)
				a[cntsize] = x;
			cntsize ++;
			intervals.pb(Interval(cntsize, x, -1, -1));
		}else {
			int l, c;
			scanf("%d%d", &l, &c);
			rep(j, c) {
				rep(k, l) {
					ll idx = cntsize + (ll)j*l + k;
					if(idx >= N) goto brk;
					a[idx] = a[k];
				}
			}
			brk:;
			cntsize += (ll)l * c;
			intervals.pb(Interval(cntsize, -1, l, c));
		}
	}
	int n;
	scanf("%d", &n);
	vector<pair<ll,int> > queries;
	rep(i, n) {
		ll x;
		scanf("%I64d", &x);
		x --;
		queries.pb(mp(x, i));
	}
	sort(all(queries));
	vi ans(n, -1);
	int inti = 0;
	rep(i, n) {
		ll x = queries[i].first; int &an = ans[queries[i].second];
		while(intervals[inti].right <= x)
			inti ++;
		const Interval &t = intervals[inti];
		if(t.x != -1) an = t.x;
		else {
			ll left = inti == 0 ? 0 : intervals[inti-1].right;
			an = a[(x - left) % t.l];
		}
	}
	rep(i, n) {
		if(i != 0) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
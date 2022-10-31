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
	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	int ma = *max_element(all(a));
	int V = q + 1;
	vector<int> l(V), r(V);
	vector<double> p(V);
	rep(i, q)
		scanf("%d%d%lf", &l[i], &r[i], &p[i]), -- l[i], -- r[i];
	l[q] = 0, r[q] = n-1, p[q] = 0;
	vector<pii> sorted;
	rep(i, V)
		sorted.push_back(mp(r[i] - l[i], i));
	sort(all(sorted));
	vector<vi> g(V);
	vector<int> leafmax(V);
	{	map<int,int> t;
		rep(i, n)
			t[i] = -1;
		rep(ix, sorted.size()) {
			int i = sorted[ix].second;
			auto left = t.lower_bound(l[i]);
			auto right = t.upper_bound(r[i]);
			int mx = -INF;
			for(auto it = left; it != right; ++ it) {
				if(it->second == -1) {
					amax(mx, a[it->first]);
				}else {
//					cerr << l[i] << "," << r[i] << " -> " << l[it->second] << "," << r[it->second] << endl;
					g[i].push_back(it->second);
				}
			}
			leafmax[i] = mx;
			t.erase(left, right);
			t.insert(mp(l[i], i));
		}
	}
	//[l[i],r[i]]ma+j
	vector<vector<double> > dp(V, vector<double>(q * 2 + 1));
	rep(ix, sorted.size()) {
		int i = sorted[ix].second;
		double pi = p[i];
		int mx = leafmax[i];
		rer(j, -q, q) {
			double x = 1, y = 1;
			each(k, g[i]) {
				x *= dp[*k][q+j];
				if(j-1 >= -q)
					y *= dp[*k][q+j-1];
			}
			if(mx > ma+j) x = 0;
			if(mx+1 > ma+j) y = 0;
			double r = (1-pi) * x + pi * y;
			dp[i][q+j] = r;
		}
	}
	double ans = 0;
	rer(j, 0, q) {
		double x = dp[q][q+j] - dp[q][q+j-1];
//		cerr << ma+j << ": " << x << endl;
		ans += x * (ma+j);
	}
	printf("%.10f\n", ans);
	return 0;
}
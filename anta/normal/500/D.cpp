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

vector<vpii> g;
vi subt;
long long sumofdist;
int dfs(int i, int p, int w) {
	int sz = 1;
	each(j, g[i]) if(j->first != p)
		sz += dfs(j->first, i, w + j->second);
	each(j, g[i]) if(j->first != p)
		sumofdist += (long long)j->second * subt[j->first] * ((int)g.size() - subt[j->first]);
	return subt[i] = sz;
}

int main() {
	int n;
	scanf("%d", &n);
	//  _{c1,c2,c3,c1!=c2,c2!=c3,c1!=c3} d(c1,c2)+d(c2,c3)+d(c1,c3)
	//= _{c1,c2,c3} d(c1,c2)+d(c2,c3)+d(c1,c3) - 3 _{c1,c2} 2 d(c1,c2)
	//= (3n-6) _{c1,c2} d(c1,c2)
	//(div n(n-1)(n-2) )
	g.assign(n, vpii());
	vpii edges(n-1); vi lens(n-1);
	rep(i, n-1) {
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l), -- a, -- b;
		edges[i] = mp(a, b);
		lens[i] = l;
		g[a].push_back(mp(b, l));
		g[b].push_back(mp(a, l));
	}
	subt.assign(n, -1);
	sumofdist = 0;
	dfs(0, -1, 0);
	int q;
	scanf("%d", &q);
	rep(i, q) {
		int r, w;
		scanf("%d%d", &r, &w), -- r;
		int a = edges[r].first, b = edges[r].second;
		if(subt[a] > subt[b]) swap(a, b);
		sumofdist -= (long long)lens[r] * subt[a] * (n - subt[a]);
		lens[r] = w;
		sumofdist += (long long)lens[r] * subt[a] * (n - subt[a]);
		double ans = (double)sumofdist * 2 * (3 * n - 6) / n / (n-1) / (n-2);
		printf("%.10f\n", ans);
	}
	return 0;
}
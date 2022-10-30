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

vector<int> smallestPrimeFactor;
void getSmallestPrimeFactors(int n) {
	n = max(n, 1);
	if((int)smallestPrimeFactor.size() >= n+1) return;
	smallestPrimeFactor.assign(n+1, 0);
	smallestPrimeFactor[1] = 1;
	rer(i, 2, n) if(!smallestPrimeFactor[i]) {
		smallestPrimeFactor[i] = i;
		if((ll)i * i <= n)
		for(int j = i * i; j <= n; j += i)
			if(!smallestPrimeFactor[j]) smallestPrimeFactor[j] = i;
	}
}

vector<int> a;
vector<vi> g;
vector<vi> stk;
vector<pii> ans;
vector<int> depth;

void dfs(int i, int parent) {
	{	int x = a[i];
		while(x > 1) {
			int p = smallestPrimeFactor[x];
			vi &v = stk[p];
			if(!v.empty()) amax(ans[i], mp(depth[v.back()], v.back()));
			v.push_back(i);
			while(x % p == 0) x /= p;
		}
	}
	each(j, g[i]) if(*j != parent) {
		dfs(*j, i);
	}
	{	int x = a[i];
		while(x > 1) {
			int p = smallestPrimeFactor[x];
			stk[p].pop_back();
			while(x % p == 0) x /= p;
		}
	}
}

void getdepth(int i, int p, int d) {
	depth[i] = d;
	each(j, g[i]) if(*j != p)
		getdepth(*j, i, d + 1);
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	a.resize(n);
	rep(i, n) scanf("%d", &a[i]);
	g.assign(n, vi());
	rep(i, n-1) {
		int x, y;
		scanf("%d%d", &x, &y), -- x, -- y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	depth.assign(n, 0);
	getdepth(0, -1, 0);
	getSmallestPrimeFactors(2000000);
	stk.assign(2000001, vi());
	bool changed = true;
	rep(ii, q) {
		if(changed) {
			ans.assign(n, mp(-1, -1));
			dfs(0, -1);
			changed = false;
		}
		int ty;
		scanf("%d", &ty);
		if(ty == 1) {
			int v;
			scanf("%d", &v), -- v;
			printf("%d\n", ans[v].first == -1 ? -1 : ans[v].second + 1);
		}else {
			int v, w;
			scanf("%d%d", &v, &w), -- v;
			a[v] = w;
			changed = true;
		}
	}
	return 0;
}
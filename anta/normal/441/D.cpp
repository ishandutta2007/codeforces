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

void permutationToCycles(int p[], int n, vector<vi> &cycles, vector<int> &cycleidx) {
	vector<bool> vis(n, false);
	cycles.clear();
	cycleidx.assign(n, -1);
	rep(i, n) if(!vis[i]) {
		int j = i;
		vi cycle;
		do {
			cycle.push_back(j);
			cycleidx[j] = cycles.size();
			vis[j] = true;
			j = p[j];
		}while(j != i);
		cycles.push_back(cycle);
	}
}

int main() {
	//swap = n - 
	//swap2
	//swap
	//
	int n;
	scanf("%d", &n);
	static int p[3000];
	rep(i, n) {
		scanf("%d", &p[i]);
		p[i] --;
	}
	int m;
	scanf("%d", &m);
	vector<vi> cycles;
	vector<int> cycleidx;
	permutationToCycles(p, n, cycles, cycleidx);
	int numcycles = cycles.size(), needcycle = n - m;
	int k = abs(numcycles - needcycle);
	vpii ans;
	if(numcycles < needcycle) {
		rep(i, k) {
			int x = 0;
			while(x < n && cycles[cycleidx[x]].size() == 1) x ++;
			if(x == n) cerr << "Error 1!!!" << endl;
			int y = INF;
			vi cycle = cycles[cycleidx[x]];
			each(j, cycle) if(*j != x)
				amin(y, *j);
			swap(p[x], p[y]);
			ans.push_back(mp(x, y));
			permutationToCycles(p, n, cycles, cycleidx);	//O(n)
		}
	}else {
		rep(i, k) {
			int x = 0;
			int y = 1;
			while(y < n && cycleidx[x] == cycleidx[y]) y ++;
			if(y == n) cerr << "Error 2!!!" << endl;
			swap(p[x], p[y]);
			ans.push_back(mp(x, y));
			permutationToCycles(p, n, cycles, cycleidx);
		}
	}
	printf("%d\n", (int)ans.size());
	rep(i, ans.size()) {
		if(i != 0) putchar(' ');
		printf("%d %d", ans[i].first + 1, ans[i].second + 1);
	}
	puts("");
	return 0;
}
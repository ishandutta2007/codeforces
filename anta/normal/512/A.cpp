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
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int impossible() {
	puts("Impossible");
	return 0;
}

bool topologicalSort(const vector<vi> &g, vi &ord) {
	int n = g.size();
	vi deg(n);
	rep(i, n) each(j, g[i]) deg[*j] ++;
	ord.assign(n, -1);
	int t = 0;
	rep(i, n) if(deg[i] == 0) ord[t ++] = i;
	for(int h = 0; h < t; h ++) {
		int v = ord[h];
		each(j, g[v])
			if(-- deg[*j] == 0)
				ord[t ++] = *j;
	}
	return t == n;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<string> name(n);
	rep(i, n)
		cin >> name[i];
	vector<bool> ok(n-1, false);
	vector<vi> g(26);
	rep(k, 101) {
		rep(i, n-1) if(!ok[i]) {
			char a = k >= (int)name[i].size() ? 0 : name[i][k];
			char b = k >= (int)name[i+1].size() ? 0 : name[i+1][k];
			if(a == b) {
				if(a == 0 && b == 0)
					return impossible();
			}else {
				if(a == 0) {
				}else if(b == 0) {
					return impossible();
				}else {
					g[a - 'a'].push_back(b - 'a');
				}
				ok[i] = true;
			}
		}
	}
	vi ord;
	if(!topologicalSort(g, ord)) {
		return impossible();
	}else {
		rep(i, 26)
			putchar('a' + ord[i]);
		puts("");
	}
	return 0;
}
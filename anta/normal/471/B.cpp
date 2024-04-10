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

vector<vi> a;
vector<int> tmp;
vector<vi> ans;

bool dfs(int h) {
	if(h >= (int)a.size()) {
		ans.push_back(tmp);
		return ans.size() == 3;
	}
	if(a[h].empty()) return dfs(h+1);
	rep(i, a[h].size()) {
		tmp.push_back(a[h][i]);
		rep(j, a[h].size()) if(i != j)
			tmp.push_back(a[h][j]);
		if(dfs(h+1)) return true;
		rep(j, a[h].size()) if(i != j)
			tmp.pop_back();
		tmp.pop_back();
	}
	return false;
}

int main() {
	int n;
	scanf("%d", &n);
	int M = 2000;
	a.assign(M+1, vi());
	rep(i, n) {
		int h;
		scanf("%d", &h);
		a[h].push_back(i);
	}
	tmp.clear();
	ans.clear();
	if(!dfs(1)) {
		puts("NO");
	}else {
		puts("YES");
		rep(k, 3) {
			rep(i, ans[k].size()) {
				if(i != 0) putchar(' ');
				printf("%d", ans[k][i] + 1);
			}
			puts("");
		}
	}
	return 0;
}
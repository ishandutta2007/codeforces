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

int a[100000];
int main() {
	int n, k, p;
	scanf("%d%d%d", &n, &k, &p);
	rep(i, n) scanf("%d", &a[i]);
	vector<int> eo[2];
	rep(i, n) eo[a[i] & 1].push_back(i);
	vector<vi> ans;
	rep(i, k - p) {
		ans.push_back(vi());
		if(eo[1].empty()) goto fail;
		ans.back().push_back(eo[1].back());
		eo[1].pop_back();
	}
	rep(i, p) {
		ans.push_back(vi());
		if(!eo[0].empty()) {
			ans.back().push_back(eo[0].back());
			eo[0].pop_back();
		}else if(eo[1].size() >= 2) {
			ans.back().push_back(eo[1].back());
			eo[1].pop_back();
			ans.back().push_back(eo[1].back());
			eo[1].pop_back();
		}else {
			goto fail;
		}
	}
	while(!eo[0].empty()) {
		ans.back().push_back(eo[0].back());
		eo[0].pop_back();
	}
	while(!eo[1].empty()) {
		if(eo[1].size() == 1) goto fail;
		ans.back().push_back(eo[1].back());
		eo[1].pop_back();
		ans.back().push_back(eo[1].back());
		eo[1].pop_back();
	}
	if(0) {
fail:	puts("NO");
	}else {
		puts("YES");
		rep(i, ans.size()) {
			printf("%d", (int)ans[i].size());
			rep(j, ans[i].size())
				printf(" %d", a[ans[i][j]]);
			puts("");
		}
	}
	return 0;
}
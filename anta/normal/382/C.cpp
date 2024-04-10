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

int a[100000];
int main() {
	int n;
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	sort(a, a+n);
	vi ans;
	if(n == 1) {
		puts("-1");
		return 0;
	}else if(n == 2) {
		int d = a[1] - a[0];
		if(d > 0 && d % 2 == 0) ans.pb(a[0] + d / 2);
		ans.pb(a[0] - d);
		ans.pb(a[1] + d);
	}else {
		map<int,int> ds;
		rep(i, n-1) ds[a[i+1] - a[i]] ++;
		if(ds.size() == 1) {
			int d = ds.begin()->first;
			ans.pb(a[0] - d);
			ans.pb(a[n-1] + d);
		}else if(ds.size() == 2) {
			pii d1 = *ds.begin(), d2 = *(++ds.begin());
//			cerr << d1.first << ", " << d1.second << endl;
//			cerr << d2.first << ", " << d2.second << endl;
			rep(d12, 2) {
				if(d1.second == 1 && d1.first == d2.first * 2) {
					rep(i, n-1) if(a[i+1] - a[i] == d1.first)
						ans.push_back(a[i] + d2.first);
				}
				swap(d1, d2);
			}
		}
	}
	sort(all(ans));
	ans.erase(unique(all(ans)), ans.end());
	printf("%d\n", (int)ans.size());
	rep(i, ans.size()) {
		if(i != 0) putchar(' ');
		printf("%d", ans[i]);
	}
	if(!ans.empty()) puts("");
	return 0;
}
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

const int fact[11] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
int hashperm(int a[10], int n) {
	
	int t[10];
	rep(i, 10) t[i] = a[i];
	int h = 0;
	rep(i, n-1) {
		h += fact[n-1-i] * t[i];
		reu(j, i+1, n-1)
			if(t[i] < t[j]) -- t[j];
	}
	return h;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		int k1, k2;
		scanf("%d", &k1);
		int a[10];
		rep(i, k1) scanf("%d", &a[i]), -- a[i];
		scanf("%d", &k2);
		rep(i, k2) scanf("%d", &a[k1 + i]), -- a[k1 + i];
		int H = fact[n] * (n+1);
		vector<bool> vis(H, false);
		int s = k1, t = 0, w;
		for(; ; ++ t) {
//			rep(i,s)cerr<<a[i]+1;cerr<<"|";rep(i,n-s)cerr<<a[s+i]+1;cerr<<endl;
			if(s == 0) {
				w = 2;
				break;
			}
			if(s == n) {
				w = 1;
				break;
			}
			int h = hashperm(a, n) * (n+1) + s;
			if(vis[h]) {
				w = -1;
				break;
			}
			vis[h] = true;
			int l = a[0], r = a[s];
			if(l > r) {
				rep(j, s-1) a[j] = a[j+1];
				a[s-1] = r;
				a[s] = l;
				++ s;
			}else {
				rep(j, s-1) a[j] = a[j+1];
				rep(j, n-s) a[s+j-1] = a[s+j+1];
				a[n-2] = l;
				a[n-1] = r;
				-- s;
			}
		}
		if(w == -1) {
			puts("-1");
		}else {
			printf("%d %d\n", t, w);
		}
	}

	return 0;
}
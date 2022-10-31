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

int main() {
	int n;
	while(cin >> n) {
		vi a(n);
		rep(i, n) scanf("%d", &a[i]);
		int X = *max_element(all(a));
		vi cnt(X+1, 0), L(X+1, INF), R(X+1, -INF);
		rep(i, n) {
			++ cnt[a[i]];
			amin(L[a[i]], i);
			amax(R[a[i]], i);
		}
		int p = *max_element(all(cnt));
		pair<int,pii> ans(INF,mp(-1,-1));
		rer(x, 0, X) if(cnt[x] == p)
			amin(ans, mp(R[x] - L[x], mp(L[x], R[x])));
		cout << ans.second.first + 1 << " " << ans.second.second + 1 << endl;
	}
	return 0;
}
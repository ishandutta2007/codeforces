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
	scanf("%d", &n);
	int N = (1 << (n+1)) - 1;
	vector<int> a(N+1);
	rep(i, N - 1) scanf("%d", &a[i+2]);
	vector<int> b(N+1);
	reu(i, 1 << n, 1 << (n+1)) {
		int x = i, t = 0;
		while(x != 1) {
			t += a[x];
			x /= 2;
		}
		x = i;
		b[i] = t;
		while(x != 1) {
			x /= 2;
			amax(b[x], t);
		}
	}
	int ans = 0;
	reu(i, 2, 1 << (n+1))
		ans += b[i / 2] - b[i];
	printf("%d\n", ans);
	return 0;
}
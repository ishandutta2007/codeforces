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
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

template<typename T>
void fastWalshTransform(T *a, int k) {
	if(k == 0)
		return;
	int n = 1 << (k - 1);
	fastWalshTransform(a, k - 1);
	fastWalshTransform(a + n, k - 1);
	rep(i, n) {
		T x = a[i], y = a[n + i];
		a[i] = x - y;
		a[n + i] = x + y;
	}
}
template<typename T>
void fastWalshTransformInverse(T *a, int k) {
	if(k == 0)
		return;
	int n = 1 << (k - 1);
	fastWalshTransformInverse(a, k - 1);
	fastWalshTransformInverse(a + n, k - 1);
	rep(i, n) {
		T x = a[i], y = a[n + i];
		a[i] = y + x;
		a[n + i] = y - x;
	}
}

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<string> table(n);
		rep(i, n)
			cin >> table[i];
		vector<long long> a(1 << n), b(1 << n);
		rep(j, m) {
			int x = 0;
			rep(i, n)
				x = x << 1 | (table[i][j] - '0');
			++ a[x];
		}
		rep(i, 1 << n) {
			int p = 0;
			rep(j, n)
				p += i >> j & 1;
			b[i] = min(p, n - p);
		}
		fastWalshTransform(a.data(), n);
		fastWalshTransform(b.data(), n);
		vector<long long> c(1 << n);
		rep(i, 1 << n) c[i] = a[i] * b[i];
		fastWalshTransformInverse(c.data(), n);
		int ans = (int)(*min_element(all(c)) >> n);
		printf("%d\n", ans);
	}
	return 0;
}
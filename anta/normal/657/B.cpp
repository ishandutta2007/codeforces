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
#include <fstream>
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

int main() {
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		vector<int> a(n + 1);
		for(int i = 0; i < n + 1; ++ i)
			scanf("%d", &a[i]);
		int X = n + 1 + 100;
		vector<long long> v;
		int pm;
		for(pm = 0; ; ++ pm) {
			v.assign(X, 0);
			rep(i, X - 1) {
				if(i <= n) v[i] += a[i];
				long long q = v[i] / 2 - (v[i] % 2 == -1);
				v[i] -= q * 2;
				v[i + 1] += q;
			}
			if(v.back() >= 0) {
				assert(v.back() == 0);
				break;
			}
			rep(i, n + 1)
				a[i] = -a[i];
		}
//		cerr << pm << ", "; rep(i, X) cerr << v[i]; cerr << endl;
		vector<int> cnt(X + 1);
		rep(i, X)
			cnt[i + 1] = cnt[i] + (v[i] != 0);
		int ans = 0;
		rer(i, 0, n) {
			const int Y = 40;
			if(cnt[i] == 0 && cnt[X] - cnt[i + Y] == 0) {
				long long t = 0;
				rep(j, Y)
					t |= v[i + j] << j;
				assert(t != 0);
				long long c = pm == 0 ? a[i] - t : -a[i] + t;
				if(abs(c) <= k && !(i == n && c == 0)) {
//					cerr << i << ": " << c << endl;
					++ ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
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
		rep(i, n)
			scanf("%d", &a[i]);
		const int B = 17;
		vi popcnt(1 << B, 0);
		rep(i, 1 << B) rep(j, B)
			popcnt[i] += i >> j & 1;
		int ans = INF;
		rep(p, B) {
			int t = 0;
			vi costs(1 << B, 0), cnts(1 << B, 0);
			rep(i, n) {
				int x = a[i];
				if(popcnt[x] < p) { t = INF; break; }
				while(popcnt[x] > p) x >>= 1, ++ t;
				if(x == 0) {
					++ cnts[0];
					continue;
				}
				int y = x;
				rep(c, B) {
					if(y >= (1 << B)) break;
					++ cnts[y];
					costs[y] += c;
					y <<= 1;
				}
				y = x;
				rer(c, 1, B) {
					if((y & 1) == 1) break;
					y >>= 1;
					++ cnts[y];
					costs[y] += c;
				}
			}
			if(t == INF) continue;
			int u = INF;
			rep(x, 1 << B) if(cnts[x] == n)
				amin(u, costs[x]);
			amin(ans, t + u);
		}
		cout << ans << endl;
	}
	return 0;
}
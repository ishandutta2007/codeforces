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

unsigned xor128() {
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

int main() {
	int n; int K; int b; int c;
	while(~scanf("%d%d%d%d", &n, &K, &b, &c)) {
		amin(b, c * 5);
		vector<int> t(n);
		for(int i = 0; i < n; ++ i) {
			scanf("%d", &t[i]);
			//			t[i] = xor128() % (int)2e9 - (int)1e9;
			t[i] += (int)1e9;
		}
		sort(all(t));
		map<int, int> cntmap;
		rep(i, n) ++ cntmap[t[i]];
		long long ans = INFL;
		each(i, cntmap) if(i->second >= K)
			ans = 0;
		if(ans == 0) {
			puts("0");
			continue;
		}
		rep(m, 5) {
			vi candidates;
			rep(i, n) rep(j, 5) if((t[i] + j) % 5 == m)
				candidates.push_back(t[i] + j);
			sort(candidates.begin(), candidates.end());
			candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
			vector<long long> v[5], sums[5];
			int pos[5] = {};
			rep(k, 5) sums[k].push_back(0);
			int ti = 0;
			for(int x : candidates) {
				for(; ti < n && t[ti] <= x; ++ ti) {
					int k = (x - t[ti]) % 5, a = (t[ti] - m + 4) / 5;
					v[k].push_back(a);
					sums[k].push_back(sums[k].back() + a);
				}
				long long a = (x - m) / 5;
				while(1) {
					int num = 0;
					long long sum = 0;
					pair<long long, int> ma(-1, -1);
					rep(k, 5) {
						int t = v[k].size();
						sum += (ll)k * c * (t - pos[k]);
						sum += (a * (t - pos[k]) - (sums[k].back() - sums[k][pos[k]])) * b;
						num += t - pos[k];
						if(t > pos[k])
							amax(ma, mp((ll)k * c + (a - v[k][pos[k]]) * b, k));
					}
					if(num <= K) {
						if(num == K)
							amin(ans, sum);
						break;
					}
					++ pos[ma.second];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
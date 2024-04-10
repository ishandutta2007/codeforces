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

typedef pair<int,int> Seg1D;
inline bool commonSeg1D(const Seg1D &x, const Seg1D &y) {
	return y.first < x.second && x.first < y.second;
}
typedef pair<Seg1D,Seg1D> Seg2D;

inline bool commonArea2D(const Seg2D &a, const Seg2D &b) {
	return commonSeg1D(a.first, b.first) && commonSeg1D(a.second, b.second);
}

int main() {
	pii ps[3];
	while(cin >> ps[0].first >> ps[0].second >> ps[1].first >> ps[1].second >> ps[2].first >> ps[2].second) {
		int area = 0;
		rep(i, 3)
			area += ps[i].first * ps[i].second;
		int N = (int)(sqrt(area * 1.) + .5);
		if(N * N != area) {
			puts("-1");
			continue;
		}
		vector<string> ans(N, string(N, '?'));
		rep(rot, 1 << 3) {
			rep(i, 3) if(rot >> i & 1)
				swap(ps[i].first, ps[i].second);
			vi ys, xs;
			rep(i, 1 << 3) {
				int y = 0, x = 0;
				rep(j, 3) if(i >> j & 1) {
					y += ps[j].first;
					x += ps[j].second;
				}
				ys.push_back(y);
				xs.push_back(x);
			}
			sort(ys.begin(), ys.end());
			ys.erase(unique(ys.begin(), ys.end()), ys.end());
			sort(xs.begin(), xs.end());
			xs.erase(unique(xs.begin(), xs.end()), xs.end());

			vi perm(3);
			rep(i, 3) perm[i] = i;
			rep(ord, 3) {
				rep(y1i, ys.size()) rep(x1i, xs.size())
				rep(y2i, ys.size()) rep(x2i, xs.size()) {
					int y1 = ys[y1i], x1 = xs[x1i];
					int y2 = ys[y2i], x2 = xs[x2i];
					Seg2D a[3];
					a[0] = Seg2D(Seg1D(0, ps[perm[0]].first), Seg1D(0, ps[perm[0]].second));
					a[1] = Seg2D(Seg1D(y1, y1 + ps[perm[1]].first), Seg1D(x1, x1 + ps[perm[1]].second));
					a[2] = Seg2D(Seg1D(y2, y2 + ps[perm[2]].first), Seg1D(x2, x2 + ps[perm[2]].second));

					bool ok = true;
					rep(i, 3) rep(j, i)
						ok &= !commonArea2D(a[i], a[j]);
					rep(i, 3) {
						ok &= a[i].first.second <= N;
						ok &= a[i].second.second <= N;
					}
					if(ok) {
						rep(i, 3) {
							reu(y, a[i].first.first, a[i].first.second)
								reu(x, a[i].second.first, a[i].second.second)
									ans[y][x] = (char)('A' + perm[i]);
						}
						goto okok;
					}
				}
				rotate(perm.begin(), perm.begin() + 1, perm.end());
			}
			rep(i, 3) if(rot >> i & 1)
				swap(ps[i].first, ps[i].second);
		}
		if(0) {
		okok:;
			printf("%d\n", N);
			rep(i, N)
				puts(ans[i].c_str());
		} else {
			puts("-1");
		}
	}
	return 0;
}
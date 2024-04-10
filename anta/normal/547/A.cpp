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

int exgcd(int a, int b, int &g) {
	int u = 1, v = 0;
	while(b) {
		int t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	g = a;
	return u;
}

//()
//x mod n1 = a1, x mod n2 = a2  x 
//
//-1

long long crt(long long a1, long long n1, int a2, int n2, long long &resn) {
	int t, g;
	t = exgcd(n1 % n2, n2, g);
	if((a1 - a2) % g != 0) return -1;
	int n2_g = n2 / g;
	int d = (a2 - a1) / g % n2_g;
	int h = (long long)d * t % n2_g;
	if(h < 0) h += n2_g;
	long long n = n1 * n2_g;
	long long a = a1 + n1 * h;
	resn = n;
	return a;
}

int main() {
	int m;
//	while(1) {
		scanf("%d", &m);
//		m=rand()%100+1;
		int h[2], a[2], x[2], y[2];
		rep(k, 2) {
			scanf("%d%d%d%d", &h[k], &a[k], &x[k], &y[k]);
//			h[k]=rand()%m;a[k]=rand()%m;x[k]=rand()%m;y[k]=rand()%m;
		}
		vi simu[2];
		int head[2], cyclelen[2], posa[2];
		rep(k, 2) {
			vi hist(m, -1);
			posa[k] = -1;
			simu[k].assign(m+1, -1);
			int t = h[k];
			rep(i, m+1) {
				if(hist[t] != -1) {
					head[k] = hist[t];
					cyclelen[k] = i - hist[t];
					for(; i < m+1; ++ i) {
						simu[k][i] = t;
						t = ((ll)x[k] * t + y[k]) % m;
					}
					break;
				}
				simu[k][i] = t;
				hist[t] = i;
				if(t == a[k])
					posa[k] = i;
				t = ((ll)x[k] * t + y[k]) % m;
			}
		}
		/*
		ll naiveans = -1;
		{	int t0 = h[0], t1 = h[1];
			rep(i, m*m) {
				if(t0 == a[0] && t1 == a[1]) {
					naiveans = i;
					break;
				}
				t0 = ((ll)x[0] * t0 + y[0]) % m;
				t1 = ((ll)x[1] * t1 + y[1]) % m;
			}
		}*/
		ll ans = -1;
		rep(i, max(head[0], head[1])) {
			if(simu[0][i] == a[0] && simu[1][i] == a[1]) {
				ans = i;
				break;
			}
		}
		if(ans == -1 && posa[0] >= head[0] && posa[1] >= head[1]) {
			int h = max(head[0], head[1]);
			int p[2];
			rep(k, 2) {
				int u = cyclelen[k];
				p[k] = ((posa[k] - h) % u + u) % u;
			}
			//ans mod cyclelen[k] = p[k]
			ll dummy;
			ll t = crt(p[0], cyclelen[0], p[1], cyclelen[1], dummy);
			if(t != -1)
				ans = h + t;
		}
		cout << ans << endl;
//		if(ans != naiveans)
//			cerr << ans << " != " << naiveans << endl;
//	}
	return 0;
}
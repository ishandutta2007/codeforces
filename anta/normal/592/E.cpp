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

struct Ratio {
	int x, y;
	Ratio() {}
	Ratio(int x_, int y_) : x(x_), y(y_) {}
	bool operator<(const Ratio &that) const {
		return (ll)x * that.y < (ll)y * that.x;
	}
};
ostream& operator<<(ostream &o, const Ratio& p) { o << p.x << "/" << p.y; return o; }

int signum(int x) { return x < 0 ? -1 : x == 0 ? 0 : 1; }
bool check(pii p, pii q) { return (ll)p.first * q.second > (ll)q.first * p.second; }

int main() {
	//r_i / w_i <(sign w_i * sign w_j)> r_j / w_j

	//(1,1),(1,-1)
	//-1 > 1
	int n; int c; int d;
	while(1) {
		if(!~scanf("%d%d%d", &n, &c, &d))break;
//		n = 10, c = d = 5;
		vector<pair<Ratio,int> > ratios;
		vpii pairs(n);
		rep(i, n) {
			int rr; int ww;
			scanf("%d%d", &rr, &ww);
//			do { rr = rand() % 10, ww = rand() % 10; } while(rr==c&&ww==d);
			int r = rr - c, w = ww - d;
			pairs[i] = mp(r, w);
			if(w == 0) {
				int s = signum(r);
				ratios.push_back(mp(Ratio(1, 0), s));
			} else {
				int s = signum(w);
				ratios.push_back(mp(Ratio(r * s, w * s), s));
			}
		}
		sort(all(ratios));
		//a < b < c: sig(a) != sig(c)
		vector<pair<int, int> > v;
		vector<Ratio> w;
		for(int i = 0; i < (int)ratios.size(); ) {
			Ratio r = ratios[i].first;
			v.push_back(mp(0, 0));
			w.push_back(r);
			for(; i < (int)ratios.size() && !(r < ratios[i].first); ++ i) {
				int s = ratios[i].second;
				++ (s == 1 ? v.back().first : v.back().second);
			}
		}
		long long ans = 0;
		ll cnt1[2] = {}, cnt2[2] = {};
		rep(i, v.size()) {
			ans += cnt2[0] * v[i].first;
			ans += cnt2[1] * v[i].second ;
			cnt2[0] += cnt1[0] * v[i].second;
			cnt2[1] += cnt1[1] * v[i].first;
			cnt1[0] += v[i].first;
			cnt1[1] += v[i].second;
		}
		cout << ans << endl;
		/*
		ll naiveans = 0;
		rep(i, n) rep(j, n)if(i != j)rep(k, n)if(k != i&&k != j)
			naiveans += check(pairs[i], pairs[j]) && check(pairs[j], pairs[k]) && check(pairs[k], pairs[i]);
		assert(naiveans%3==0);
		naiveans /= 3;
		if(ans != naiveans)
			cerr << ans << " != " << naiveans << endl;*/
	}
	return 0;
}
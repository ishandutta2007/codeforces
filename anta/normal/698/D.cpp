#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct P {
	typedef int T; typedef ll T2;	//T2{a*b | a:T, b:T}^Cv
	T x, y;
	P(T x_, T y_) : x(x_), y(y_) {}
	P() : x(0), y(0) {}
};
inline P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
inline P::T2 norm(const P& a) { return (P::T2)a.x*a.x + (P::T2)a.y*a.y; }

int compareAngle(const P &a, const P &b) {
	int za = a.y > 0 || (a.y == 0 && a.x > 0) ? 0 : 1;
	int zb = b.y > 0 || (b.y == 0 && b.x > 0) ? 0 : 1;
	if(za != zb) return za - zb;
	P::T2 t1 = (P::T2)a.x * b.y;
	P::T2 t2 = (P::T2)a.y * b.x;
	return t1 > t2 ? -1 : t1 < t2 ? 1 : 0;
}

struct Angle {
	P point;
	Angle() : point() {}
	Angle(P::T x, P::T y) : point(P(x, y)) {}
	explicit Angle(P point_) : point(point_) {}
	explicit Angle(P origin, P target) : point(target.x - origin.x, target.y - origin.y) {}
	bool zero() const { return point.x == 0 && point.y == 0; }
	int compare_to(const Angle &that) const {
		assert(!zero() && !that.zero());
		return compareAngle(point, that.point);
	}
	bool operator==(const Angle &that) const { return compare_to(that) == 0; }
	bool operator< (const Angle &that) const { return compare_to(that) <  0; }
};


int main() {
	int k; int n;
	while(~scanf("%d%d", &k, &n)) {
		vector<P> as(k);
		rep(i, k) {
			int x; int y;
			scanf("%d%d", &x, &y);
			as[i] = P(x, y);
		}
		vector<P> ms(n);
		rep(i, n) {
			int x; int y;
			scanf("%d%d", &x, &y);
			ms[i] = P(x, y);
		}
		vector<map<Angle, vector<pair<long long,int>>>> angles(k);
		rep(i, k) {
			rep(j, n) {
				P d = ms[j] - as[i];
				angles[i][Angle(d)].emplace_back(norm(d), j);
			}
			for(auto &p : angles[i])
				sort(p.second.begin(), p.second.end());
		}
		int ans = 0;
		rep(mi, n) {
			vi perm(k);
			iota(perm.begin(), perm.end(), 0);
			vector<pair<int,pair<int,int>>> stk;
			vector<bool> killed(n);
			vector<int> killedList;
			do {
				stk.clear();
				stk.emplace_back(mi, make_pair(0, 0));
				int curpi = 0;
				while(!stk.empty()) {
					int i = stk.back().first;
					int vi = stk.back().second.first;
					int pi = stk.back().second.second;
					if(pi == k) break;
					int p = perm[pi];
					stk.pop_back();
					const auto &v = angles[p][Angle(as[p], ms[i])];
					for(; vi != v.size(); ++ vi) {
						int j = v[vi].second;
						if(j == i) {
							killed[i] = true;
							killedList.push_back(i);
							break;
						}
						if(killed[j]) continue;
						stk.emplace_back(i, make_pair(vi + 1, pi));
						++ curpi;
						stk.emplace_back(j, make_pair(0, curpi));
						break;
					}
					assert(vi != v.size());
				}
				for(int i : killedList)
					killed[i] = false;
				killedList.clear();
				if(stk.empty()) {
					++ ans;
					break;
				}
			} while(next_permutation(perm.begin(), perm.end()));
		}
		printf("%d\n", ans);
	}
	return 0;
}
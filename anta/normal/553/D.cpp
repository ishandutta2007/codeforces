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

template<typename T>T gcd(T x, T y) { return y == 0 ? x : gcd(y,x%y); }

struct Ratio {
	typedef ll T;
	T x, y;
	Ratio(): x(0), y(1) { }
	Ratio(T x_): x(x_), y(1) { }
	Ratio(T x_, T y_): x(x_), y(y_) { normalize(); }
	double toDouble() { return double(x) / y; }
	void normalize() {
		T g = gcd(abs(x), abs(y));
        if(g == 0) return;
		x /= g; y /= g;
		if(y < 0) x = -x, y = -y;
		if(x == 0) y = 1;
	}
	bool operator==(const Ratio& q) const { return x == q.x && y == q.y; }
	bool operator!=(const Ratio& q) const { return x != q.x || y != q.y; }
	bool operator<(const Ratio& q) const { return x*q.y < y*q.x; }
	bool operator<=(const Ratio& q) const { return x*q.y <= y*q.x; }
	bool operator>(const Ratio& q) const { return x*q.y > y*q.x; }
	bool operator>=(const Ratio& q) const { return x*q.y >= y*q.x; }
	Ratio& operator+=(const Ratio& q) {
		T g = gcd(y,q.y); x = q.y/g*x + y/g*q.x, y = y/g*q.y; normalize();
		return *this;
	}
	Ratio& operator-=(const Ratio& q) {
		T g = gcd(y,q.y); x = q.y/g*x - y/g*q.x, y = y/g*q.y; normalize();
		return *this;
	}
	Ratio& operator*=(const Ratio& q) {
		x = x*q.x, y = y*q.y; normalize();
		return *this;
	}
	Ratio& operator/=(const Ratio& q) {
		x = x*q.y, y = y*q.x; normalize();
		return *this;
	}
	Ratio operator+(const Ratio& q) const { return Ratio(*this) += q; }
	Ratio operator-(const Ratio& q) const { return Ratio(*this) -= q; }
	Ratio operator*(const Ratio& q) const { return Ratio(*this) *= q; }
	Ratio operator/(const Ratio& q) const { return Ratio(*this) /= q; }
	Ratio operator-() const { return Ratio(-x, y); }
};
ostream& operator<<(ostream &o, const Ratio& p) { o << p.x << "/" << p.y; return o; }

int main() {
	int n, m, k;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		vector<bool> fortress(n, false);
		rep(i, k) {
			int a;
			scanf("%d", &a), -- a;
			fortress[a] = true;
		}
		vector<int> deg(n, 0);
		vector<vi> g(n);
		rep(i, m) {
			int a, b;
			scanf("%d%d", &a, &b), -- a, -- b;
			++ deg[a], ++ deg[b];
			g[a].push_back(b);
			g[b].push_back(a);
		}
		Ratio ans = 0;
		vector<int> ansset;
		rep(phase, 2) {
			vector<int> degS(n, 0);
			rep(i, n) if(!fortress[i]) each(j, g[i])
				if(!fortress[*j])
					++ degS[i];
			priority_queue<pair<Ratio,int> > pq;
			vector<bool> inS(n, false);
			rep(i, n) inS[i] = !fortress[i];
			rep(i, n) if(inS[i])
				pq.push(mp(-Ratio(degS[i], deg[i]), i));
			while(!pq.empty()) {
				int i = pq.top().second;
				Ratio t = -pq.top().first;
				pq.pop();
				if(!inS[i] || t != Ratio(degS[i], deg[i])) continue;
				if(phase == 0) {
					amax(ans, t);
				}else {
					if(ans == t)
						break;
				}
				inS[i] = false;
				each(j, g[i]) if(inS[*j]) {
					-- degS[*j];
					pq.push(mp(-Ratio(degS[*j], deg[*j]), *j));
				}
			}
			if(phase == 1) {
				rep(i, n) if(inS[i])
					ansset.push_back(i);
			}
		}
//		cerr << "ans = " << ans << endl;
		printf("%d\n", (int)ansset.size());
		rep(i, ansset.size()) {
			if(i != 0) putchar(' ');
			printf("%d", ansset[i] + 1);
		}
		puts("");
	}
	return 0;
}
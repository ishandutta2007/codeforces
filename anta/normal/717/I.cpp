#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

typedef long double Num;
struct Vec3 {
	Num p[3];
	Vec3() : p{} {}
	Vec3(Num x, Num y, Num z) : p{ x,y,z } {}
	Num operator[](int i) const { return p[i]; }
};
inline Vec3 operator+(Vec3 a, Vec3 b) { return Vec3(a[0] + b[0], a[1] + b[1], a[2] + b[2]); }
inline Vec3 operator-(Vec3 a, Vec3 b) { return Vec3(a[0] - b[0], a[1] - b[1], a[2] - b[2]); }
inline Vec3 operator*(Vec3 a, Num s) { return Vec3(a[0] * s, a[1] * s, a[2] * s); }
inline Num dot(Vec3 a, Vec3 b) {
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
inline Vec3 cross(Vec3 a, Vec3 b) {
	return Vec3(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]);
}
inline Num norm(Vec3 a) { return dot(a, a); }
inline Num abs(Vec3 a) { return sqrt(norm(a)); }
inline Vec3 normalize(Vec3 a) { return a * (1 / abs(a)); }

struct Vec2 {
	Num p[2];
	Vec2() : p{} {}
	Vec2(Num x, Num y) : p{ x,y } {}
	Num operator[](int i) const { return p[i]; }
};
inline Vec2 operator+(Vec2 a, Vec2 b) { return Vec2(a[0] + b[0], a[1] + b[1]); }
inline Vec2 operator-(Vec2 a, Vec2 b) { return Vec2(a[0] - b[0], a[1] - b[1]); }
inline Vec2 operator*(Vec2 a, Num s) { return Vec2(a[0] * s, a[1] * s); }
inline Num dot(Vec2 a, Vec2 b) {
	return a[0] * b[0] + a[1] * b[1];
}
inline Num cross(Vec2 a, Vec2 b) {
	return a[0] * b[1] - a[1] * b[0];
}
inline Num norm(Vec2 a) { return dot(a, a); }
inline Num abs(Vec2 a) { return sqrt(norm(a)); }
inline Vec2 normalize(Vec2 a) { return a * (1 / abs(a)); }

//#include "GeoVisClient.h"
int main() {
	const Num EPS = 1e-9;
	int n;
	//GeoVisClient gv;
	while(~scanf("%d", &n)) {
		vector<Vec3> hole(n);
		rep(i, n) {
			int x; int y; int z;
			scanf("%d%d%d", &x, &y, &z);
			hole[i] = Vec3(x, y, z);
		}
		int m;
		scanf("%d", &m);
		vector<Vec3> ring(m);
		rep(i, m) {
			int x; int y; int z;
			scanf("%d%d%d", &x, &y, &z);
			ring[i] = Vec3(x, y, z);
		}
		Vec3 axisO = hole[0];
		for(auto &v : hole)
			v = v - axisO;
		for(auto &v : ring)
			v = v - axisO;
		Vec3 axisX = normalize(hole[1]);
		Vec3 axisZ = normalize(cross(axisX, hole[n - 1]));
		Vec3 axisY = cross(axisZ, axisX);
		vector<pair<Vec2,int>> points;
		rep(i, m) {
			Vec3 a = ring[i], b = ring[(i + 1) % m];
			Num za = dot(a, axisZ), zb = dot(b, axisZ);
			if((za >= EPS) != (zb >= EPS)) {
				Vec3 p = a + (b - a) * (abs(za) / (abs(za) + abs(zb)));
				Num x = dot(p, axisX), y = dot(p, axisY);
				points.emplace_back(Vec2(x, y), za >= EPS ? 1 : -1);
			}
		}
		if(points.empty()) {
			puts("NO");
			continue;
		}
		//ring1points1
		Vec2 origin = points[0].first;
		Vec2 vec(1, 0);
		for(auto p : points) if(norm(p.first - origin) > EPS) {
			vec = normalize(p.first - origin);
			break;
		}
		Vec2 vecR(-vec[1], vec[0]);
		vector<pair<Num, int>> events;
		for(auto p : points)
			events.emplace_back(dot(p.first - origin, vec), p.second);
		//gv.clear();
		rep(i, n) {
			Vec3 a = hole[i];
			Vec2 a2(dot(a, axisX), dot(a, axisY));
			Vec3 b = hole[(i + 1) % n];
			Vec2 b2(dot(b, axisX), dot(b, axisY));
			//gv.line(a2[0],a2[1],b2[0],b2[1]);
			Num A = dot(a2 - origin, vecR);
			Num B = dot(b2 - origin, vecR);
			if((A > EPS) != (B > EPS)) {
				Vec2 x = a2 + (b2 - a2) * (abs(A) / (abs(A) + abs(B)));
				//gv.plot(x[0], x[1], to_string(dot(x, vec)));
				events.emplace_back(dot(x - origin, vec), 0);
			}
		}
		//for(auto p : points)
		//	gv.plot(p.first[0], p.first[1], to_string(dot(p.first - origin, vec)) + ": " + to_string(p.second), GeoVisClient::RED);
		//gv.fitCamera();
		sort(events.begin(), events.end());
		int parity = 0, crosses = 0;
		for(auto ev : events) {
			if(ev.second == 0) {
				parity ^= 1;
			} else {
				if(parity == 1)
					crosses += ev.second;
			}
		}
		puts(crosses != 0 ? "YES" : "NO");
	}
	return 0;
}
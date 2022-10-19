#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long double ld;
typedef pair <ld, ld> vec;

const int MAXN = 1e5 + 5;
const ld INF = 1e20;
const ld eps = 1e-4;

int N, M;
vec gen[MAXN], poly[MAXN];
ld tot, squares;
vec centroid;

vec get() {
	int p, q;
	scanf("%d%d", &p, &q);
	return {p, q};
}

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		gen[i] = get();
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
		poly[i] = get();
}

vec operator +(const vec &u, const vec &v) {
	return {u.x + v.x, u.y + v.y};
}

vec operator -(const vec &u, const vec &v) {
	return {u.x - v.x, u.y - v.y};
}

void operator +=(vec &u, const vec &v) {
	u = u + v;
}

ld operator *(const vec &u, const vec &v) {
	return u.x * v.x + u.y * v.y;
}

vec operator *(const ld &lambda, const vec &v) {
	return {lambda * v.x, lambda * v.y};
}

void operator *=(vec &v, const ld &lambda) {
	v = lambda * v;
}

ld norm(const vec &v) {
	return v * v;
}

ld eval(vec v) {
	return N * norm(v) - 2 * N * centroid * v + squares;
}

ld area(vec a, vec b, vec c) {
	return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

bool inside(vec v) {
	ld sum = 0;
	for (int i = 0; i < M; i++)
		sum += area(v, poly[i], poly[(i + 1) % M]);
	return abs(sum - tot) < eps;
}

ld optimize(vec u, vec v) {
	ld t = (ld)1 / norm(v - u) * (centroid - u) * (v - u);
	if (t < 0 || t > 1)
		return INF;
	return eval((1 - t) * u + t * v);
}

ld solve() {
	for (int i = 0; i < N; i++) {
		squares += norm(gen[i]);
		centroid += gen[i];
	}
	centroid *= (ld)1 / N;
	
	for (int i = 1; i < M - 1; i++)
		tot += area(poly[0], poly[i], poly[i + 1]);
	
	if (inside(centroid)) 
		return eval(centroid);
	
	ld sol = INF;
	for (int i = 0; i < M; i++) {
		sol = min(sol, eval(poly[i]));
		sol = min(sol, optimize(poly[i], poly[(i + 1) % M]));
	}
	
	return sol;
}

int main() {
	load();
	printf("%.10Lf\n", solve());
	return 0;
}
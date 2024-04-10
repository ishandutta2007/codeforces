#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

long long n, m, x, y, a, b;
long long w, h;


int main()
{
	#ifdef MJUDGE
		assert(freopen("in", "r", stdin));
		assert(freopen("out", "w", stdout));
	#endif
	
	cin >> n >> m >> x >> y >> a >> b;
	long long g = gcd(a, b);
	a /= g;
	b /= g;
	
	long long k = min (n / a, m / b);
	long long w = k * a;
	long long h = k * b;
	w *= 2;
	h *= 2;
	x *= 2;
	y *= 2;
	n *= 2;
	m *= 2;
	long long cx = min(max(x, w / 2), n - w / 2);
	long long cy = min(max(y, h / 2), m - h / 2);
	long long x1 = (cx - w / 2) / 2, y1 = (cy - h / 2) / 2;
	w /= 2;
	h /= 2;
	
	cout << x1 << " " << y1 << " " << x1 + w << " " << y1 + h << endl;
	
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

long double x[maxn], y[maxn];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int n;
	scanf("%d", &n);
	double xx, yy;
	long double x0, y0;
	scanf("%lf%lf", &xx, &yy);
	x0 = xx, y0 = yy;
	long double midist = 1e20, madist = 0;
	for(int i = 0; i < n; i++) {
		scanf("%lf%lf", &xx, &yy);
		x[i] = xx, y[i] = yy;
		midist = min(midist, sqrt(sqr(x[i] - x0) + sqr(y[i] - y0)));
		madist = max(madist, sqrt(sqr(x[i] - x0) + sqr(y[i] - y0)));
	}

	x[n] = x[0], y[n] = y[0];

	for(int i = 0; i < n; i++) {
		long double vx = x[i + 1] - x[i], vy = y[i + 1] - y[i];
		long double l = 0., r = 1.;
		for(int g = 0; g < 200; g++) {
			long double m1 = l + (r - l) / 3., m2 = r - (r - l) / 3.;
			long double x1 = x[i] + vx * m1, y1 = y[i] + vy * m1;
			long double x2 = x[i] + vx * m2, y2 = y[i] + vy * m2;
			if(sqrt(sqr(x1 - x0) + sqr(y1 - y0)) < sqrt(sqr(x2 - x0) + sqr(y2 - y0))) {
				r = m2;
			} else {
				l = m1;
			}
		}
		long double x1 = x[i] + vx * r, y1 = y[i] + vy * r;
		midist = min(midist, sqrt(sqr(x1 - x0) + sqr(y1 - y0)));
	}

	printf("%.15lf", (double)(pi * sqr(madist) - pi * sqr(midist)));

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim
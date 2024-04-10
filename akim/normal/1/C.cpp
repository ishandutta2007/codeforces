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

const double eps = 1e-3;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;



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

	double x1, y1, x2, y2, x3, y3, ans = 1e30;
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
	double dist12 = sqrt(sqr(x1 - x2) + sqr(y1 - y2));
	double dist23 = sqrt(sqr(x2 - x3) + sqr(y2 - y3));
	double dist13 = sqrt(sqr(x1 - x3) + sqr(y1 - y3));
	for(int cnt = 3; cnt <= 100; cnt++) {
		double ang = (2. * pi) / (cnt * 1.);
		for(int i = 1; i < cnt; i++) {
			double fang12 = ang * (abs(i - 0));
			double R12 = abs(dist12 / 2. / sin(fang12 / 2.));
			for(int j = 1; j < cnt; j++) {
				if(i == j) continue;
				double fang13 = ang * (abs(0 - j));
				double R13 = abs(dist13 / 2. / sin(fang13 / 2.));
				double fang23 = ang * (abs(i - j));
				double R23 = abs(dist23 / 2. / sin(fang23 / 2.));
				if(abs(R12 - R23) < eps && abs(R12 - R13) < eps && abs(R23 - R13) < eps) {
					double a = R12 * sin(ang / 2.);
					double h = R12 * cos(ang / 2.);
					ans = min(ans, a * h * cnt);
				}
			}
		}
	}

	printf("%.10lf", ans);

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
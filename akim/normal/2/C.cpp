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

const double eps = 1e-5;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 3;

double x[maxn], y[maxn], r[maxn], t[maxn];

double func(double dx, double dy) {
	double rz = 0;
	for(int i = 0; i < maxn; i++) {
		t[i] = (sqr(dx - x[i]) + sqr(dy - y[i])) / sqr(r[i]);
	}
	for(int i = 0; i < maxn; i++) {
		rz += sqr(t[i] - t[(i + 1) % 3]);
	}
	return(rz);
}

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

	double dx = 0, dy = 0;
	for(int i = 0; i < maxn; i++) {
		scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
		dx += x[i];
		dy += y[i];
	}
	dx /= 3;
	dy /= 3;

	for(double m = 1.; m >= eps; m *= 0.5) {
		while(func(dx, dy) > func(dx + m, dy)) {
			dx += m;
		}
		while(func(dx, dy) > func(dx - m, dy)) {
			dx -= m;
		}
		while(func(dx, dy) > func(dx, dy + m)) {
			dy += m;
		}
		while(func(dx, dy) > func(dx, dy - m)) {
			dy -= m;
		}
		while(func(dx, dy) > func(dx + m, dy)) {
					dx += m;
				}
				while(func(dx, dy) > func(dx - m, dy)) {
					dx -= m;
				}
				while(func(dx, dy) > func(dx, dy + m)) {
					dy += m;
				}
				while(func(dx, dy) > func(dx, dy - m)) {
					dy -= m;
				}
				while(func(dx, dy) > func(dx + m, dy)) {
							dx += m;
						}
						while(func(dx, dy) > func(dx - m, dy)) {
							dx -= m;
						}
						while(func(dx, dy) > func(dx, dy + m)) {
							dy += m;
						}
						while(func(dx, dy) > func(dx, dy - m)) {
							dy -= m;
						}
						while(func(dx, dy) > func(dx + m, dy)) {
									dx += m;
								}
								while(func(dx, dy) > func(dx - m, dy)) {
									dx -= m;
								}
								while(func(dx, dy) > func(dx, dy + m)) {
									dy += m;
								}
								while(func(dx, dy) > func(dx, dy - m)) {
									dy -= m;
								}
								while(func(dx, dy) > func(dx + m, dy)) {
											dx += m;
										}
										while(func(dx, dy) > func(dx - m, dy)) {
											dx -= m;
										}
										while(func(dx, dy) > func(dx, dy + m)) {
											dy += m;
										}
										while(func(dx, dy) > func(dx, dy - m)) {
											dy -= m;
										}
										while(func(dx, dy) > func(dx + m, dy)) {
													dx += m;
												}
												while(func(dx, dy) > func(dx - m, dy)) {
													dx -= m;
												}
												while(func(dx, dy) > func(dx, dy + m)) {
													dy += m;
												}
												while(func(dx, dy) > func(dx, dy - m)) {
													dy -= m;
												}
	}

	if(func(dx, dy) < eps * 100) printf("%.10lf %.10lf", dx, dy);

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
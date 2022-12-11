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

int l[maxn], r[maxn], v[maxn], a[maxn];

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

	int n, p;
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &l[i], &r[i]);
		a[i] = r[i] - l[i] + 1;
		v[i] = r[i] / p - (l[i] - 1) / p;
	}
	v[n] = v[0], a[n] = a[0];
	v[n + 1] = v[0 + 1], a[n + 1] = a[0 + 1];
	double ans = 0;
	for(int i = 0; i < n; i++) {
		double m[3];
		for(int j = 0; j < 2; j++) {
			m[j] = (v[i + j] * 1.) / (a[i + j] * 1.);
		}
		ans += ((1. - m[0]) * (m[1])) * 2000.;
		ans += ((m[0]) * (1 - m[1])) * 2000.;
		ans += ((m[0]) * (m[1])) * 2000.;
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
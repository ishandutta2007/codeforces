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

	int n, d, h;
	scanf("%d%d%d", &n, &d, &h);
	if(n - 1 < d) {
		printf("-1");
		return(0);
	}
	if(2 * h < d) {
		printf("-1");
		return(0);
	}

	if(n - 1 < h) {
		printf("-1");
		return(0);
	}

	if(h + h < d) {
		printf("-1");
		return(0);
	}

	if(d == h && n - 1 > h) {

		if(d == 1 && n > 2) {
			printf("-1");
			return(0);
		}
		for(int i = 2; i <= h + 1; i++) {
			printf("%d %d\n", i - 1, i);
		}
		for(int i = d + 2; i <= n; i++) {
			printf("%d %d\n", 2, i);
		}
		return(0);
	}

	for(int i = 2; i <= h + 1; i++) {
		printf("%d %d\n", i - 1, i);
	}
	for(int i = h + 2; i <= d + 1; i++) {
		printf("%d %d\n", i - 1 == h + 1 ? 1 : i - 1, i);
	}
	for(int i = d + 2; i <= n; i++) {
		printf("%d %d\n", 1, i);
	}

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
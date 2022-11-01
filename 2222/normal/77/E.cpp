#define __USE_MINGW_ANSI_STDIO    0

#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(), (a).end()

typedef long long int64;

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int T;
	for (cin >> T; T --> 0; ) {
		int R, r, k;
		cin >> R >> r >> k;
		double x0 = 0.5 / R, x1 = 0.5 / r, y = (x1 - x0) * k, p = (x1 - x0) * 0.5, x = (x1 + x0) * 0.5;
		double h = sqrt(x * x + y * y);
		printf("%.12lf\n", (1 / (h - p) - 1 / (h + p)) / 2);
	}
	return 0;
}
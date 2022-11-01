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
	int t;
	for (cin >> t; t --> 0; ) {
		int a, b;
		scanf("%d%d", &a, &b);
		double res;
		if (b == 0) 
			res = 1;
		else if (a < 4 * b) 
			res = 0.5 + double(a) / (16 * b);
		else 
			res = 1 - double(b) / a;
		printf("%.12lf\n", res);
	}
	return 0;
}
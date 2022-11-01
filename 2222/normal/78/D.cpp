#undef __USE_MINGW_ANSI_STDIO
#define __USE_MINGW_ANSI_STDIO    1

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

const double pi = acos(-1.0);
const double s3 = sqrt(3.0);

double dx[6], dy[6];

int64 R;

bool check(int i, int j) {
	double cx = (i + ((j & 1) ? 0.5 : 0.0)) * s3;
	double cy = j * 1.5;
	for (int k = 0; k < 6; ++k) {
		double x = cx + dx[k];
		double y = cy + dy[k];
		if (x * x + y * y > R + 1e-9)
			return false;
	}
	return true;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> R;
	R *= R;
	for (int i = 0; i < 6; ++i) {
		dx[i] = sin(pi * i / 3);
		dy[i] = cos(pi * i / 3);
	}
	int64 res = 0;
	int L = 0, R = 0, y = R;
	for (; check(0, y); ++y);
	for (; !check(0, y); --y);
	for (; y >= 0; --y) {
		L = min(L + 2, 0);
		R = max(R - 2, 0);
		for (; check(L - 1, y); --L);
		for (; check(R + 1, y); ++R);
		res += R - L + 1;
		if (y) res += R - L + 1;
	}
	printf("%lld\n", res);
	return 0;
}
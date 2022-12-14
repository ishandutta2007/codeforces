
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

lf a, b, c, d;

bool inside(lf x, lf y, lf z) {
	return x <= y && y <= z;
	//return ((x < y) ? true : fabs(x - y) < 1e-13) && ((y < z) ? true : fabs(y - z) < 1e-13);
}

bool good(lf v) {
	lf t1, t2, u1, u2;
	for (int x = -1; x <= 1; x += 2) {
		for (int y = -1; y <= 1; y += 2) {
			lf t = (a + x * v) * (d + y * v);
			if (x == -1 && y == -1) t1 = t2 = t;
			t1 = min(t1, t);
			t2 = max(t2, t);

			lf u = (b + x * v) * (c + y * v);
			if (x == -1 && y == -1) u1 = u2 = u;
			u1 = min(u1, u);
			u2 = max(u2, u);
		}
	}

	return inside(u1, t1, u2) || inside(u1, t2, u2) || inside(t1, u1, t2) || inside(t1, u2, t2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("549H.in", "r", stdin);
	freopen("549H.out", "w", stdout);
#endif

	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

	lf low = 0, high = 1e15, ans = 1e11;
	for (int rep = 0; rep < 100; rep++) {
		lf mid = (low + high) / 2;
		if (good(mid)) {
			high = ans = mid;
		}
		else {
			low = mid;
		}
	}

	printf("%.11lf\n", ans);
	return 0;
}
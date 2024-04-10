#include <functional>
#include <algorithm>
#include <assert.h>
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

typedef long long ll;

const int mod = 1000000009;

int p[100500], n, m;

int f(int i) { return p[i] == i ? i : p[i] = f(p[i]); }

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m;
	for (int i = 0; i < 100500; ++i) p[i] = i;
	int r = 1;
	for (; m --> 0; ) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (f(x) == f(y)) {
			if ((r += r) >= mod) r -= mod;
		} else {
			p[f(x)] = f(y);
		}
		printf("%d\n", (r + mod - 1) % mod);
	}
	return 0;
}
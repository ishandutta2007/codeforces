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
	int x, y;
	cin >> x >> y;
	for (; ; ) {
		int i = min(x, 2), j = min(y, 22 - i * 10);
		if (i * 100 + j * 10 == 220) {
			x -= i;
			y -= j;
		} else {
			puts("Hanako");
			return 0;
		}
		j = min(22, y);
		i = min(2, min(x, (220 - j * 10 + 99) / 100));
		j = min(j, 22 - i * 10);
		if (i * 100 + j * 10 == 220) {
			x -= i;
			y -= j;
		} else {
			puts("Ciel");
			return 0;
		}
	}
}
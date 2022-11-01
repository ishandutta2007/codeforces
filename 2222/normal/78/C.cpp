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

void answer(bool first) {
	puts(first ? "Timur" : "Marsel");
	exit(0);
}

vector<int> d;
map<int, int> f;
int n, m, k;

bool go(int n) {
	if (f.count(n)) return f[n];
	bool res = false;
	for (int x : d)
		if (x >= k && x < n) {
			if ((n / x) % 2 == 0 || !go(x)) {
				res = true;
				break;
			}
		}
	f[n] = res;
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m >> k;
	if (n % 2 == 0) answer(false);
	for (int x = 1; x * x <= m; ++x) {
		if (m % x == 0) {
			d.push_back(x);
			if (x * x != m) d.push_back(m / x);
		}
	}
	sort(all(d));
	answer(go(m));
	return 0;
}
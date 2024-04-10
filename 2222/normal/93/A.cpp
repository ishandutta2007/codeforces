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

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	--a, --b;
	int x0 = a % m, x1 = b % m;
	int h = (b / m) - (a / m), res = 3;
	if (h == 1 || x0 == 0 || x1 + 1 == m || b + 1 == n || x1 + 1 == x0) res = 2;
	if (h == 0 || x0 == 0 && (x1 + 1 == m || b + 1 == n)) res = 1;
	cout << res << endl;
	return 0;
}
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
	int n;
	cin >> n;
	printf("ROYGBIV");
	for (int i = 0; i + 7 < n; ++i)
		putchar("GBIV"[i % 4]);
	return 0;
}
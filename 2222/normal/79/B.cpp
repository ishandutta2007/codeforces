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

int n, m, k;
pair<int, int> p[1024];
const char* ans[] = {"Carrots", "Kiwis", "Grapes"};

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int u;
	cin >> n >> m >> k >> u;
	for (int i = 0; i < k; ++i) cin >> p[i].first >> p[i].second;
	sort(p, p + k);
	p[k] = {n + 1, m + 1};
	for (pair<int, int> q; u > 0; --u) {
		cin >> q.first >> q.second;
		int j = lower_bound(p, p + k, q) - p;
		if (p[j] == q) 
			puts("Waste");
		else 
			puts(ans[((q.first - 1) * m + q.second - j + 2) % 3]);
	}
	return 0;
}
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
	int n;
	cin >> n;
	vector<int> a(n), r(n, -1);
	for (int &x : a) scanf("%d", &x);
	vector<int> z(1, -(-1u/4)), pos(1, n);
	for (int i = n; i --> 0; ) {
		if (-a[i] > z.back()) {
			z.push_back(-a[i]);
			pos.push_back(i);
		}
		int j = upper_bound(all(z), -a[i]) - z.begin();
		if (j != z.size()) {
			j = pos[j];
			if (j != n) r[i] = j - i - 1;
		}
	}
	for (int i = 0; i < n; ++i) cout << r[i] << ' ';
	return 0;
}
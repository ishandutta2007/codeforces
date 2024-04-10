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

typedef long long ll;

int n;
vector<int> a[100500];
int v[100500];

ll go(int x, int pr = -1) {
	ll res = 0, k = 0;
	vector <ll> q;
	for (auto y = a[x].begin(); y != a[x].end(); ++y) 
		if (*y != pr && v[*y] > 0) {
			--v[*y];
			q.push_back(go(*y, x));
			k += v[*y];
		}
	if (v[x] > q.size()) {
		res = accumulate(all(q), 0ll) + 2 * q.size();
		v[x] -= q.size();
	} else {
		nth_element(all(q) - v[x], q.end());
		res = accumulate(q.size() - v[x] + all(q), 0ll) + 2 * v[x];
		v[x] = 0;
	}
	k = min((ll)v[x], k);
	v[x] -= k;
	return res + k * 2;
}

int main() {
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	vector <int> fff;
	for (int i = 0; i < 10000000; ++i) fff.push_back(i);
	for (; fff.size() > 0; fff.pop_back());
	cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%d", v + i);
	for (int x, y, i = 1; i < n; ++i) {
		scanf("%d%d", &x, &y);
		--x, --y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int s;
	cin >> s;
//	++v[s - 1];
	cout << go(s - 1) << endl;
	return 0;
}
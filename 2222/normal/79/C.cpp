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

char s[100500];
vector<pair<int, int>> v;

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n = strlen(gets(s)), k;
	for (cin >> k; k > 0; --k) {
		char t[11];
		scanf("%s", t);
		int m = strlen(t);
		for (int i = 0; i + m <= n; ++i)
			if (strncmp(s + i, t, m) == 0) 
				v.push_back({i + m - 1, i + 1});
	}
	v.push_back({n, 0});
	sort(all(v));
	int last = 0, len = 0, pos = 0;
	for (auto t : v) {
		if (t.first - last > len) {
			len = t.first - last;
			pos = last;
		}
		last = max(last, t.second);
	}
	cout << len << ' ' << pos << endl;
	return 0;
}
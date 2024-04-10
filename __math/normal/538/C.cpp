#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

// #pragma comment(linker,"/STACK:36777216")

int main() {
	int n, m; scanf("%d%d", &n, &m);
	map<int, int> mp;
	FOR(i, m) {
		int d, h; scanf("%d%d", &d, &h);
		mp[d] = h;
	}
	int ans = 0;
	Pii fv = *mp.begin();
	ans = max(ans, fv.first + fv.second - 1);
	fv = *mp.rbegin();
	ans = max(ans, (n - fv.first) + fv.second);
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		auto it2 = next(it);
		if (it2 == mp.end()) break;
		int dist = it2->first - it->first;
		int diff = abs(it2->second - it->second);
		if (dist < diff) {
			ans = ten(9);
			break;
		}
		dist -= diff;
		ans = max(ans, max(it->second, it2->second) + dist / 2);
	}
	if (ans == ten(9)) cout << "IMPOSSIBLE" << endl;
	else cout << ans << endl;
}
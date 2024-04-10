/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

char s[1000];

int main() {
	int a, b, c;

	cin >> a >> b >> c;

	int m;

	cin >> m;

	vector <int> y, z;

	for (int i = 0; i < m; i++) {
		int x;

		scanf("%d %s", &x, s);

		if (s[0] == 'U') {
			y.push_back(x);
		} else {
			z.push_back(x);
		}
	}

	sort(y.rbegin(), y.rend());
	sort(z.rbegin(), z.rend());

	int cnt = 0;
	ll ans = 0;

	while (a > 0 && !y.empty()) {
		cnt++;
		ans += y.back();
		y.pop_back();
		a--;
	}

	while (b > 0 && !z.empty()) {
		cnt++;
		ans += z.back();
		z.pop_back();
		b--;
	}

	for (int i = 0; i < (int)z.size(); i++) {
		y.push_back(z[i]);
	}

	sort(y.rbegin(), y.rend());

	while (c > 0 && !y.empty()) {
		cnt++;
		ans += y.back();
		y.pop_back();
		c--;
	}

	cout << cnt << ' ' << ans << endl;

	return 0;
}
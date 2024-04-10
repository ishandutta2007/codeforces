#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>

//#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(7);
	int sy, a, b;
	cin >> sy >> a >> b;
	int n;
	cin >> n;
	vector<ld> l(n), r(n);
	for (int i = 0; i < n; ++i) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		l[i] = tmp1 + 0.; r[i] = tmp2 + 0.;
	}
	vector<int> pref(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		pref[i] = pref[i - 1] + r[i - 1] - l[i - 1];
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		ld l1, r1;
		l1 = a * 1. + (x - a) * 1. * (0. - sy) / (ld)(y - sy);
		r1 = b * 1. + (x - b) * 1. * (0. - sy) / (ld)(y - sy);
		int lp = lower_bound(all(l), l1) - l.begin();
		int rp = upper_bound(all(r), r1) - r.begin();
		ld ans = 0.;
		if (lp > 0 && r[lp - 1] > l1) ans += r[lp - 1] - l1;
		if (rp < n && r1 > l[rp]) ans += r1 - l[rp];
		if (rp - 1 >= lp) ans += (ld)(pref[rp] - pref[lp]);
		ans = min(ans, r1 - l1);
		cout << fixed << (ld)(b - a) * ans / (r1 - l1) << '\n';
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
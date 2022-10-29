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

#pragma GCC optimize("O3")
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
const int mod = 1e6;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	vector<int> a(mod, 0);
	int mx = 0;
	for (int i = 0; i < t; ++i) {
		int tmp;
		cin >> tmp;
		mx = max(mx, tmp);
		a[tmp]++;
	}
	if (a[0] != 1)
		return cout << -1, 0;
	int l = -1;
	for (int i = 0; i < mod; ++i)
		if (a[i] == 0) {
			l = i;
			break;
		}
	if (l != -1) {
		for (int i = l + 1; i < mod; ++i)
			if (a[i] > 0) return cout << -1, 0;
	}
	bool k = 0;
	for (int p = 1; p <= pow(t, 0.5); ++p) {
		if (t % p != 0)
			continue;
		int q = t / p;
		int i;
		for (i = 1; i < mod; ++i)
			if (a[i] != 4 * i)
				break;
		if (a[i] > 4 * i)
			return cout << -1, 0;
		i--;
		int x = i, y = q - (mx - (p - 1 - i)) - 1;
		if (!(x < 0 || y < 0 || x >= p || y >= q)) {
			vector<int> b(mod, 0);
			for (int g = 0; g < p; ++g)
				for (int h = 0; h < q; ++h)
					b[abs(g - x) + abs(h - y)]++;
			if (a == b) {
				cout << p << ' ' << q << endl;
				cout << x + 1 << ' ' << y + 1 << endl;
				k = 1;
				break;
			}
		}
		y = i;
		x = p - (mx - (q - 1 - i)) - 1;
		if (!(x < 0 || y < 0 || x >= p || y >= q)) {
			vector<int> b(mod, 0);
			for (int g = 0; g < p; ++g)
				for (int h = 0; h < q; ++h)
					b[abs(g - x) + abs(h - y)]++;
			if (a == b) {
				cout << p << ' ' << q << endl;
				cout << x + 1 << ' ' << y + 1 << endl;
				k = 1;
				break;
			}
		}
	}
	if (!k)
		cout << -1;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
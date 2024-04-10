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
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()
#define int ll

signed main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int m = n / 2;
	int l = 0, r = n / 2, a1, a2, b1, b2;
	if (m & 1)
		return cout << "! -1" << endl, 0;
	cout << "? 1" << endl;
	cin >> a1;
	cout << "? " << m + 1 << endl;
	cin >> a2;
	b1 = a2; b2 = a1;
	if (a1 == a2)
		return cout << "! 1" << endl, 0;
	int c1, c2;
	while (1) {
		int tmp = (r + l) >> 1;
		cout << "? " << tmp + 1 << endl;
		cin >> c1;
		cout << "? " << tmp + m + 1 << endl;
		cin >> c2;
		if (c1 == c2) {
			cout << "! " << tmp + 1 << endl;
			break;
		}
		if ((a2 - a1 > 0 && c2 - c1 < 0) || (a2 - a1 < 0 && c2 - c1 > 0)) {
			r = tmp;
			b1 = c1; b2 = c2;
		}
		else {
			l = tmp;
			a1 = c1; a2 = c2;
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
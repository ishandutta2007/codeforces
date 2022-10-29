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

#define int long long

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<vi2> vi3;
typedef vector<vi3> vi4;
typedef vector<vi4> vi5;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()



signed main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<ll> a(70, 0), b(70, 0);
	int q;
	cin >> q;
	vi1 st(64, 1);
	for (int i = 1; i < 64; ++i)
		st[i] = st[i - 1] * 2ll;
	while (q--) {
		int t;
		cin >> t;
		if (t < 3) {
			ll x, k;
			cin >> x >> k;
			int i = log2(x);
			if (t == 1) {
				a[i] += k % st[i] + st[i];
				a[i] = a[i] & (st[i] - 1);
			}
			else {
				b[i] += k % st[i] + st[i];
				b[i] = b[i] & (st[i] - 1);
			}
			continue;
		}
		ll x;
		cin >> x;
		int i = log2(x);
		cout << x << ' ';
		for (i--; i >= 0; --i) {
			int k = x & 1;
			x >>= 1;
			x -= st[i];
			x += ((a[i + 1] + k + st[i + 1]) >> 1) + ((b[i + 1] + (1 & (k ^ a[i + 1])) + st[i + 1]) >> 1) - a[i] + st[i];
			x = x & (st[i] - 1);
			x += st[i];
			cout << x << ' ';
		}
		cout << '\n';
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
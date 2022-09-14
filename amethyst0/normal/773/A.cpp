/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
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
#include <map>            
#define ll long long
#define ld double
#define mp make_pair

using namespace std;

const double PI = 3.14159265358979323846;
const ll maxn = (ll)3e3 + 10;
const ll maxlog = (ll)13;
const ll mod = (ll)1e9 + 7;
const ll inf = (ll)1e18 + 7;
const ld eps = 1e-7;

int t;
ll x, y, q, p;

int stup(int x, int y, int p, int q) {
	for (int z = 0; z < 100000; z++) {
		for (int j = 0; j <= z; j++) {
			if (p * (y + z) == q * (x + j)) {
				return z;
			}
		}
	}
	return -1;
}

int gcd(int a, int b) {
	if (!a || !b) {
		return 1;
	}
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	//srand(time(NULL));
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x >> y >> p >> q;
		//x = rand() % 200;
		//y = rand() % 200;
		//p = rand() % 200;
		//q = rand() % 200;
		//int g = gcd(p, q);
		//p /= g;
		//q /= g;
		//if (p > q) {
		//	swap(p, q);
		//}
		//if (x > y) {
		//	swap(x, y);
		//}
		if (p == 0) {
			if (x == 0) {
				cout << 0 << endl;
			}
			else {
				cout << -1 << endl;
			}
			continue;
		}
		if (q == p) {
			if (x == y) {
				cout << 0 << endl;
			}
			else {
				cout << -1 << endl;
			}
			continue;
		}

		ll tmp;
		if (y % q != 0) {
			tmp = (y / q + 1) * q;
		}
		else {
			tmp = y;
		}
		ll ans = tmp - y;
		ll k = tmp / q;
		ll tmp1 = k * p;

		ll d = tmp - y;
		ll m = 0;
		if (x > k * p) {
			m = max(m, (x - k * p) / p + ((x - k * p) % p != 0 ? 1 : 0));
		}
		if (k * p > x + d) {
			m = max(m, (k * p - x - d) / (q - p) + ((k * p - x - d) % (q - p) != 0 ? 1 : 0));
		}
		ans += m * q;


		cout << ans << endl;
		/*if (ans != stup(x, y, p, q)) {
			cout << x << ' ' << y << ' ' << p << ' ' << q << endl;
			cout << ans << endl << stup(x, y, p, q) << endl;
			return 0;
		}*/
	}
	return 0;
}
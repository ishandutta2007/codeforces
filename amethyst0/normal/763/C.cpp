/*AMETHYSTS*/
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
#include <unordered_set>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;
int v[maxn];
int cnt[maxn];

ll my_pow(ll a, ll b, ll m) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return (a * my_pow(a, b - 1, m)) % m;
	}

	ll t = my_pow(a, b >> 1, m);

	return (t * t) % m;
}

int main() {
	int n, m;

	cin >> m >> n;

	ll sum = 0;
	ll sumsq = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n);

	bool st = false;

	if (n == 1) {
		cout << v[0] << ' ' << 0 << endl;
		return 0;
	}

	if (n >= m) {
		for (int i = 0; i < n; i++) {
			cnt[v[i]]++;
		}

		int x = n / m;
		
		vector <int> vv;

		for (int i = 0; i < m; i++) {
			if (cnt[i] < x) {
				cout << -1 << endl;
				return 0;
			}

			cnt[i] -= x;

			if (cnt[i] > 1) {
				cout << -1 << endl;
				return 0;
			}

			if (cnt[i] == 1) {
				vv.push_back(i);
			}
		}

		n = (int)vv.size();

		for (int i = 0; i < n; i++) {
			v[i] = vv[i];
		}

		if (n == 1) {
			cout << v[0] << ' ' << 1 << endl;
			return 0;
		}

		if (n == 0) {
			cout << 0 << ' ' << 1 << endl;
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		sum += v[i];

		if (sum >= m) {
			sum -= m;
		}

		sumsq = (sumsq + (ll)v[i] * v[i]) % m;
	}

	sum = (sum * my_pow(n, m - 2, m)) % m;
	sumsq = (sumsq * my_pow(n, m - 2, m)) % m;

	ll six = my_pow(6, m - 2, m);
	ll nn = my_pow(n - 1, m - 2, m);

	ll h = 0;

	for (int i = 0; i < n; i++) {
		h += (ll)i * i;
		h %= m;
	}

	h *= my_pow(n, m - 2, m);
	h %= m;

	set <int> s;

	for (int i = 0; i < n; i++) {
		s.insert(v[i]);
	}

	for (int i = 0; i < n; i++) {
		ll a = v[i];

		ll d = sum - a;
		if (d < 0) {
			d += m;
		}

		d *= 2;

		if (d >= m) {
			d -= m;
		}

		d *= nn;
		d %= m;

		if (d == 0) {
			continue;
		}

		if ((a * a + (a * d % m) * (n - 1) + (d * d % m) * h) % m != sumsq) {
			continue;
		}

		st = true;

		for (int j = 0; j < n; j++) {
			ll x = a + j * d;
			x %= m;

			if (!s.count(x)) {
				st = false;
				break;
			}
		}

		if (st) {
			cout << a << ' ' << d << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}
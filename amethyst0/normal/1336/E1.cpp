#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)2e5 + 10, mod = 998244353;

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int sub(int x, int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

int mul(int x, int y) {
	return (ll)x * y % mod;
}

ll v[maxn];

vector <ll> g;

int cntg(ll x) {
	int ans = 0;
	while (x) {
		ans += x & 1;
		x >>= 1;
	}
	return ans;
}

int res[100];

int my_pow(int x, int y) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}

		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}

	sort(v, v + n);
	reverse(v, v + n);

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		ll y = v[i];

		for (ll x : g) {
			if ((y ^ x) < y) {
				y ^= x;
			}
		}

		if (y == 0) {
			cnt++;
		}
		else {
			g.push_back(y);
		}
	}

	int mag = 18;

	map <pair <ll, int>, int> num[2];

	num[0][mp(0, 0)] = 1;
	int it = 1;

	for (ll x : g) {
		num[it].clear();

		int o = 35;

		while (((x >> o) & 1) == 0) {
			o--;
		}

		for (auto itr : num[it ^ 1]) {
			ll y = itr.first.first ^ x;
			int cn = itr.first.second;
			int tot = itr.second;

			if ((y >> o) & 1) {
				y ^= (1ll << o);
				cn++;
			}

			auto &w = num[it][mp(y, cn)];
			w = add(w, tot);

			y = itr.first.first;
			cn = itr.first.second;
			tot = itr.second;

			if ((y >> o) & 1) {
				y ^= (1ll << o);
				cn++;
			}

			auto &w1 = num[it][mp(y, cn)];
			w1 = add(w1, tot);
		}

		it ^= 1;
	}

	it ^= 1;

	int st = my_pow(2, cnt);

	for (auto itr : num[it]) {
		ll x = itr.first.first;
		int cn = cntg(x) + itr.first.second;
		int tot = itr.second;

		res[cn] = add(res[cn], mul(tot, st));
	}

	for (int i = 0; i <= m; i++) {
		cout << res[i] << ' ';
	}
}
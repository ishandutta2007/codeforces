//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)2e5 + 10, mod = 998244353;
int p[maxn];

int r[110];

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

int my_pow(int x, int y) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}

		x = mul(x, x);
		y >>= 1;
	}

	return ans;
}

pii t[4 * maxn];

pii recalc(pii a, pii b) {
	pii ans;
	ans.second = mul(a.second, b.second);
	ans.first = add(b.first, mul(a.first, b.second));
	return ans;
}

void build(int it, int l, int r) {
	if (l == r) {
		t[it] = mp(p[l], p[l]);
	}
	else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);
		t[it] = recalc(t[2 * it], t[2 * it + 1]);
	}
}

pii go(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		return t[it];
	}
	else {
		int m = (l + r) >> 1;

		if (rm <= m) {
			return go(2 * it, l, m, lm, rm);
		}
		else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm);
		}
		else {
			return recalc(go(2 * it, l, m, lm, m), go(2 * it + 1, m + 1, r, m + 1, rm));
		}
	}
}

int main() {
	for (int i = 1; i < 110; i++) {
		r[i] = my_pow(i, mod - 2);
	}

	int n, q;

	cin >> n >> q;

	set <int> s;
	
	s.insert(0);
	s.insert(n);

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);
		p[i] = mul(100, r[x]);
	}

	build(1, 0, n - 1);

	int ans = t[1].first;

	while (q--) {
		int x;

		scanf("%d", &x);
		x--;

		if (s.count(x)) {
			auto it = s.lower_bound(x);
			auto nit = it;
			nit++;
			ans = sub(ans, go(1, 0, n - 1, *it, (*nit) - 1).first);
			it--;
			nit--;
			ans = sub(ans, go(1, 0, n - 1, *it, (*nit) - 1).first);
			s.erase(x);
			nit = it;
			nit++;
			ans = add(ans, go(1, 0, n - 1, *it, (*nit) - 1).first);
		}
		else {
			auto nit = s.lower_bound(x);
			auto it = nit;
			it--;
			ans = sub(ans, go(1, 0, n - 1, *it, (*nit) - 1).first);
			s.insert(x);
			nit = it;
			nit++;
			ans = add(ans, go(1, 0, n - 1, *it, (*nit) - 1).first);
			it++;
			nit++;
			ans = add(ans, go(1, 0, n - 1, *it, (*nit) - 1).first);
		}

		printf("%d\n", ans);
	}

	//system("pause");
}
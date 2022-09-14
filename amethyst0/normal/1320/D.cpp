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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)2e5 + 10;
char s[maxn];

const int p = (int)1e9 + 7, q = (int)1e9 + 9;

int add(int x, int y, int mod) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}

	return x;
}

int sub(int x, int y, int mod) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

int mul(int x, int y, int mod) {
	return (ll)x * y % mod;
}

int my_pow(int x, int y, int mod) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = mul(ans, x, mod);
		}

		x = mul(x, x, mod);
		y >>= 1;
	}

	return ans;
}

pii operator +(pii a, pii b) {
	a.first = add(a.first, b.first, p);
	a.second = add(a.second, b.second, q);
	return a;
}

pii operator -(pii a, pii b) {
	a.first = sub(a.first, b.first, p);
	a.second = sub(a.second, b.second, q);
	return a;
}

pii operator *(pii a, pii b) {
	a.first = mul(a.first, b.first, p);
	a.second = mul(a.second, b.second, q);
	return a;
}

pii st[maxn];
pii rst;

struct vt {
	pii hsh;
	int cnt;
	bool last;
	bool fir;

	vt() : hsh(mp(0, 0)), cnt(0), last(false), fir(false) {

	}
};

vt t[4 * maxn];

vt merg(vt a, vt b) {
	if (a.cnt == 0) {
		return b;
	}

	if (b.cnt == 0) {
		return a;
	}

	vt ans;
	
	if (!a.last || !b.fir) {
		ans.cnt = a.cnt + b.cnt;
		ans.last = b.last;
		ans.fir = a.fir;
		ans.hsh = a.hsh + b.hsh * st[a.cnt];
	}
	else {
		ans.cnt = a.cnt + b.cnt - 2;
		if (b.cnt > 1) {
			ans.last = b.last;
		}
		else {
			ans.last = 0;
		}

		if (a.cnt > 1) {
			ans.fir = a.fir;
		}
		else {
			ans.fir = 0;
		}

		int d = a.cnt;

		ans.hsh = a.hsh - st[d - 1] + (b.hsh - st[0]) * rst * st[d - 1];
	}

	return ans;
}

void build(int it, int l, int r) {
	if (l == r) {
		if (s[l] == '1') {
			t[it].last = true;
			t[it].fir = true;
			t[it].hsh = st[0];
			t[it].cnt = 1;
		}
		else {
			t[it].cnt = 1;
		}
	}
	else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);
		t[it] = merg(t[2 * it], t[2 * it + 1]);
	}
}

vt go(int it, int l, int r, int lm, int rm) {
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
			return merg(go(2 * it, l, m, lm, m), go(2 * it + 1, m + 1, r, m + 1, rm));
		}
	}
}

int main() {
	int n;

	cin >> n;
	scanf("%s", s);

	st[0] = mp(1, 1);

	for (int i = 1; i < maxn; i++) {
		st[i] = st[i - 1] * mp(1234567, 7654321);
	}

	rst.first = my_pow(st[1].first, p - 2, p);
	rst.second = my_pow(st[1].second, q - 2, q);

	build(1, 0, n - 1);

	int q;

	cin >> q;

	while (q--) {
		int a, b, l;

		scanf("%d %d %d", &a, &b, &l);

		a--;
		b--;

		vt x = go(1, 0, n - 1, a, a + l - 1);
		vt y = go(1, 0, n - 1, b, b + l - 1);

		if (x.hsh == y.hsh && x.cnt == y.cnt) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
}
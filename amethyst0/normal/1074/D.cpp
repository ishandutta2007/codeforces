#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

map <ll, ll> p;
map <ll, ll> ch;
map <ll, int> sz;

pll getp(ll x) {
	if (x == p[x]) {
		return mp(x, 0);
	}

	pll g = getp(p[x]);

	ch[x] ^= g.second;
	g.second = ch[x];
	p[x] = g.first;
	return g;
}

ll go(ll x, ll y) {
	if (!p.count(x) || !p.count(y)) {
		return -1;
	}

	pll a = getp(x);
	pll b = getp(y);

	if (a.first != b.first) {
		return -1;
	}

	return ch[x] ^ ch[y];
}

void add(ll x, ll y, ll d) {
	if (!p.count(x)) {
		p[x] = x;
		sz[x] = 1;
		ch[x] = 0;
	}

	if (!p.count(y)) {
		p[y] = y;
		sz[y] = 1;
		ch[y] = 0;
	}

	pll a = getp(x);
	pll b = getp(y);

	if (a.first == b.first) {
		return;
	}
	else {
		if (sz[a.first] > sz[b.first]) {
			swap(a, b);
			swap(x, y);
		}

		sz[b.first] += sz[a.first];
		p[a.first] = b.first;
		ch[a.first] ^= d ^ ch[x] ^ ch[y];
	}
}

int main() {
	int q;

	cin >> q;

	ll last = 0;

	while (q--) {
		int t;

		scanf("%d", &t);

		if (t == 1) {
			ll l, r, x;

			scanf("%lld %lld %lld", &l, &r, &x);

			l ^= last;
			r ^= last;
			x ^= last;

			if (l > r) {
				swap(l, r);
			}

			r++;

			add(l, r, x);
		}
		else {
			ll l, r;

			scanf("%lld %lld", &l, &r);

			l ^= last;
			r ^= last;

			if (l > r) {
				swap(l, r);
			}

			r++;

			ll ans = go(l, r);

			printf("%lld\n", ans);

			if (ans == -1) {
				last = 1;
			} else {
				last = ans;
			}
		}
	}

	//system("pause");
}
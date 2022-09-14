#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#include <list>
#include <numeric>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)5010;

struct vt {
	ll x, y;

	vt() {

	}

	vt(ll x, ll y) : x(x), y(y) {

	}
};

ll operator *(vt a, vt b) {
	return a.x * b.x + a.y * b.y;
}

vt operator -(vt a, vt b) {
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

vt v[maxn];
int p[maxn];

bool bad(int a, int b, int c) {
	return (v[a] - v[b]) * (v[c] - v[b]) <= 0;
}

mt19937 rr;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &v[i].x, &v[i].y);
		p[i] = i;
	}

	shuffle(p, p + n, rr);

	while (true) {
		bool ok = true;

		for (int i = 2; i < n; i++) {
			if (bad(p[i - 2], p[i - 1], p[i])) {
				ok = false;
				swap(p[i - 1], p[i]);
			}
		}

		if (ok) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", p[i] + 1);
	}
	printf("\n");
}
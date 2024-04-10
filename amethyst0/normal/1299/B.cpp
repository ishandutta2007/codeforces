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
#include <fstream>
#include <bitset>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

struct vt {
	ll x, y;

	vt() {

	}

	vt(ll x, ll y) : x(x), y(y) {

	}
};

vt operator +(vt a, vt b) {
	a.x += b.x;
	a.y += b.y;
	return a;
}

vt operator -(vt a, vt b) {
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

const int maxn = (int)1e6;

vt v[maxn];

int main() {
	int n;

	cin >> n;

	if (n & 1) {
		cout << "NO\n";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &v[i].x, &v[i].y);
	}

	for (int i = 0; i < n; i++) {
		int nx = (i + 1) % n;
		int p = (i + n / 2) % n;
		int np = (p + 1) % n;

		vt a = v[nx] - v[i] + (v[np] - v[p]);

		if (a.x != 0 || a.y != 0) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
}
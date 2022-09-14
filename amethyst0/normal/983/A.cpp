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
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
#define mp make_pair

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

ll mul(ll x, ll y, ll p) {
	if (y == 0) {
		return 0;
	}

	if (y & 1) {
		ll z = mul(x, y - 1, p);

		z += x;

		if (z >= p) {
			z -= p;
		}

		return z;
	}

	ll z = mul(x, y >> 1, p) << 1;

	if (z >= p) {
		z -= p;
	}

	return z;
}

int main() {
	int n;

	cin >> n;

	while (n--) {
		ll p, q, b;

		scanf("%lld %lld %lld", &p, &q, &b);

		ll g = gcd(p, q);

		q /= g;

		b %= q;

		for (int i = 0; i < 6; i++) {
			b = mul(b, b, q);
		}

		if (b != 0) {
			printf("Infinite\n");
		}
		else {
			printf("Finite\n");
		}
	}

	//system("pause");
}
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
typedef long double ld;
#define mp make_pair

const int maxn = (int)3e5 + 10;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	ll ans = -1;

	int n;

	cin >> n;

	ll xx, yy;

	for (int i = 0; i < n; i++) {
		ll x, y;

		scanf("%lld %lld", &x, &y);
		xx = x;
		yy = y;

		x = x / gcd(x, y) * y;
		if (i == 0) {
			ans = x;
		}
		else {
			ans = gcd(ans, x);
		}
	}

	ll a = gcd(ans, xx);

	if (a == 1) {
		a = gcd(ans, yy);
	}

	if (a == 1) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			cout << i << endl;
			return 0;
		}
	}

	cout << a << endl;

	//system("pause");
}
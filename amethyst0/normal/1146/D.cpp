#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

const int maxn = (int)3e5 + 10;
int ans[maxn];

ll solve(ll x, ll g, ll f) {
	if (x >= f) {
		ll c = (x - f) / g + 1;
		x -= c * g;
		return ans[x] + c;
	}
	else {
		return ans[x];
	}
}

int main() {
	int m, a, b;

	cin >> m >> a >> b;

	int f = a + b;

	int g = gcd(a, b);

	for (int i = 0; i < a; i++) {
		ans[i] = 1;
	}

	int prev = 0;
	int numb = 1;

	for (int i = a; i < f; i++) {
		while (true) {
			while (prev > b) {
				prev -= b;
				numb++;
			}

			if (prev + a <= i) {
				prev += a;
				numb++;
			}
			else {
				break;
			}
		}

		ans[i] = numb;
	}

	ll sum = 0;

	for (int i = f - g; i < f; i++) {
		sum += ans[i];
	}

	ll res = 0;

	while (m >= 0 && m % g != g - 1) {
		res += solve(m, g, f);
		m--;
	}

	if (m >= f) {
		ll c = (m - f + 1) / g;
		res += c * (c + 1) / 2 * g;
		res += c * sum;
		for (int i = 0; i < f; i++) {
			res += ans[i];
		}
	}
	else {
		for (int i = 0; i <= m; i++) {
			res += ans[i];
		}
	}

	cout << res << endl;

	//system("pause");

	return 0;
}
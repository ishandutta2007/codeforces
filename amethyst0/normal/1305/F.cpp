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
ll v[maxn];

vector <ll> pr;

void getp(ll x) {
	pr.clear();
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			pr.push_back(i);

			while (x % i == 0) {
				x /= i;
			}
		}
	}

	if (x > 1) {
		pr.push_back(x);
	}
}

int n;

int go(ll p) {
	ll ans = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] < p) {
			ans += p - v[i];
		}
		else {
			ll x = v[i] % p;
			ans += min(x, p - x);
		}

		if (ans > n) {
			return n + 1;
		}
	}

	return (int)ans;
}

int solve(int pos) {
	int ans = n + 1;
	for (int d = -2; d <= 2; d++) {
		ll x = v[pos] + d;

		if (x > 0) {
			getp(x);

			for (ll p : pr) {
				ans = min(ans, go(p));
			}
		}
	}

	return ans;
}

int main() {
	cin >> n;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);

		if ((v[i] & 1)) {
			ans++;
		}
	}

	for (int i = 0; i < 10; i++) {
		int pos = rand() % n;

		ans = min(ans, solve(pos));
	}

	cout << ans << '\n';
}
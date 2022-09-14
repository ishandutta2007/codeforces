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

const int maxn = (int)2e5 + 10, mod = 998244353;

int v[maxn];

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	ll ans = 0;

	for (int i = n; i > n - k; i--) {
		ans += i;
	}

	cout << ans << ' ';

	set <int> s;

	for (int i = 0; i < n; i++) {
		if (v[i] > n - k) {
			s.insert(i);
		}
	}

	auto it = s.begin();

	int res = 1;

	for (int i = 0; i < k - 1; i++) {
		auto nit = next(it);

		res = (ll)res * (*nit - *it) % mod;
		it = nit;
	}

	cout << res << '\n';
}
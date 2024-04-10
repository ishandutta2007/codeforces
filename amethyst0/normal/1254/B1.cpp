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

const int maxn = (int)1e6 + 10;
ll v[maxn];

const ll inf = (ll)1e18;

int n;

ll check(ll x) {
	ll ans = 0;

	for (int i = 0; i < n - 1; i++) {
		ll y = v[i] % x;
		ans += min(y, x - y);
	}

	return ans;
}

int main() {
	cin >> n;

	ll cur = 0;

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		cur += x;
		v[i] = cur;
	}

	if (v[n - 1] == 1) {
		cout << -1 << endl;
		return 0;
	}

	ll ans = inf;

	for (ll i = 1; i * i <= v[n - 1]; i++) {
		if (v[n - 1] % i == 0) {
			if (i != 1) {
				ans = min(ans, check(i));
			}

			if (i * i != v[n - 1]) {
				ans = min(ans, check(v[n - 1] / i));
			}
		}
	}

	cout << ans << endl;

	//system("pause");
}
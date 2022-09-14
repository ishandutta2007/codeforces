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

const int maxn = (int)2e5 + 10, mod = 998244353;

int my_pow(int x, int y) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = (ll)ans * x % mod;
		}

		x = (ll)x * x % mod;
		y >>= 1;
	}

	return ans;
}

int f[maxn], rf[maxn];

int C(int a, int b) {
	return ((ll)f[a] * rf[b] % mod) * rf[a - b] % mod;
}

int v[maxn];

int main() {
	f[0] = 1;
	rf[0] = 1;

	for (int i = 1; i < maxn; i++) {
		f[i] = (ll)f[i - 1] * i % mod;
		rf[i] = my_pow(f[i], mod - 2);
	}

	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int nx = (i + 1) % n;

		if (v[i] != v[nx]) {
			cnt++;
		}
	}

	ll ans = 0;

	int r2 = my_pow(2, mod - 2);

	for (int i = 1; i <= cnt; i++) {
		int cur = C(cnt, i);
		cur = (ll)cur * my_pow(k - 2, cnt - i) % mod;
		cur = (ll)cur * my_pow(k, n - cnt) % mod;

		if (i % 2 == 1) {
			cur = (ll)cur * my_pow(2, i - 1) % mod;
		}
		else {
			int p = my_pow(2, i);
			p -= C(i, i / 2);
			if (p < 0) {
				p += mod;
			}

			p = (ll)p *r2 % mod;
			cur = (ll)cur * p % mod;
		}

		ans += cur;
	}

	cout << (ans % mod) << endl;

	//system("pause");
}
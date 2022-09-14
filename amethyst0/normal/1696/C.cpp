#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <cstdio>
#include <cassert>
#include <cstring>
#include <unordered_set>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = 2010;
const int p = (int)1e9 + 7, q = 998244353;
int t = 263517632;

int mul(int x, int y, int mod) {
	return (ll)x * y % mod;
}

pii operator +(pii a, pii b) {
	a.first += b.first;
	if (a.first >= p) {
		a.first -= p;
	}
	a.second += b.second;
	if (a.second >= q) {
		a.second -= q;
	}
	return a;
}

pii operator *(pii a, pii b) {
	a.first = mul(a.first, b.first, p);
	a.second = mul(a.second, b.second, q);
	return a;
}

int my_pow(int x, int y, int mod) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = mul(ans, x, mod);
		}

		x = mul(x, x, mod);
		y >>= 1;
	}
	return ans;
}

int main() {
	int tt;
	cin >> tt;

	pii rt = { my_pow(t - 1, p - 2, p), my_pow(t - 1, q - 2, q) };

	while (tt--) {
		int n, m;
		scanf("%d %d", &n, &m);
		pii cur = mp(1, 1);
		pii ans = mp(0, 0);
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			int cnt = 1;
			while (x % m == 0) {
				x /= m;
				cnt *= m;
			}

			pii f = { my_pow(t, cnt, p), my_pow(t, cnt, q) };
			pii g = f;
			f.first--;
			if (f.first < 0) {
				f.first += p;
			}
			f.second--;
			if (f.second < 0) {
				f.second += q;
			}

			f = f * rt;
			f = f * mp(x, x);
			f = f * cur;
			ans = ans + f;
			cur = cur * g;
		}

		scanf("%d", &n);

		cur = mp(1, 1);
		pii ans1 = mp(0, 0);
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			int cnt = 1;
			while (x % m == 0) {
				x /= m;
				cnt *= m;
			}

			pii f = { my_pow(t, cnt, p), my_pow(t, cnt, q) };
			pii g = f;
			f.first--;
			if (f.first < 0) {
				f.first += p;
			}
			f.second--;
			if (f.second < 0) {
				f.second += q;
			}

			f = f * rt;
			f = f * mp(x, x);
			f = f * cur;
			ans1 = ans1 + f;
			cur = cur * g;
		}

		if (ans == ans1) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
}
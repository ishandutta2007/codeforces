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

const int mod = (int)1e9 + 7;

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int my_pow(int x, int y) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}

		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

int sub(int x, int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n, p;

		scanf("%d %d", &n, &p);

		vector <int> v(n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}

		if (p == 1) {
			printf("%d\n", n % 2);
			continue;
		}

		sort(all(v));
		reverse(all(v));

		int cur = v[0];
		int cnt = 1;

		bool ok = true;

		for (int i = 1; i < (int)v.size(); i++) {
			int dt = cur - v[i];

			if (ok) {
				if (dt >= 20 && cnt != 0) {
					ok = false;
					cnt = mul(cnt, my_pow(p, dt));
				}
				else if (cnt != 0) {
					for (int i = 0; i < dt; i++) {
						if ((ll)cnt * p > (int)1e6) {
							ok = false;
						}

						cnt = mul(cnt, p);
					}
				}
			}
			else {
				cnt = mul(cnt, my_pow(p, dt));
			}

			if (!ok) {
				cnt = sub(cnt, 1);
			}
			else {
				if (cnt == 0) {
					cnt = 1;
				}
				else {
					cnt = sub(cnt, 1);
				}
			}

			cur = v[i];
		}

		printf("%d\n", mul(cnt, my_pow(p, cur)));
	}
}
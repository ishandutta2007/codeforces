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

const int maxn = 510, mod = (int)1e9 + 7;
char ss[maxn];

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

int sub(int x, int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

int my_pow(int x, int y) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}

		y >>= 1;
		x = mul(x, x);
	}

	return ans;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		int x;
		scanf("%d", &x);

		scanf("%s", ss);

		int n = strlen(ss);

		string s;

		int sr = 0;

		for (int i = 0; i < n; i++) {
			s.push_back(ss[i]);
			sr = mul(sr, 10);
			sr = add(sr, s.back() - '0');
		}

		int len = n;

		int ans = 0;

		for (int i = 1; i <= x; i++) {
			if ((int)s.size() <= x && s[i - 1] != '1') {
				string t = "";

				for (int j = i; j < (int)s.size(); j++) {
					t += s[j];
				}

				s += t;
				if (s[i - 1] == '3') {
					s += t;
				}
			}

			ans++;

			len--;
			if (len < 0) {
				len += mod;
			}

			int cnt = s[i - 1] - '0';

			len = mul(len, cnt);
		}

		printf("%d\n", ans + len);
	}
	//system("pause");
}
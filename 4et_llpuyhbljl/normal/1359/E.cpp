#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<random>
#include<bitset>
using namespace std;
typedef long double ld;
#define double long double
inline int getint() {
	int val = 0;
	char c;
	while ((c = getchar()) && !(c >= '0' && c <= '9'));
	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));
	return val;
}
const int Y = 500100;
const long long m = 998244353;
long long pw(long long et, int b) {
	if (b == 0)return 1;
	long long tmp = pw(et, b / 2);
	tmp = (tmp * tmp) % m;
	if (b % 2 == 1)tmp = (tmp * et) % m;
	return tmp;
}
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
const long long INF = 1e17, add = 1e5;
long long f[Y];
long long g[Y];
long long c(int n, int k) {
	return f[n] * g[k] % m * g[n - k] % m;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(15);
	f[0] = g[0] = 1;
	int n, k;
	cin >> n >> k;
	long long ans = 0;
	for (int i = 1; i < Y; ++i) {
		f[i] = f[i - 1] * i % m;
		g[i] = pw(f[i], m - 2);
	}
	for (int i = 1; i <= n; ++i) {
		int ct = n / i;
		if (ct < k)break;
		else {
			ans = (ans + c(ct - 1, k - 1)) % m;
		}
	}
	cout << ans;
	return 0;
}
/* Fri Apr 17 2020 21:48:38 GMT+0300 (MSK) */

/* Sat Apr 18 2020 00:44:00 GMT+0300 (MSK) */
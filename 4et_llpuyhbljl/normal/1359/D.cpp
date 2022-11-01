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
/*long long pw(long long et, int b) {
	if (b == 0)return 1;
	long long tmp = pw(et, b / 2);
	tmp = (tmp * tmp) % m;
	if (b % 2 == 1)tmp = (tmp * et) % m;
	return tmp;
}*/
const int Y = 100100;
//const long long m = 998244353;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
const long long INF = 1e17, add = 1e5;
long long a[Y];
long long p[Y];
long long s[Y];
int mt[61];
long long tree[4 * add + 10000];
int sz = 1;
void a1(int id, long long s) {
	id += sz;
	tree[id] = s;
	while (id) {
		tree[id] = min(tree[id], s);
		id /= 2;
	}
}
long long g1(int ql, int qr, int v, int tl, int tr) {
	if (ql <= tl && tr <= qr)return tree[v];
	int mid = (tr+tl) / 2;
	long long res = INF;
	if (ql <= mid)res = min(res, g1(ql, qr, 2 * v, tl, mid));
	if (qr > mid)res = min(res, g1(ql, qr, 2 * v + 1, mid + 1, tr));
	return res;
}
void a2(int id, long long s) {
	id += sz;
	tree[id] = s;
	while (id) {
		tree[id] = max(tree[id], s);
		id /= 2;
	}
}
long long g2(int ql, int qr, int v, int tl, int tr) {
	if (ql <= tl && tr <= qr)return tree[v];
	int mid = (tr + tl) / 2;
	long long res = -INF;
	if (ql <= mid)res = max(res, g2(ql, qr, 2 * v, tl, mid));
	if (qr > mid)res = max(res, g2(ql, qr, 2 * v + 1, mid + 1, tr));
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(15);
	fill(begin(tree), end(tree), INF);
	while (sz <= add + 10)sz <<= 1;
	long long ans = 0;
	int n;
	cin >> n;
	a1(0, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
		a1(i, p[i]);
		int id = 0;
		for (int j = a[i] + 30 + 1; j <= 60; ++j) {
			id = max(id, mt[j]);
		}
		s[i] = p[i - 1] - g1(id, i - 1, 1, 0, sz - 1);
		mt[a[i] + 30] = i;
	}
	for (int j = 0; j <= 60; ++j)mt[j] = n + 1;
	fill(begin(tree), end(tree), -INF);
	for (int i = n; i > 0; --i) {
		a2(i, p[i]);
		int id = n;
		for (int j = a[i] + 30 + 1; j <= 60; ++j) {
			id = min(id, mt[j] - 1);
		}
		mt[a[i] + 30] = i;
		s[i] += g2(i, id, 1, 0, sz - 1) - p[i];
	}

	for (int i = 1; i <= n; ++i) {
		ans = max((long long)s[i], ans);
	}
	cout << ans;
	return 0;
}
/* Fri Apr 17 2020 21:48:38 GMT+0300 (MSK) */

/* Sat Apr 18 2020 00:44:00 GMT+0300 (MSK) */
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

const int maxn = 2050, mod = 998244353;

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

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int dp[maxn][maxn];

int go(int x, int y) {
	if (x == 0) {
		return 1;
	}

	if (y > x) {
		return dp[x][y] = 1;
	}

	if (dp[x][y] != -1) {
		return dp[x][y];
	}

	return dp[x][y] = add(go(x, y + 1), go(x - y, y));
}

struct vt {
	int pos;
	int x;
	int lim;

	vt() {

	}

	vt(int pos, int x, int lim): pos(pos), x(x), lim(lim) {

	}
};

const int maxsq = 70;

vector <int> dp2[maxsq][maxn];

int go(vt a) {
	a.x = min(a.x, a.lim / a.pos);
	if (dp2[a.pos][a.lim][a.x] != -1) {
		return dp2[a.pos][a.lim][a.x];
	}

	if (a.x == 0) {
		return dp2[a.pos][a.lim][a.x] = 1;
	}

	vt b = a;
	b.x--;

	int ans = go(b);
	b = a;

	if (b.lim >= b.x * b.pos) {
		b.lim -= b.x * b.pos;
		b.pos++;
		ans = add(ans, go(b));
	}

	return dp2[a.pos][a.lim][a.x] = ans;
}

bool check2(vector <int> &a, int lim) {
	int sum = 0;

	for (int i = 0; i < (int)a.size(); i++) {
		sum += a[i] * ((int)a.size() - i);
	}

	return sum <= lim;
}

set <vector <int> > s[maxn];

bool check(vector <int> &a, int k, int lim) {
	if (k == 2) {
		return check2(a, lim);
	}
	else {
		return s[k].count(a);
	}
}

vector <int> p;

bool good(int k, int lim) {
	vector <int> ch;

	for (int i = (int)p.size() - 1; i >= 0; i--) {
		int x = (int)p.size() - i;

		for (int j = 0; j < p[i]; j++) {
			ch.push_back(x);
		}
	}

	return check(ch, k - 1, lim);
}

bool gen(int k, int lim) {
	if (!good(k, lim)) {
		return false;
	}

	s[k].insert(p);
	int x = (p.empty() ? 1 : p.back());

	while (true) {
		p.push_back(x);
		if (!gen(k, lim)) {
			p.pop_back();
			break;
		}
		p.pop_back();
		x++;
	}

	return true;
}

int main() {
	for (int pos = 1; pos < maxsq; pos++) {
		for (int lim = 0; lim < maxn; lim++) {
			dp2[pos][lim].assign(lim / pos + 1, -1);
		}
	}

	memset(dp, -1, sizeof dp);

	int n, k;
	cin >> n >> k;

	if (k == 2) {
		cout << sub(go({ 1, n, n }), 1) << '\n';
		return 0;
	}
	else if (k == 1) {
		cout << sub(go(n, 1), 1) << '\n';
		return 0;
	}

	for (int i = 3; i <= k; i++) {
		gen(i, n);
	}

	cout << sub((int)s[k].size(), 1) << '\n';
}
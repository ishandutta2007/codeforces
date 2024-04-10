#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()

template<typename T> bool uin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<typename T> bool uax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream & out = cerr) {
	while (begin != end) {
		out << (*begin) << ' ';
		begin++;
	}
	out << '\n';
}

template<class T> void output(T x, ostream & out = cerr) {
	output(all(x), out);
}

mt19937 rnd(time(NULL));

int c[20][4];
ll st10[19];
void pre_calc() {
	forn(i, 20) c[i][0] = 1ll;
	for (int i = 1; i < 20; ++i)
		for (int j = 1; j < 4; ++j)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	st10[0] = 1ll;
	for (int i = 1; i <= 18; ++i) st10[i] = st10[i - 1] * 10ll;
}

void chi(ll k, vector<int> & a) {
	while (k > 0) {
		a.push_back(k % 10);
		k /= 10;
	}
	reverse(all(a));
}
int ans(ll r) {
	if (r == 0)
		return 0;
	vector<int> a;
	chi(r, a);
	int cnt = 3;
	ll an = 0;
	forn(i, a.size()) {
		if (cnt < 0)
			break;
		if (a[i] > 0) {
			if (cnt >= 3)
				an += c[(int)a.size() - i - 1][3] * 729ll;
			if (cnt >= 2)
				an += c[(int)a.size() - i - 1][2] * 81ll;
			if (cnt >= 1)
				an += c[(int)a.size() - i - 1][1] * 9ll;
			an++;
		}
		if (a[i] > 0) cnt--;
		if (cnt >= 2)
			an += c[(int)a.size() - i - 1][2] * 81ll * max(0, a[i] - 1);
		if (cnt >= 1)
			an += c[(int)a.size() - i - 1][1] * 9ll * max(0, a[i] - 1);
		if (cnt >= 0)
			an += 1ll * max(0, a[i] - 1);
	}
	if (cnt >= 0) {
		an++;
	}
	return an - 1;
}

int ans(ll l, ll r) {
	return ans(r) - ans(l - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pre_calc();
	int t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		cout << ans(l, r) << '\n';
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
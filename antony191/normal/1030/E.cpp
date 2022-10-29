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

template<class iterator> void output(iterator begin, iterator end, ostream & out = cout) {
	while (begin != end) {
		out << (*begin) << ' ';
		begin++;
	}
	out << '\n';
}

template<class T> void output(T x, ostream & out = cout) {
	output(all(x), out);
}

mt19937 rnd(time(NULL));

ll gcd(ll a, ll b) {
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int cnt(ll a) {
	int ans = 0;
	while (a > 0) {
		if (a & 1)
			ans++;
		a >>= 1;
	}
	return ans;
}

vector<int> pref;

ll aa(int l, int r) {
	int cnt1 = 0, cnt2 = 0;
	for (int i = l; i <= r; ++i)
		if (pref[i])
			cnt2++;
		else
			cnt1++;
	return cnt1 * 1ll * (cnt1 - 1) / 2ll + cnt2 * 1ll * (cnt2 - 1) / 2ll;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> a(n);
	forn(i, n)
		cin >> a[i];
	vector<int> sum(n);
	forn(i, n)
		sum[i] = cnt(a[i]);
	pref.resize(n + 1);
	forn(i, n)
		pref[i + 1] = (pref[i] + sum[i]) & 1;
	int cnt1 = 0, cnt2 = 0;
	ll ans = aa(0, n);
	forn(i, n) {
		int l = i;
		int s = 0;
		while (l && s + sum[l - 1] < sum[i]) {
			l--;
			s += sum[l];
		}
		int r = i;
		while (l <= i) {
			while (r < n - 1 && s + sum[r + 1] < sum[i]) {
				r++;
				s += sum[r];
			}
			int cnt1 = 0;
			for (int j = i + 1; j <= r + 1; ++j)
				if (pref[j] == pref[l])
					cnt1++;
			ans -= cnt1;
			s -= sum[l];
			l++;
		}
	}
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
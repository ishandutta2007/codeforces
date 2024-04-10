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

const int inf = 1e9, mod = 1000'000'007;
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	forn(i, n) cin >> a[i];
	vector<int> len;
	for (int i = k; i <= n; i += k - 1) {
		len.push_back(i);
	}
	vector<ll> an(n, 0);
	int l = 0;
	forn(i, n) {
		if (l < (int)len.size() && len[l] <= i + 1)
			l++;
		an[i] = (i > 0 ? an[i - 1] : 0ll) + l * 1ll;
		an[i] %= mod;
	}
	vector<int> lefmax(n, -1), rimax(n, n);
	vector<int> stack;
	stack.push_back(0);
	for (int i = 1; i < n; ++i) {
		while (!stack.empty() && a[stack.back()] < a[i])
			stack.pop_back();
		if (!stack.empty()) lefmax[i] = stack.back();
		stack.push_back(i);
	}
	stack.clear();
	stack.push_back(n - 1);
	for (int i = n - 2; i + 1; --i) {
		while (!stack.empty() && a[stack.back()] <= a[i])
			stack.pop_back();
		if (!stack.empty()) rimax[i] = stack.back();
		stack.push_back(i);
	}
	ll ans = 0ll;
	for (int i = 0; i < n; ++i) {
		ll cnt = rimax[i] - lefmax[i] - 1;
		ll cnt1 = rimax[i] - i - 1, cnt2 = i - lefmax[i] - 1;
		ll tmp = 0;
		if (cnt1 > 0) tmp += an[cnt1 - 1];
		if (cnt2 > 0) tmp += an[cnt2 - 1];
		tmp %= mod;
		ans += (an[cnt - 1] - tmp) * 1ll * a[i];
		ans %= mod;
	}
	ans = (ans % mod + mod) % mod;
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
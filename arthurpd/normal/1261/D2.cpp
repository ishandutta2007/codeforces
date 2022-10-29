#pragma once

#include <bits/stdc++.h>
using namespace std;

template <class TH>
void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }

template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a)
{
	while (*sdbg != ',')
		cerr << *sdbg++;
	cerr << '=' << h << ',';
	_dbg(sdbg + 1, a...);
}

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

template <class Iterable, class = typename enable_if<!is_same<string, Iterable>::value>::type>
auto operator<<(ostream &os, Iterable v) -> decltype(os << *begin(v))
{
	os << "[";
	for (auto vv : v)
		os << vv << ", ";
	return os << "]";
}

#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }

// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out

const int mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.

int modpow(int b, int e)
{
	int ans = 1;
	for (; e; b = b * (ll)b % mod, e /= 2)
		if (e & 1)
			ans = (ans * (ll)b) % mod;
	return ans;
}

void ntt(vi &a, vi &rt, vi &rev, int n)
{
	for (int i = 0; i < n; i++)
		if (i < rev[i])
			swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k)
			for (int j = 0; j < k; j++)
			{
				int z = (rt[j + k] * (ll)a[i + j + k]) % mod, &ai = a[i + j];
				a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
				ai += (ai + z >= mod ? z - mod : z);
			}
}

vi conv(const vi &a, const vi &b)
{
	if (a.empty() || b.empty())
		return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	vi L(a), R(b), out(n), rt(n, 1), rev(n);
	L.resize(n), R.resize(n);

	for (int i = 0; i < n; i++)
		rev[i] = (rev[i / 2] | (i & 1) << B) / 2;

	int curL = mod / 2, inv = modpow(n, mod - 2);
	for (int k = 2; k < n; k *= 2)
	{
		int z[] = {1, modpow(root, curL /= 2)};
		for (int i = k; i < 2 * k; i++)
			rt[i] = (rt[i / 2] * (ll)z[i & 1]) % mod;
	}

	ntt(L, rt, rev, n);
	ntt(R, rt, rev, n);
	for (int i = 0; i < n; i++)
		out[-i & (n - 1)] = ((L[i] * (ll)R[i]) % mod * (ll)inv) % mod;
	ntt(out, rt, rev, n);
	return {out.begin(), out.begin() + s};
}

vi pot(vi b, ll e)
{
	vi ans = {1};
	for (; e;)
	{
		if (e & 1)
			ans = conv(ans, b);

		e /= 2;
		if (e)
			b = conv(b, b);
	}

	return ans;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	vi h(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
		// h[i] = (rand() % k) + 1;
		// printf("%d\n", h[i]);
	}

	int k1 = 0;
	int k2 = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (h[i] == h[(i + 1) % n])
			k1++;
		else
			k2++;
	}

	vi ans;
	if (k1 > 0)
	{
		ll y = 1;
		for (int i = 0; i < k1; i++)
			y = (k * (ll)y) % mod;

		ans = pot({1, k - 2, 1}, k2);
		vector<int> tmp;
		for (int i = 0; i < k1; i++)
			tmp.push_back(0);
		for (int i = 0; i < ans.size(); i++)
			tmp.push_back((y * (ll)ans[i]) % mod);
		ans = tmp;
	}
	else
	{
		ans = pot({1, k - 2, 1}, k2);
	}

	int x = 0;
	for (int i = n + 1; i < ans.size(); i++)
		x = (x + ans[i]) % mod;
	cout << x << endl;
}
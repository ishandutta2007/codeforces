// https://codeforces.com/contest/1251/problem/F

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

// int main()
// {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// }

/*
	Number Theoretic Transform:
		FFT allows multiplication of two polynomials in O(n log n)
		where you need the coeficients modulo some specific prime.

	Usage:
		Can be used for convolutions modulo specific nice primes
		of the form (b * 2^a + 1), where the convolution result 
		has size at most $2^a$.
		Inputs must be in [0, mod).

	Source: https://cp-algorithms.com/algebra/fft.html
*/

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.

ll modpow(ll b, ll e)
{
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1)
			ans = ans * b % mod;
	return ans;
}

typedef vector<ll> vl;
void ntt(vl &a, vl &rt, vl &rev, int n)
{
	for (int i = 0; i < n; i++)
		if (i < rev[i])
			swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k)
			for (int j = 0; j < k; j++)
			{
				ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
				a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
				ai += (ai + z >= mod ? z - mod : z);
			}
}

vl conv(const vl &a, const vl &b)
{
	if (a.empty() || b.empty())
		return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	vl L(a), R(b), out(n), rt(n, 1), rev(n);
	L.resize(n), R.resize(n);

	for (int i = 0; i < n; i++)
		rev[i] = (rev[i / 2] | (i & 1) << B) / 2;

	ll curL = mod / 2, inv = modpow(n, mod - 2);
	for (int k = 2; k < n; k *= 2)
	{
		ll z[] = {1, modpow(root, curL /= 2)};
		for (int i = k; i < 2 * k; i++)
			rt[i] = rt[i / 2] * z[i & 1] % mod;
	}

	ntt(L, rt, rev, n);
	ntt(R, rt, rev, n);
	for (int i = 0; i < n; i++)
		out[-i & (n - 1)] = L[i] * R[i] % mod * inv % mod;
	ntt(out, rt, rev, n);
	return {out.begin(), out.begin() + s};
}

#define MAXN 312345

vector<ll> pot(vector<ll> b, ll e)
{
	vector<ll> ans = {1};
	for (; e; b = conv(b, b), e /= 2)
		if (e & 1)
			ans = conv(ans, b);
	return ans;
}

int main()
{
	int t = 1;
	while (t--)
	{
		int n, k, a;
		scanf("%d %d", &n, &k);
		vector<int> tab(MAXN, 0);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			tab[a]++;
		}

		vector<ll> ans(4 * MAXN);
		vector<int> b(k);
		for (int i = 0; i < k; i++)
			scanf("%d", &b[i]);
		sort(b.begin(), b.end());

		int k1 = 0, k2 = 0, j = 0;
		vector<ll> p = {1};
		for (int i = 0; i < k; i++)
		{
			for (; j < b[i]; j++)
				if (tab[j] >= 2)
					k2++;
				else if (tab[j] == 1)
					k1++;

			p = conv(p, conv(pot({1, 2}, k1), pot({1, 2, 1}, k2)));
			k1 = 0, k2 = 0;
			for (int l = 0; l < sz(p); l++)
				ans[l + b[i] + 1] = (p[l] + ans[l + b[i] + 1]) % mod;
		}

		int q;
		scanf("%d", &q);
		while (q--)
		{
			scanf("%d", &a);
			printf("%lld\n", ans[a / 2]);
		}
	}
}
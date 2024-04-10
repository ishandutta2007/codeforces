// https://codeforces.com/contest/300/problem/C

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
typedef long double ld;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

template <class T>
T abs(const T &x) {	return (x < T(0)) ? -x : x; }

// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out

/*
	Extended Euclidean Algorithm:
		Returns the gcd of a and b.
		Also finds numbers x and y for which a * x + b * y = gcd(a, b) (not unique).
		All pairs can be represented in the form (x + k * b / gcd, y - k * a / gcd) for k an arbitrary integer.
		If there are several such x and y, the function returns the pair for which |x| + |y| is minimal.
		If there are several x and y satisfying the minimal criteria, it outputs the pair for which X <= Y.

	Source: modified from https://cp-algorithms.com/algebra/extended-euclid-algorithm.html

	Usage:
		For non-extendend version, c++ has __gcd and __lcm.

	Constraints:
		Produces correct results for negative integers as well.
*/

template<class T>
T gcd(T a, T b, T &x, T &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

/*
	Modular Inverse:
		Returns an integer x such that (a * x) % m == 1.
		The modular inverse exists if and only if a and m are relatively prime.
		Modular inverse is also equal to a^(phi(m) - 1) % m.
		In particular, if m is prime a^(-1) == a^(m-2), which might be faster to code.

	Source: modified from https://cp-algorithms.com/algebra/module-inverse.html
*/

template<class T>
T mod_inverse(T a, T m)
{
	T x, y;
	assert(gcd(a, m, x, y) == 1); // Or return something, if gcd is not 1 the inverse doesn't exist.
	return (x % m + m) % m;
}

#define MAXN 1123456

const ll mod = 1e9+7;

ll fat[MAXN];

ll choose(ll n, ll k)
{
	return (fat[n] * mod_inverse((fat[n-k]*fat[k]) % mod, mod)) % mod;
}

int a, b;

bool good(ll x)
{
	while (x)
	{
		if (x % 10 != a && x % 10 != b)
			return false;

		x /= 10;
	}

	return true;
}

int main(void)
{
	ll n;
	cin >> a >> b >> n;

	fat[0] = 1;
	for (int i = 1; i <= n; i++)
		fat[i] = (fat[i-1] * i) % mod;

	ll ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ll sum = a*i + b*(n-i);
		if (good(sum))
			ans = (ans + choose(n, i)) % mod;
	}

	cout << ans << endl;
}
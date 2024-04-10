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

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())

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
	String hashing:
		Get polynomial hash for any substring in O(1) after O(n) preprocessing.
	
	Usage:
		Good values c = 137, mod = 10^9 + 7.
		If necessary to check too many pairs of hashes, use two different hashes.

		If hashing something other than english characters:
			- Don't have elements with value 0.
			- Use c > max element value.
*/

struct hash_interval
{
	ll c, mod;
	vector<ll> h, p;
	hash_interval(string s, ll c, ll mod) : c(c), mod(mod), h(sz(s) + 1), p(sz(s) + 1)
	{
		p[0] = 1;
		h[0] = 0;
		for (int i = 0; i < sz(s); i++)
		{
			h[i + 1] = (c * h[i] + s[i]) % mod;
			p[i + 1] = (c * p[i]) % mod;
		}
	}

	// Returns hash of interval s[a ... b] (where 0 <= a <= b < sz(s)).
	ll get(int a, int b)
	{
		return (h[b + 1] - ((h[a] * p[b - a + 1]) % mod) + mod) % mod;
	}
};

char tmp[5123456];

int main(void)
{
	string s;
	scanf("%s", tmp);
	s = tmp;
	int n = sz(s);
	vector<int> tab(n+1);
	hash_interval hash(s, 137, 1000000007);
	reverse(s.begin(), s.end());
	hash_interval rev_hash(s, 137, 1000000007);
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (hash.get(0, (i-1)/2) == rev_hash.get(n - i, n - (i+2)/2))
			tab[i] = tab[i/2] + 1;
		else
			tab[i] = 0;

		ans += tab[i];
	}

	cout << ans << endl;
}
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

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	ll total = 0;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		total += a[i];
	}
	
	ll x = total;
	vector<ll> fats;
	for (ll i = 2; i*i <= x; i++)
	{
		if (x % i == 0)
			fats.push_back(i);

		while (x % i == 0)
			x /= i;
	}

	if (x != 1)
		fats.push_back(x);
	
	ll ans = infll;
	for (ll k : fats)
	{
		ll cnt = 0;
		ll tmp = 0;
		for (int i = 0; i < n; i++)
		{
			tmp += a[i];
			tmp %= k;
			if (tmp > k/2)
				tmp = -(k-tmp);
			
			cnt += abs(tmp);
		}

		assert(tmp == 0);
		ans = min(ans, cnt);
	}

	cout << (ans == infll ? -1 : ans) << endl;
}
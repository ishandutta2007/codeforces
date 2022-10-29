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

#define MAXN 112345

int n;
int a[MAXN];
ll pref[MAXN];

ll foo(int diff)
{
	ll retv = infll;

	int l = 1, r = 1;
	for (int i = 1; i <= n; i++)
	{
		while (a[l] < a[i] - diff)
			l++;
		while (r < n && a[r + 1] <= a[i] + diff)
			r++;
		
		retv = min(retv, (l-1) * 1ll * (a[i] - diff) - pref[l - 1] + (pref[n] - pref[i]) - (n - i) * 1ll * (a[i]));
		retv = min(retv, (pref[n] - pref[r]) - (n - r) * 1ll * (a[i] + diff) + (i-1) * 1ll * (a[i]) - pref[i - 1]);
	}

	return retv;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++)
		pref[i] = pref[i-1] + a[i];

	int bot = 0, top = a[n] - a[1];

	while (bot < top)
	{
		int mid = (bot + top) / 2;
		if (foo(mid) > k)
		{
			bot = mid + 1;
		}
		else
		{
			top = mid;
		}
	}

	cout << bot << endl;
}
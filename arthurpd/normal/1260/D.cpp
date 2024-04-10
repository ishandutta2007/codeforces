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

#define MAXN 212345

int m, n, k, t;
int a[MAXN], l[MAXN], r[MAXN], d[MAXN];

int foo(int s)
{
	if (s == 0)
		return n + 1;
	
	vector<int> trap(n + 1, 0);
	for (int i = 0; i < k; i++)
		if (d[i] > a[m - s])
		{
			// debug(l[i], r[i]);
			trap[l[i] - 1]++;
			trap[r[i]]--;
		}

	int ans = n + 1;
	for (int i = 0; i < n + 1; i++)
	{
		if (i > 0)
			trap[i] += trap[i-1];
		// debug(i, trap[i]);

		if (trap[i] > 0)
			ans += 2;
	}

	return ans;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> k >> t;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	
	sort(a, a + m);

	for (int i = 0; i < k; i++)
		cin >> l[i] >> r[i] >> d[i];

	int bot = 0, top = m;
	while (bot < top)
	{
		int mid = (bot + top + 1) / 2;
		if (foo(mid) <= t)
		{
			bot = mid;
		}
		else
		{
			top = mid - 1;
		}
		
	}

	// cout << foo(bot) << endl;
	cout << bot << endl;
}
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

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	ll k;
	cin >> n >> k;

	vector<int> p(n);
	vector<int> q(n);
	iota(p.begin(), p.end(), 1);
	iota(q.begin(), q.end(), 1);

	for (int i = 0; i < n; i++)
		k -= p[i];
	
	if (k < 0)
	{
		cout << -1 << endl;
		return 0;
	}

	bool not_maxed = false;
	for (int i = 0; i < n - i - 1; i++)
	{
		if (k >= q[n - i - 1] - q[i])
		{
			k -= q[n - i - 1] - q[i];
			swap(q[n - i - 1], q[i]);
		}
		else
		{
			not_maxed = true;
		}		
	}

	if (k == 1 && not_maxed)
	{
		for (int i = 0; i < n - i - 1; i++)
			if (q[i] <= n / 2)
			{
				swap(q[i], q[i + 1]);
				break;
			}
		
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += max(p[i], q[i]);

	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << p[i] << " ";

	cout << endl;
	for (int i = 0; i < n; i++)
		cout << q[i] << " ";
	cout << endl;

}
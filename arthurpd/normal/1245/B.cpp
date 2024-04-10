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
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, n;
		cin >> n >> a >> b >> c;
		string s;
		cin >> s;
		map<char, vector<int>> pos;
		for (int i = 0; i < n; i++)
			pos[s[i]].push_back(i);

		vector<char> ans(n);
		while (a > 0 && pos['S'].size() > 0)
		{
			ans[pos['S'].back()] = 'R';
			pos['S'].pop_back();
			a--;
		}

		while (b > 0 && pos['R'].size() > 0)
		{
			ans[pos['R'].back()] = 'P';
			pos['R'].pop_back();
			b--;
		}

		while (c > 0 && pos['P'].size() > 0)
		{
			ans[pos['P'].back()] = 'S';
			pos['P'].pop_back();
			c--;
		}

		for (int i = 0; i < n; i++)
			if (ans[i] == 0)
			{
				if (a > 0)
				{
					ans[i] = 'R';
					a--;
				}
				else if (b > 0)
				{
					ans[i] = 'P';
					b--;
				}
				else
				{
					ans[i] = 'S';
					c--;
				}
			}

		int nwin = 0;
		for (int i = 0; i < n; i++)
			if ((ans[i] == 'R' && s[i] == 'S') || (ans[i] == 'P' && s[i] == 'R') || (ans[i] == 'S' && s[i] == 'P'))
				nwin++;

		if (2 * nwin >= n)
		{
			cout << "yes" << endl;
			for (char c : ans)
				cout << c;
			cout << endl;
		}
		else
		{
			cout << "no" << endl;
		}
		
	}
}
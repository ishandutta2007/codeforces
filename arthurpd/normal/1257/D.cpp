// https://codeforces.com/contest/1257/problem/D

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
	Range Min(Max) Query
		Maximum of range in vector with O(n log n) preprocessing
		and O(1) query.
	
	Usage:
		Create passing vector.
		Call query with 0 <= a <= b <= n-1.

	Author: Arthur Pratti Dadalto
*/

template <class T>
struct rmq
{
	vector<vector<T>> jmp;
	rmq(const vector<T> &v)
	{
		int n = sz(v);
		int lgn = 31 - __builtin_clz(n + 1);
		jmp.assign(lgn + 1, vector<int>(n, 0));
		jmp[0] = v;
		for (int i = 1; i <= lgn; i++)
			for (int j = 0; j < n; j++)
				jmp[i][j] = max(jmp[i - 1][j], jmp[i - 1][min(n - 1, j + (1 << (i - 1)))]);
	}

	T query(int a, int b)
	{
		int k = 31 - __builtin_clz(b - a + 1);
		return max(jmp[k][a], jmp[k][b - (1 << k) + 1]);
	}
};

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		cin >> m;
		vector<pii> h(m);
		for (int i = 0; i < m; i++)
			cin >> h[i].first >> h[i].second;

		sort(h.begin(), h.end());
		vector<pii> heros;
		for (int i = 0; i < m; i++)
		{
			while (heros.size() > 0 && h[i].second >= heros.back().second)
				heros.pop_back();

			heros.push_back(h[i]);
		}

		rmq<int> rm(a);

		int ans = 0;
		int cur = 0;
		while (cur != n)
		{
			int bot = 0, top = sz(heros) - 1;
			while (bot < top)
			{
				int mid = (bot + top + 1) / 2;
				if (rm.query(cur, min(n - 1, cur + heros[mid].second - 1)) > heros[mid].first)
					bot = mid;
				else
					top = mid - 1;
			}

			set<int> candidates = {bot, min(bot + 1, sz(heros) - 1)};
			int mx = 0;
			for (int cand : candidates)
			{
				int i;
				for (i = 0; cur + i < n && i < heros[cand].second && heros[cand].first >= a[cur + i]; i++)
					;
				mx = max(mx, i);
			}

			// debug(candidates);
			// debug(mx);

			if (mx == 0)
			{
				ans = -1;
				break;
			}
			else
			{
				ans++;
				cur += mx;
			}
		}

		cout << ans << endl;
	}
}
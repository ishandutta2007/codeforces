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
	vi a(n);
	for (int i = 0; i < n; a[i]--, i++)
		cin >> a[i];
	
	vector<vi> s(2, vi(n + 1, 0)), first(2, vi(2 * (n + 1), inf));
	for (int i = 0; i < n; i++)
		for (int k = 0; k < 2; k++)
		{
			s[k][i + 1] = s[k][i] + (a[i] == k);
			if (first[k][s[k][i + 1]] == inf)
				first[k][s[k][i + 1]] = i + 1;
		}
	
	vector<pair<int,int>> ans;
	for (int t = 1; t <= n; t++)
	{
		int cur = 0;
		int sets[2] = {0, 0};
		int last = 0;
		while (first[0][s[0][cur] + t] != inf || first[1][s[1][cur] + t] != inf)
		{
			if (first[0][s[0][cur] + t] < first[1][s[1][cur] + t])
				sets[last = 0]++;
			else
				sets[last = 1]++;
			
			cur = min(first[0][s[0][cur] + t], first[1][s[1][cur] + t]);
		}
		
		if (cur == n && sets[last] > sets[last ^ 1])
			ans.push_back({sets[last], t});
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (pii v : ans)
		cout << v.first << " " << v.second << "\n";
}
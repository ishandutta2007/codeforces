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

ll cost(int med, vector<pii> e, int n)
{
	vector<int> sol;
	vector<pii> tmp;
	for (int i = 0; i < n; i++)
		if (e[i].first > med)
		{
			sol.push_back(e[i].first);
		}
		else
		{
			tmp.push_back(e[i]);
		}

	e = tmp;

	sort(e.begin(), e.end(), [](pii lhs, pii rhs) { return lhs.first > rhs.first; });

	tmp.clear();
	for (int i = 0; i < sz(e); i++)
		if (e[i].second >= med && sz(sol) <= n/2)
		{
			sol.push_back(med);
		}
		else
		{
			tmp.push_back(e[i]);
		}
	
	e = tmp;
	for (int i = 0; i < sz(e); i++)
		sol.push_back(e[i].first);

	ll retv = 0;
	for (int i = 0; i < n; i++)
		retv += sol[i];

	return retv;
}


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		ll s;
		cin >> n >> s;
		vector<pii> e(n);
		for (int i = 0; i < n; i++)
			cin >> e[i].first >> e[i].second;

		sort(e.begin(), e.end());
		int bot = e[n/2].first;

		sort(e.begin(), e.end(), [](pii lhs, pii rhs) { return lhs.second < rhs.second; });

		int top = e[n/2].second;
		while (top > bot)
		{
			int mid = (bot + top + 1) / 2;
			if (cost(mid, e, n) > s)
				top = mid - 1;
			else
			{
				bot = mid;
			}
		}

		cout << bot << endl;
	}
}
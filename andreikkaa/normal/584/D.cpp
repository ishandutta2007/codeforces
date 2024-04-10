/* ______ INCLUDES ______ */

#include <bits/stdc++.h>

/* _____ NAMESPACES _____ */

using namespace std;

/* ______ TEMPLATE ______ */

typedef long long ll;
typedef long double ld;

inline void _redirect_streams(const string input = "", const string output = "")
{
	if(not input.empty())
		assert(freopen(input.c_str(), "r", stdin) != nullptr);

	if(not output.empty())
		assert(freopen(output.c_str(), "w", stdout) != nullptr);
}

inline void _speed_up_iostreams()
{
	//IMPORTANT NOTE: don't mix iostreams and stdio when next line is active
	ios_base::sync_with_stdio(false);

	cin.tie(nullptr);
}

inline void _pre()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("soldiers.in", "soldiers.out");
#endif //ANDREIKKAA

	_speed_up_iostreams();
}

inline void _post()
{
#ifdef ANDREIKKAA
	cerr.precision(10);
	cerr << "Execution time: " << clock() / (ld) CLOCKS_PER_SEC << endl;
#endif
}

/* ________ CODE ________ */

unordered_map<int, bool> is_pr;

bool pr(int n)
{
	if(is_pr.find(n) != is_pr.end())
	{
		return is_pr[n];
	}

	int s = (int) sqrt(n);

	is_pr[n] = false;

	for(int i = 2 ; i <= s; ++i)
	{
		if(n % i == 0)
		{
			return false;
		}
	}

	is_pr[n] = true;
	return true;
}

pair<bool, pair<int, int>> g(int n)
{
	for(int i = 2; i <= n; ++i)
	{
		if(pr(i) and pr(n - i))
		{
			return {true, {i, n - i}};
		}
	}

	return {false, {-1, -1}};
}

void _solve()
{
	int n;
	cin >> n;

	if(pr(n))
	{
		cout << 1 << endl << n << endl;
		return;
	}

	const int TL = 1000;

	for(int i = n - 1; i > max(1, n - TL - 1); --i)
	{
		if(pr(i) and pr(n - i))
		{
			cout << 2 << endl << i << " " << n - i << endl;
			return;
		}

		auto res = g(n - i);

		if(pr(i) and res.first)
		{
			cout << 3 << endl << i << " " << res.second.first << " " << res.second.second << endl;
			return;
		}
	}

	assert(false);
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}
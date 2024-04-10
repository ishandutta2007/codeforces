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


void _solve()
{
	const int MOD = 1000 * 1000 * 1000 + 7;

	int n;
	cin >> n;

	ll r1 = 1, r2 = 1;

	for(int i = 0; i < 3 * n; ++i)
	{
		r1 *= 3;
		r1 %= MOD;
	}

	for(int i = 0; i < n; ++i)
	{
		r2 *= 7;
		r2 %= MOD;
	}

	cout << (r1 - r2 + MOD) % MOD << endl;
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}
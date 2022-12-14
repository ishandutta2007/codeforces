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

ll k;

ll f(ll x, ll y)
{
	if(x > y)
		return 0;

	return y / k - (x - 1) / k;
}

void _solve()
{
	ll a, b;
	cin >> k >> a >> b;

	if(b < 0)
	{
		cout << f(-b, -a) << endl;
	}
	else if(a < 0)
	{
		cout << f(1, -a) + f(1, b) + 1 << endl;
	}
	else
	{
		cout << f(max(a, 1ll), b) + (a == 0) << endl;
	}
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}
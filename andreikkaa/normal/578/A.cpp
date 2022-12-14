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
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	_speed_up_iostreams();
}

inline void _post()
{
#ifdef ANDREIKKAA
	cerr.precision(10);
	cerr << "Execution time: " << clock() / (ld)CLOCKS_PER_SEC << endl;
#endif
}

/* ________ CODE ________ */

const ll INF = 1000ll * 1000 * 1000 * 1000;

inline void _solve()
{
	ll a, b;
	cin >> a >> b;

	if(b > a)
	{
		cout << -1 << endl;
		return;
	}

	ll c = a + b;

	ll l = 1, r = c + 1;

	while(l != r)
	{
		ll m = (l + r) / 2;

		if(c / (ld) m / 2 >= b)
		{
			l = m + 1;
		}
		else
		{
			r = m;
		}
	}

	cout << setprecision(30) << fixed << c / (ld)(l - 1) / 2 << endl;
}

int main()
{
	_pre();

	_solve();

	_post();
	
	return 0;
}
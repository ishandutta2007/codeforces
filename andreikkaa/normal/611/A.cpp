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
	//_redirect_streams("robot.in", "robot.out");
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
	int n;
	cin >> n;
	string s;
	getline(cin, s);

	if(s.back() == 'k')
	{
		if(n == 5 or n == 6)
		{
			cout << 53 << endl;
		}
		else
		{
			cout << 52 << endl;
		}
	}
	else
	{
		if(n == 31)
		{
			cout << 7 << endl;
		}
		else if(n == 30)
		{
			cout << 11 << endl;
		}
		else
		{
			cout << 12 << endl;
		}
	}
}

int main()
{
	_pre();

	_solve();

	_post();
}
//Created in CLion IDE, Ubuntu OS.

/**
	inline void print_hello()
	{
		string message = R"(
		Hello!

		My name is Andrey E. Kalendarov,
		And I'm waiting for OK (or AC) status.

		Yes, please, don't blame my code.
		I know that it's far from ideal.
		But it shoulong double pass all the tests.

		And everybody will be happy.
		And you, my dear reader, too.
		I'm sure.

		Goodbye.
		)";

		cout << message << endl;
	}
**/

/* ______ INCLUDES ______ */

#include <bits/stdc++.h>

/* _____ NAMESPACES _____ */

using namespace std;

/* ______ TEMPLATE ______ */

typedef long long ll;
//typedef long long double long double;

inline void _redirect_streams(const string input="", const string output="")
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

inline void _prepare()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	_speed_up_iostreams();
}

/* ________ CODE ________ */

long double a, b, c, d;

inline pair<long double, long double> prod(pair<long double, long double> a, pair<long double, long double> b)
{
	vector<long double> v = {a.first * b.first, a.first * b.second, a.second * b.first, a.second * b.second};

	return {*min_element(v.begin(), v.end()), *max_element(v.begin(), v.end())};
}

inline bool f(long double m)
{
	pair<long double, long double> p1 = prod({a - m, a + m}, {d - m, d + m});
	pair<long double, long double> p2 = prod({b - m, b + m}, {c - m, c + m});

	if(p1.first <= p2.first and p2.first <= p1.second)
		return true;

	if(p1.first <= p2.second and p2.second <= p1.second)
		return true;

	if(p2.first <= p1.first and p1.first <= p2.second)
		return true;

	return p2.first <= p1.second and p1.second <= p2.second;

}

int main()
{
	_prepare();

	cin >> a >> b >> c >> d;

	long double l = 0, r = 1e18;

	const long double EPS = 1e-10;

	cout.precision(20);

	while(r - l > EPS)
	{
		long double m = (l + r) / 2;

		if(f(m))
			r = m;
		else
			l = m;
	}

	cout.precision(30);
	cout << l << endl;

	return 0;
}
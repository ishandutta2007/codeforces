/**
	inline void print_hello()
	{
		string message = R"(Hello!

		My name is Andrey E. Kalendarov,
		And I'm waiting for OK (or AC) status.

		Yes, please, don't blame my code.
		I know that it's far from ideal.
		But it should pass all the tests.

		And everybody will be happy.
		And you, my dear reader, too.
		I'm sure.

		Goodbye.)";

		cout << message << endl;
	}
**/

/* _____ INCLUDES _____ */

#include <bits/stdc++.h>

/* _____ NAMESPACES _____ */

using namespace std;

/* ______ TEMPLATE ______ */

typedef long long ll;
typedef long double ld;

inline void _redirect_streams(const string input="", const string output="")
{
	if(not input.empty())
		assert(freopen(input.c_str(), "r", stdin) != nullptr);

	if(not output.empty())
		assert(freopen(output.c_str(), "w", stdout) != nullptr);
}

template<class T> T gcd(T _a, T _b)
{
	return __gcd(_a, _b);
}

ll lcm(ll _a, ll _b)
{
	return _a / gcd(_a, _b) * _b;
}

template<class T> T binpow(T _a, ll _b, ll _mod=(1 << (8 * sizeof(T) - 1)) - 1)
{
	if(_b == 0)
	{
		return 1;
	}

	if(_b % 2 == 0)
	{
		T _c = binpow(_a, _b / 2, _mod);
		return (_c * _c) % _mod;
	}
	else
	{
		return (_a * binpow(_a, _b - 1, _mod)) % _mod;
	}
}

ll division(ll _a, ll _b, ll _mod=1000000009ll)
{
	_b = binpow(_b, _mod - 2, _mod);

	return (_a * _b) % _mod;
}

/* ________ CODE ________ */

bool a[1002][1002];

inline bool f(int x, int y)
{
	return a[x][y] and a[x + 1][y] and a[x + 1][y + 1] and a[x][y + 1];
}

int main()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("rps.in", "rps.out");
#endif //ANDREIKKAA

	int n, m, k;
	cin >> n >> m >> k;

	for(int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y;

		a[x][y] = true;

		if(f(x, y) or f(x - 1, y) or f(x, y - 1) or f(x - 1, y - 1))
		{
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout << 0 << endl;

    return 0;
}
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

template<class T> T gcd(T a, T b)
{
	return __gcd(a, b);
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

template<class T> T binpow(T a, ll b, ll mod=(1 << (8 * sizeof(T) - 1)) - 1)
{
	if(b == 0)
	{
		return 1;
	}

	if(b % 2 == 0)
	{
		T c = binpow(a, b / 2, mod);
		return (c * c) % mod;
	}
	else
	{
		return (a * binpow(a, b - 1, mod)) % mod;
	}
}

ll division(ll a, ll b, ll mod=1000000009ll)
{
	b = binpow(b, mod - 2, mod);

	return (a * b) % mod;
}

/* ________ CODE ________ */

int main()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	int n;
	cin >> n;

	int x[(int)1e5 + 2];
	int h[(int)1e5 + 2];

	x[0] = -2e9 - 1;

	for(int i = 1; i <= n; ++i)
		cin >> x[i] >> h[i];

	x[n + 1] = 2e9 + 1;

	int ans = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(x[i] - h[i] > x[i - 1])
			++ans;
		else if(x[i] + h[i] < x[i + 1])
		{
			++ans;
			x[i] += h[i];
		}
	}

	cout << ans << endl;

    return 0;
}
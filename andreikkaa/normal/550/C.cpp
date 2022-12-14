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

void f(string s, string t, string u)
{
	auto pos = s.find(t);

	if(pos == string::npos)
		return;

	pos = s.find(u, pos + 2);

	if(pos == string::npos)
		return;

	cout << "YES" << endl;
	exit(0);
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	string s;
	cin >> s;

	int a[100];

	int n = s.size();

	for(int i = 0; i < n; ++i)
	{
		a[i] = s[i] - '0';
	}

	for(int i = 0; i < n; ++i)
	{
		if(a[i] % 8 == 0)
		{
			cout << "YES" << endl;
			cout << a[i] << endl;
			return 0;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			if((a[i] * 10 + a[j]) % 8 == 0)
			{
				cout << "YES" << endl;
				cout << a[i] << a[j] << endl;
				return 0;
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			for(int k = j + 1; k < n; ++k)
			{
				if((a[i] * 100 + a[j] * 10 + a[k]) % 8 == 0)
				{
					cout << "YES" << endl;
					cout << a[i] << a[j] << a[k] << endl;
					return 0;
				}
			}
		}
	}

	cout << "NO" << endl;


    return 0;
}
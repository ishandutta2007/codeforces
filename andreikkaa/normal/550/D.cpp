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

int k;
vector<pair<int, int>> v;

void f(const int c)
{
	for(int i = 2; i <= k; ++i)
		v.push_back({c + 1, c + i});

	for(int i = 2; i <= k; ++i)
	{
		for(int j = k + 1; j < 2 * k; ++j)
		{
			v.push_back({c + i, c + j});
		}
	}

	for(int i = k + 1; i < 2 * k; i += 2)
	{
		v.push_back({c + i, c + i + 1});
	}
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

	cin >> k;

	if(k % 2 == 0)
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	int n = 2 * (1 + 2 * (k - 1));

	f(0);
	f(1 + 2 * (k - 1));

	cout << n << " " << v.size() + 1 << endl;

	for(auto i : v)
		cout << i.first << " " << i.second << "\n";

	cout << 1 << " " << 1 + 2 * (k - 1) + 1 << endl;

    return 0;
}
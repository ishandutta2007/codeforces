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

int m;

vector<ll> solve(ll s, ll f, ll x, ll y)
{
	vector<ll> ans;

	int used[1000000];
	memset(used, 0, sizeof used);

	for(ll i = 0; used[s] <= 1; ++i)
	{
		if(s == f)
		{
			ans.push_back(i);

			if(ans.size() > 1)
				break;
		}
		++used[s];
		s = (s * x + y) % m;
	}

	return ans;
}

int main()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	cin >> m;

	int s, f, x, y;

	cin >> s >> f >> x >> y;
	auto v1 = solve(s, f, x, y);

	cin >> s >> f >> x >> y;
	auto v2 = solve(s, f, x, y);

    if(v1.size() > v2.size())
		swap(v1, v2);

	if(v1.empty())
	{
		cout << -1 << endl;
	}
	else if(v1.size() == 1)
	{
		if(v2.size() == 1)
		{
			if(v1.front() == v2.front())
			{
				cout << v1.front() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else
		{
			ll x1 = v1.front(), x2 = v2.front(), y2 = v2.back() - x2;

			if(x1 >= x2 and (x1 - x2) % y2 == 0)
				cout << x1 << endl;
			else
				cout << -1 << endl;
		}
	}
	else
	{
		ll x1 = v1.front(), x2 = v2.front(), y1 = v1.back() - x1, y2 = v2.back() - x2;

		const int TL = 1e7;

		for(int k = 0; k < TL; ++k)
		{
			ll cur = x1 + y1 * k;

			if(cur >= x2 and (cur - x2) % y2 == 0)
			{
				cout << cur << endl;
				return 0;
			}
		}

		cout << -1 << endl;
	}


    return 0;
}
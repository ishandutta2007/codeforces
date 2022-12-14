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

inline void _redirect_streams(const string input = "", const string output = "")
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

template<class T> T binpow(T a, ll b, ll mod = (1 << (8 * sizeof(T) - 1)) - 1)
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

ll division(ll a, ll b, ll mod = 1000000009ll)
{
	b = binpow(b, mod - 2, mod);

	return (a * b) % mod;
}

/* ________ CODE ________ */

const int MAX = 5e6;
long long lp[MAX + 1];

int main()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	vector<int> pr;

	lp[1] = 0;

	for (int i = 2; i <= MAX; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			pr.push_back (i);
		}

		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAX; ++j)
			lp[i * pr[j]] = pr[j];
	}

	for(int i = 2; i <= MAX; ++i)
	{
		lp[i] = lp[i / lp[i]] + 1;
	}

	for(int i = 2; i <= MAX; ++i)
	{
		lp[i] += lp[i - 1];
	}

	int t;
	cin >> t;

	for(int i = 0; i < t; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lp[a] - lp[b]);
	}

	return 0;
}
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

	int n, l, r, x;
	cin >> n >> l >> r >> x;

	int a[15];

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	int ans = 0;

	for(int i = 0; i < (1 << n); ++i)
	{
		if(__builtin_popcount(i) < 2)
			continue;

		int sum = 0, minn = 1e6 + 1, maxx = -1;

		for(int j = 0; j < n; ++j)
		{
			if((i >> j) & 1)
			{
				sum += a[j];
				minn = min(minn, a[j]);
				maxx = max(maxx, a[j]);
			}
		}

		if(l <= sum and sum <= r and maxx - minn >= x)
			++ans;
	}

	cout << ans << endl;


    return 0;
}
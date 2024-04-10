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

vector<int> dp(vector<int> a)
{
	int n = a.size();

	vector<int> prev(n);

	stack<pair<int, int>> s;

	for(int i = 0; i < n; ++i)
	{
		while(not s.empty() and s.top().first > a[i])
		{
			s.pop();
		}

		if(not s.empty() and s.top().first == a[i])
		{
			prev[i] = prev[s.top().second];
			s.top().second = i;
		}
		else
		{
			if(not s.empty())
				prev[i] = s.top().second;
			else
				prev[i] = 0;

			s.push({a[i], i});
		}
	}

	return prev;
}

int main()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	int n;
	cin >> n;

	vector<int> a(n + 2);
	vector<int> ans(n + 2);

	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	auto prev = dp(a);

	reverse(a.begin(), a.end());

	auto next = dp(a);

	reverse(next.begin(), next.end());
	reverse(a.begin(), a.end());

	for(auto& i : next)
		i = n - i + 1;

	for(int i = 1; i <= n; ++i)
	{
		ans[i - prev[i] + next[i] - i - 1] = max(ans[i - prev[i] + next[i] - i - 1], a[i]);
	}

	for(int i = n - 1; i >= 0; --i)
	{
		ans[i] = max(ans[i + 1], ans[i]);
	}

	/*for(int i = 1; i <= n; ++i)
	{
		cout << prev[i] << " ";
	}
	cout << endl;

	for(int i = 1; i <= n; ++i)
	{
		cout << next[i] << " ";
	}
	cout << endl;*/

	for(int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << endl;

    return 0;
}
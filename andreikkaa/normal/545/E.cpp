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

vector<pair<int, pair<int, int>>> g[(int) 3e5 + 1];
bool used[(int) 3e5 + 1];
ll dist[(int) 3e5 + 1];

int main()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({b, {c, i + 1}});
		g[b].push_back({a, {c, i + 1}});
	}

	int u;
	cin >> u;

	multiset<pair<pair<ll, int>, pair<int, int>>> act;
	act.insert({{0ll, 0}, {u, -1}});

	vector<int> ans;
	ll w = 0;

	for(int i = 0; i < n; ++i)
	{
		while(used[act.begin()->second.first])
		{
			act.erase(act.begin());
		}

		auto p = *act.begin();
		act.erase(act.begin());

		ll cost = p.first.first;
		ll cedg = p.first.second;
		int ver = p.second.first;
		int edg = p.second.second;

		used[ver] = true;
		ans.push_back(edg);
		w += cedg;
		dist[ver] = cost;

		for(auto j : g[ver])
		{
			act.insert({{cost + j.second.first, j.second.first}, {j.first, j.second.second}});
		}
	}

	cout << w << endl;

	for(int i : ans)
		if(i != -1)
			printf("%d ", i);
	cout << endl;

    return 0;
}
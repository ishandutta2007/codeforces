/* ______ INCLUDES ______ */

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

inline void _speed_up_iostreams()
{
	//IMPORTANT NOTE: don't mix iostreams and stdio when next line is active
	ios_base::sync_with_stdio(false);

	cin.tie(nullptr);
}

inline void _pre()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	_speed_up_iostreams();
}

inline void _post()
{
#ifdef ANDREIKKAA
	cerr.precision(10);
	cerr << "Execution time: " << clock() / (ld)CLOCKS_PER_SEC << endl;
#endif
}

/* ________ CODE ________ */

ll power(ll a, ll b)
{
	const ll MOD = 1000 * 1000 * 1000 + 7;
	ll res = 1;
	for(int i = 0; i < b; ++i)
	{
		res = (res * a) % MOD;
	}

	return res;
}

inline void _solve()
{
	const int MAX_N = 1000 * 1000 + 228;
	static ll n[MAX_N];
	static bool used[MAX_N];

	ll p, k;
	cin >> p >> k;

	if(k == 0)
	{
		cout << power(p, p - 1) << endl;
		return;
	}
	else if(k == 1)
	{
		cout << power(p, p) << endl;
		return;
	}

	for(int i = 0; i < p; ++i)
	{
		n[i] = (i * k) % p;
	}

	int cnt = 0;
	for(int i = 0; i < p; ++i)
	{
		if(used[i])
		{
			continue;
		}
		++cnt;
		int j = i;
		while(not used[j])
		{
			used[j] = true;
			j = (int) n[j];
		}
	}

	cout << power(p, cnt - 1) << endl;
}

int main()
{
	_pre();

	_solve();

	_post();
	
	return 0;
}
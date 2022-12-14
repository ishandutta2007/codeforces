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

inline void _solve()
{
	const int MAX_N = 502;
	const int INF = 1000 * 1000;
	static int a[MAX_N];
	static int dp[MAX_N][MAX_N];

	int n;
	cin >> n;

	for(int i = 0; i <= n + 1; ++i)
	{
		for(int j = 0; j <= n + 1; ++j)
		{
			dp[i][j] = INF;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		dp[i][i] = 1;
	}

	for(int i = 1; i + 1 <= n; ++i)
	{
		if(a[i] == a[i + 1])
		{
			dp[i][i + 1] = 1;
		}
		else
		{
			dp[i][i + 1] = 2;
		}
	}

	for(int len = 3; len <= n; ++len)
	{
		for(int l = 1; l + len - 1 <= n; ++l)
		{
			int r = l + len - 1;

			for(int m = l; m < r; ++m)
			{
				dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
			}

			if(a[l] == a[r])
			{
				dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
			}
		}
	}

	cout << dp[1][n] << endl;
}

int main()
{
	_pre();

	_solve();

	_post();
	
	return 0;
}
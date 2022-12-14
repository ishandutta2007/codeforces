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
	//_redirect_streams("soldiers.in", "soldiers.out");
#endif //ANDREIKKAA

	_speed_up_iostreams();
}

inline void _post()
{
#ifdef ANDREIKKAA
	cerr.precision(10);
	cerr << "Execution time: " << clock() / (ld) CLOCKS_PER_SEC << endl;
#endif
}

/* ________ CODE ________ */

void _solve()
{
	const int MAX_N = 52;

	static int a[MAX_N];
	static int b[MAX_N];
	static int c[MAX_N];

	int n;
	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		cin >> a[i];
	}

	partial_sum(a, a + n + 1, a);

	for(int i = 1; i < n; ++i)
	{
		cin >> c[i];
	}

	reverse(c, c + n + 1);
	partial_sum(c, c + n + 1, c);
	reverse(c, c + n + 1);

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}

	int ans = 1000 * 1000 * 1000;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(i == j)
			{
				continue;
			}

			ans = min(ans, a[i - 1] + b[i] + c[i] + a[j - 1] + b[j] + c[j]);
		}
	}

	cout << ans << endl;
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}
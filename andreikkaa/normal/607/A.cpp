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
	const int INF = 1000 * 1000 * 1000;
	const int MAX_N = 100 * 1000 + 228;
	static pair<int, int> kek[MAX_N];
	static int a[MAX_N];
	static int b[MAX_N];
	static int dp[MAX_N];

	int n;
	cin >> n;

	kek[0].first = -INF;
	for(int i = 1; i <= n; ++i)
	{
		cin >> kek[i].first >> kek[i].second;
		//cin >> a[i] >> b[i];
	}

	sort(kek, kek + n + 1);
	for(int i = 0; i <= n; ++i)
	{
		a[i] = kek[i].first;
		b[i] = kek[i].second;
	}

	for(int i = 1; i <= n; ++i)
	{
		int f = (int) (lower_bound(a, a + i, a[i] - b[i]) - a - 1);
		dp[i] = dp[f] + (i - f - 1);
		//cout << i << " " << dp[i] << endl;
	}

	int ans = INF;
	for(int i = 1; i <= n + 1; ++i)
	{
		//cout << i << " " << n - i + 1 << endl;
		ans = min(ans, n - i + 1 + dp[i - 1]);
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
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
	cerr << "Execution time: " << clock() / (ld) CLOCKS_PER_SEC << endl;
#endif
}

/* ________ CODE ________ */

void _solve()
{
	const int MAX_N = 1000 + 1;
	const int INF = 1000 * 1000;
	static int a[MAX_N];

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int cnt = 0, ans = 0;

	while(cnt < n)
	{
		for(int i = 0; i < n; ++i)
		{
			if(a[i] <= cnt)
			{
				a[i] = INF;
				++cnt;
			}
		}

		if(cnt == n)
		{
			break;
		}
		++ans;

		for(int i = n - 1; i >= 0; --i)
		{
			if(a[i] <= cnt)
			{
				a[i] = INF;
				++cnt;
			}
		}

		if(cnt == n)
		{
			break;
		}
		++ans;
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
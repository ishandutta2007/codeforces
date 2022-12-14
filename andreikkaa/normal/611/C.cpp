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
	//_redirect_streams("robot.in", "robot.out");
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
	const int MAX_S = 500 + 14;
	static char a[MAX_S][MAX_S];
	static int dpld[MAX_S][MAX_S];
	static int dpl[MAX_S][MAX_S];
	static int dpd[MAX_S][MAX_S];

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			dpl[i][j] = dpl[i][j - 1];
			if(a[i][j] == '.' and a[i][j + 1] == '.')
			{
				++dpl[i][j];
				++dpld[i][j];
			}

			dpd[i][j] = dpd[i - 1][j];
			if(a[i][j] == '.' and a[i + 1][j] == '.')
			{
				++dpd[i][j];
				++dpld[i][j];
			}

			dpld[i][j] += dpld[i - 1][j] + dpld[i][j - 1] - dpld[i - 1][j - 1];
		}
	}

	int q;
	cin >> q;

	for(int i = 0; i < q; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1;
		--y1;
		--x2;
		--y2;

		int ans = dpld[x2][y2] - dpld[x2][y1] - dpld[x1][y2] + dpld[x1][y1];
		ans += dpl[x2 + 1][y2] - dpl[x2 + 1][y1];
		ans += dpd[x2][y2 + 1] - dpd[x1][y2 + 1];
		cout << ans << endl;
	}
}

int main()
{
	_pre();

	_solve();

	_post();
}
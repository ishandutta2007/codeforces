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
	const int MAX_N = 1000;
	static int a[MAX_N][MAX_N];
	static int p[MAX_N];

	int n;
	cin >> n;
	n *= 2;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			cin >> a[i][j];

			a[j][i] = a[i][j];
		}
	}

	for(int k = 0; k < n / 2; ++k)
	{
		int x = 0, y = 0;

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(a[i][j] > a[x][y])
				{
					x = i;
					y = j;
				}
			}
		}

		for(int i = 0; i < n; ++i)
		{
			a[i][y] = 0;
			a[y][i] = 0;
			a[x][i] = 0;
			a[i][x] = 0;
		}

		p[x] = y + 1;
		p[y] = x + 1;
	}

	for(int i = 0; i < n; ++i)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}
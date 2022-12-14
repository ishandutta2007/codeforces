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

string a[5];
int n, k;

bool f(int x)
{
	bool good[5][n];
	for(int i = 0; i < n; ++i)
	{
		good[1][i] = good[2][i] = good[3][i] = false;
		good[0][i] = good[4][i] = false;
	}

	good[x][0] = true;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 1; j <= 3; ++j)
		{
			if(not good[j][i])
			{
				continue;
			}

			if(i == n - 1)
			{
				return true;
			}

			if(isalpha(a[j][i + 1]))
			{
				continue;
			}

			if(i == n - 2 or i == n - 3)
			{
				return true;
			}

			if(not isalpha(a[j - 1][i + 1]) and not isalpha(a[j - 1][i + 3]))
			{
				good[j - 1][i + 3] = true;
			}

			if(not isalpha(a[j][i + 3]))
			{
				good[j][i + 3] = true;
			}

			if(not isalpha(a[j + 1][i + 1]) and not isalpha(a[j + 1][i + 3]))
			{
				good[j + 1][i + 3] = true;
			}
		}
	}

	return false;
}

void solve()
{
	cin >> n >> k;

	cin >> a[1] >> a[2] >> a[3];
	a[0] = a[4] = string(n, 'A');

	bool st = false;

	if(a[1][0] == 's')
	{
		st = f(1);
	}

	if(a[2][0] == 's')
	{
		st = f(2);
	}

	if(a[3][0] == 's')
	{
		st = f(3);
	}

	if(st)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

inline void _solve()
{
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i)
	{
		solve();
	}
}

int main()
{
	_pre();

	_solve();

	_post();
	
	return 0;
}
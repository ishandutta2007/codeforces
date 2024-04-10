//Created in CLion IDE, Ubuntu OS.

/**
	inline void print_hello()
	{
		string message = R"(
		Hello!

		My name is Andrey E. Kalendarov,
		And I'm waiting for OK (or AC) status.

		Yes, please, don't blame my code.
		I know that it's far from ideal.
		But it should pass all the tests.

		And everybody will be happy.
		And you, my dear reader, too.
		I'm sure.

		Goodbye.
		)";

		cout << message << endl;
	}
**/

/* ______ INCLUDES ______ */

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

inline void _speed_up_iostreams()
{
	//IMPORTANT NOTE: don't mix iostreams and stdio when next line is active
	ios_base::sync_with_stdio(false);

	cin.tie(nullptr);
}

inline void _prepare()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	_speed_up_iostreams();
}

/* ________ CODE ________ */

int main()
{
	_prepare();

	int n, m;
	cin >> n >> m;

	int a[n][m];
	bool c[n][m];

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			char t;
			cin >> t;
			c[i][j] = t == 'B';
			a[i][j] = 0;
		}

	int ans = 0;

	for(int i = n - 1; i >= 0; --i)
	{
		for(int j = m - 1; j >= 0; --j)
		{
			if(c[i][j])
			{
				const int diff = -1 - a[i][j];

				if(diff == 0)
				{
					continue;
				}

				++ans;

				for(int k = 0; k <= i; ++k)
				{
					for(int l = 0; l <= j; ++l)
					{
						a[k][l] += diff;
					}
				}
			}
			else
			{
				const int diff = 1 - a[i][j];

				if(diff == 0)
				{
					continue;
				}

				++ans;

				for(int k = 0; k <= i; ++k)
				{
					for(int l = 0; l <= j; ++l)
					{
						a[k][l] += diff;
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
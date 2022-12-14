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

char f(char c)
{
	if(c == '+')
		return '*';
	return '+';
}

void _solve()
{
	const int MAX_N = 1000;
	static char a[MAX_N][MAX_N];

	int k;
	cin >> k;

	a[0][0] = '+';

	for(int i = 0; i < k; ++i)
	{
		int n = (1 << i);
		for(int j = 0; j < n; ++j)
		{
			for(int l = 0; l < n; ++l)
			{
				a[j][l + n] = a[j][l];
				a[j + n][l] = a[j][l];
				a[j + n][l + n] = f(a[j][l]);
			}
		}
	}

	int n = (1 << k);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}

int main()
{
	_pre();

	_solve();

	_post();
}
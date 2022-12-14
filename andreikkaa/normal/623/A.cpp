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

inline void _solve()
{
	const int MAX_N = 502;
	static bool g[MAX_N][MAX_N];
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;

		g[a][b] = g[b][a] = 1;
	}

	string s(n, ' ');

	char c = 'a';

	for(int i = 0; i < n; ++i)
	{
		if(count(g[i], g[i] + n, 1) == n - 1)
		{
			s[i] = 'b';
		}
	}

	for(int i = 0; i < n; ++i)
	{
		if(s[i] == ' ')
		{
			if(c == 'd')
			{
				cout << "No" << endl;
				return;
			}
			s[i] = c;
			for(int j = 0; j < n; ++j)
			{
				if(g[i][j] and s[j] != 'b')
				{
					s[j] = c;
				}
			}
			if(c == 'c')
			{
				c = 'd';
			}
			else
			{
				c = 'c';
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			if(g[i][j])
			{
				if(max(s[i], s[j]) - min(s[i], s[j]) == 2)
				{
					cout << "No" << endl;
					return;
				}
			}
			else
			{
				if(max(s[i], s[j]) - min(s[i], s[j]) != 2)
				{
					cout << "No" << endl;
					return;
				}
			}
		}
	}

	cout << "Yes" << endl;
	cout << s << endl;
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}
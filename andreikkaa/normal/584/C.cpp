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
	int n, t;
	cin >> n >> t;

	string a, b;
	cin >> a >> b;

	int dif = 0, com = 0;

	for(int i = 0; i < n; ++i)
	{
		if(a[i] == b[i])
		{
			++com;
		}
	}

	dif = n - com;

	if(dif > 2 * t)
	{
		cout << -1 << endl;
		return;
	}

	int aa = t, bb = t;
	string c(n, '0');

	for(int i = 0; i < n; ++i)
	{
		if(a[i] != b[i])
		{
			--dif;

			if(aa > 0 and bb > 0)
			{
				--aa;
				--bb;

				for(char sym = 'a'; sym <= 'c'; ++sym)
				{
					if(a[i] != sym and b[i] != sym)
					{
						c[i] = sym;
						break;
					}
				}
			}
			else if(aa > 0)
			{
				--aa;
				c[i] = b[i];
			}
			else if(bb > 0)
			{
				--bb;
				c[i] = b[i];
			}
			else
			{
				--aa;
				c[i] = b[i];
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{
		if(a[i] == b[i])
		{
			if(aa > 0 and bb > 0)
			{
				--aa;
				--bb;

				if(a[i] == 'a')
				{
					c[i] = 'b';
				}
				else
				{
					c[i] = 'a';
				}
			}
			else
			{
				c[i] = a[i];
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{
		if(a[i] != b[i])
		{
			if(aa < 0)
			{
				++aa;

				if(c[i] == b[i])
				{
					--bb;
				}

				c[i] = a[i];
			}
			else if(bb < 0)
			{
				++bb;

				if(c[i] == a[i])
				{
					--aa;
				}

				c[i] = b[i];
			}
		}
	}

	if(aa == 0 and bb == 0)
	{
		cout << c << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}
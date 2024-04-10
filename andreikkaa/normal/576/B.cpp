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

const int MAX_N = 100 * 1000 + 1;
vector<int> c[MAX_N];
int cnt = 0;
bool used[MAX_N];
int p[MAX_N];
int n;

void go1(int x)
{
	cout << "YES" << endl;

	x = c[x][0];

	for(int i = 1; i <= n; ++i)
	{
		if(x == i)
		{
			continue;
		}

		cout << x << " " << i << endl;
	}
}

void go2(int x)
{
	cout << "YES" << endl;
	cout << c[x][0] << " " << c[x][1] << endl;

	for(int i = 0; i < cnt; ++i)
	{
		if(i == x)
		{
			continue;
		}

		for(int j = 0; j < c[i].size(); j += 2)
		{
			cout << c[x][0] << " " << c[i][j] << endl;
			cout << c[x][1] << " " << c[i][j + 1] << endl;
		}
	}
}

inline void _solve()
{
	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(used[i])
		{
			continue;
		}

		int x = i;
		while(not used[x])
		{
			used[x] = true;
			c[cnt].push_back(x);
			x = p[x];
		}

		++cnt;
	}

	for(int i = 0; i < cnt; ++i)
	{
		if(c[i].size() == 1)
		{
			go1(i);
			return;
		}
	}

	int p2 = -1;

	for(int i = 0; i < cnt; ++i)
	{
		if(c[i].size() == 2)
		{
			p2 = i;
		}

		if(c[i].size() % 2 == 1)
		{
			cout << "NO" << endl;
			return;
		}
	}

	if(p2 == -1)
	{
		cout << "NO" << endl;
		return;
	}

	go2(p2);
}

int main()
{
	_pre();

	_solve();

	_post();
	
	return 0;
}
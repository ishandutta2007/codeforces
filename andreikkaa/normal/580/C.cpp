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

const int MAX_N = 100 * 1000 + 1;

vector<int> g[MAX_N];
bool bad[MAX_N];

int m;
int ans = 0;

void dfs(int v, int p, int b)
{
	if(bad[v])
	{
		--b;
	}
	else
	{
		b = m;
	}

	if(b < 0)
	{
		return;
	}

	if(g[v].size() == 1 and p == g[v][0])
	{
		++ans;
	}

	for(int i : g[v])
	{
		if(i == p)
		{
			continue;
		}

		dfs(i, v, b);
	}
}

void _solve()
{
	int n;
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		cin >> bad[i];
	}

	for(int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		--x;
		--y;

		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(0, -1, m);

	cout << ans << endl;
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}
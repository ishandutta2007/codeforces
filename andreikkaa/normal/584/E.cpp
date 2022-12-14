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
	const int MAX_N = 2000 + 1;

	static int p1[MAX_N], p2[MAX_N], p3[MAX_N];

	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p1[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> p2[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(p2[i] == p1[j])
			{
				p3[j] = i;
			}
		}
	}

	iota(p2 + 1, p2 + 1 + n, 1);
	move(p3 + 1, p3 + 1 + n, p1 + 1);

	int ans = 0;
	vector<pair<int, int>> ops;

	for(int i = 1; i <= n; ++i)
	{
		int p = -1;

		for(int j = i; j <= n; ++j)
		{
			if(p1[j] == i)
			{
				p = j;
				break;
			}
		}

		assert(p != -1);

		for(int j = p - 1; p > i; --j)
		{
			if(p1[j] >= p)
			{
				swap(p1[p], p1[j]);
				ans += p - j;
				ops.push_back({p, j});
				p = j;
			}
		}

		assert(p == i);
	}

	cout << ans << endl;
	cout << ops.size() << endl;

	for(auto i : ops)
	{
		cout << i.first << " " << i.second << "\n";
	}
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}
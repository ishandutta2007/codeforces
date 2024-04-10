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

const int MAX_C = 1000 * 1000;

const int BLOCK = 1000;
const int SIZE = MAX_C / BLOCK;

vector<pair<pair<int, int>, int>> v[BLOCK + 1][BLOCK + 1];

bool cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
	return a.first < b.first;
}

vector<int> ans;

void go(int x, int y)
{
	sort(v[x][y].begin(), v[x][y].end(), cmp);

	for(auto i : v[x][y])
	{
		ans.push_back(i.second);
	}
}

inline void _solve()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		v[x / SIZE][y / SIZE].push_back({{x, y}, i + 1});
	}

	for(int i = 0; i <= BLOCK; ++i)
	{
		if(i % 2 == 0)
		{
			for(int j = 0; j <= BLOCK; ++j)
			{
				go(i, j);
			}
		}
		else
		{
			for(int j = BLOCK; j >= 0; --j)
			{
				go(i, j);
			}
		}
	}

	for(int i : ans)
	{
		cout << i << " ";
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
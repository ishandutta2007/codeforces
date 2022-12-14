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
	const int MAX_N = 5 * 100 * 1000 + 1;

	int n;
	cin >> n;

	static pair<int, int> a[MAX_N];

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i].first >> a[i].second;
	}

	sort(a, a + n, [](const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second < b.second;
	});

	int l = 0;
	int ans = 0;

	for(int i = 0; i < n; ++i)
	{
		if(a[i].first > l)
		{
			++ans;
			l = a[i].second;
		}
	}

	cout << ans << endl;
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}
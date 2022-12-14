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
	int n;
	cin >> n;

	vector<int> a(n);

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	while(not a.empty() and a.front() == 0)
	{
		a.erase(a.begin());
	}

	while(not a.empty() and a.back() == 0)
	{
		a.pop_back();
	}

	int ans = 0;

	for(int i = 0; i < a.size(); ++i)
	{
		ans += a[i];

		if(a[i] == 0 and a[i - 1] == 1 and a[i + 1] == 1)
		{
			++ans;
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
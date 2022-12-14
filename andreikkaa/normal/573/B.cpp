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

const int MAX_N = 100 * 1000 + 4;

int lft[MAX_N];
int rgt[MAX_N];
int a[MAX_N];

inline void _solve()
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		lft[i] = min(lft[i - 1] + 1, a[i]);
	}

	for(int i = n; i > 0; --i)
	{
		rgt[i] = min(rgt[i + 1] + 1, a[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		lft[i] = min(lft[i], rgt[i]);
	}

	cout << *max_element(lft + 1, lft + n + 1) << endl;
}

int main()
{
	_pre();

	_solve();

	_post();
	
	return 0;
}
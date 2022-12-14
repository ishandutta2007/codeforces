/* ______ INCLUDES ______ */

#include <bits/stdc++.h>

/* _____ NAMESPACES _____ */

using namespace std;

/* ______ TEMPLATE ______ */

typedef long long ll;
typedef double ld;

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

const int MAX_N = 200 * 1000 + 1;
const ld EPS = 1e-9;

ld a[MAX_N];
int n;

inline ld f(const ld x)
{
	ld ans = 0;

	ld mi = 0, cur = 0;

	for(int i = 0; i < n; ++i)
	{
		cur += a[i] - x;
		ans = max(ans, abs(cur - mi));
		mi = min(mi, cur);
	}

	ld ma = 0;
	cur = 0;

	for(int i = 0; i < n; ++i)
	{
		cur += a[i] - x;
		ans = max(ans, abs(cur - ma));
		ma = max(ma, cur);
	}

	return ans;
}

inline void _solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	ld l = -10001, r = 10001;

	for(int i = 0; i < 200; ++i)
	{
		ld m1 = l + (r - l) / 3;
		ld m2 = r - (r - l) / 3;

		if(f(m1) < f(m2))
		{
			r = m2;
		}
		else
		{
			l = m1;
		}
	}

	cout << setprecision(30) << fixed << f(l) << endl;
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}
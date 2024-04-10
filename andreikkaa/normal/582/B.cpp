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

inline void _solve()
{
	const int MAX_N = 210 + 1;
	const int MAX_A = 300 + 1;

	static int a[MAX_N * MAX_N];
	static int prf[MAX_A], suf[MAX_A];

	int n, t;
	cin >> n >> t;

	if(t <= 210)
	{
		for(int i = 0; i < n; ++i)
		{
			cin >> a[i];
			for(int j = i; j < n * t; j += n)
			{
				a[j] = a[i];
			}
		}

		for(int i = 0; i < n * t; ++i)
		{
			for(int j = a[i]; j > 0; --j)
			{
				prf[a[i]] = max(prf[a[i]], prf[j] + 1);
			}
		}

		cout << *max_element(prf, prf + MAX_A) << endl;
	}
	else
	{
		for(int i = 0; i < n; ++i)
		{
			cin >> a[i];
			for(int j = i; j < n * n; j += n)
			{
				a[j] = a[i];
			}
		}

		for(int i = 0; i < n * n; ++i)
		{
			for(int j = a[i]; j > 0; --j)
			{
				prf[a[i]] = max(prf[a[i]], prf[j] + 1);
			}
		}

		reverse(a, a + n * n);

		for(int i = 0; i < n * n; ++i)
		{
			for(int j = a[i]; j < MAX_A; ++j)
			{
				suf[a[i]] = max(suf[a[i]], suf[j] + 1);
			}
		}

		reverse(a, a + n * n);

		int ans = 0;

		for(int i = 0; i < MAX_A; ++i)
		{
			ans = max(ans, prf[i] + (int) count(a, a + n, i) * (t - 2 * n) + suf[i]);
		}

		cout << ans << endl;
	}
}

int main()
{
	_pre();

	_solve();

	_post();
	
	return 0;
}
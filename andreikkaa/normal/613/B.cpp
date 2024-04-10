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

const int MAX_N = 100 * 1000 + 228;
pair<ll, int> a[MAX_N];
ll ps[MAX_N];
ll res[MAX_N];

ll get_s(int a, int b)
{
	if(a > b)
		return 0;

	if(a == 0)
		return ps[b];
	return ps[b] - ps[a - 1];
}

inline void _solve()
{
	int n;
	ll A;
	ll cf, cm, m;
	cin >> n >> A >> cf >> cm >> m;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a, a + n);
	ps[0] = a[0].first;
	for(int i = 1; i < n; ++i)
	{
		ps[i] = ps[i - 1] + a[i].first;
	}

	ll ans = -1;
	ll ans_i = -1, ans_lvl = -1;

	for(int i = n; i >= 0; --i)
	{
		ll mm = m;
		mm -= A * (n - i) - get_s(i, n - 1);

		if(mm < 0)
			break;

		ll l = 0, r = A;
		while(l != r)
		{
			ll mid = (l + r) / 2;
			int pos = (int) (lower_bound(a, a + i, make_pair(mid, -1)) - a - 1);
			if((pos + 1) * mid - get_s(0, pos) > mm)
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}

		int pos = ((int) (lower_bound(a, a + i, make_pair(l, -1)) - a)) - 1;
		if((pos + 1) * l - get_s(0, pos) > mm)
			--l;
		pos = ((int) (lower_bound(a, a + i, make_pair(l, -1)) - a)) - 1;
		assert((pos + 1) * l - get_s(0, pos) <= mm);

		if(l * cm + (n - i) * cf > ans)
		{
			ans = l * cm + (n - i) * cf;
			ans_i = i;
			ans_lvl = l;
		}
	}

	for(int i = 0; i < ans_i; ++i)
	{
		res[a[i].second] = max(ans_lvl, a[i].first);
	}

	for(int i = ans_i; i < n; ++i)
	{
		res[a[i].second] = A;
	}

	cout << ans << endl;
	for(int i = 0; i < n; ++i)
	{
		cout << res[i] << " ";
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
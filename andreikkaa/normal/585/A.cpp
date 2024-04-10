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
	const int MAX_N = 4000 + 1;
	static ll v[MAX_N], d[MAX_N], p[MAX_N];
	static bool used[MAX_N];

	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> v[i] >> d[i] >> p[i];
	}

	vector<int> ans;

	for(int i = 1; i <= n; ++i)
	{
		if(used[i])
		{
			continue;
		}

		ans.push_back(i);

		ll cur = v[i];
		ll cnt = v[i];

		for(int j = i + 1; j <= n; ++j)
		{
			if(not used[j])
			{
				p[j] -= cur;

				if(p[j] < 0)
				{
					used[j] = true;
					cur += d[j];
				}
				if(cnt > 0)
			 	{
					--cnt;
					--cur;
				}
                        }
		}
	}

	cout << ans.size() << endl;

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
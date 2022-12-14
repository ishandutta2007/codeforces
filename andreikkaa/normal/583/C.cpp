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
	const int MAX_N = 500 * 500 + 1;

	static int a[MAX_N];
	map<int, int> ans;

	int n;
	cin >> n;
	n *= n;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	reverse(a, a + n);

	vector<pair<int, int>> cnt;

	for(int i = 0; i < n;)
	{
		int j;
		for(j = i; j < n and a[i] == a[j]; ++j)
		{

		}

		int sum = j - i;
		sum -= ans[a[i]];

		int lcm = 0;

		for(auto& k : cnt)
		{
			if(k.first % a[i] == 0)
			{
				lcm += 2 * k.second;
			}
		}

		int k;
		for(k = 0; k * k <= n; ++k)
		{
			if(k * k + k * lcm == sum)
			{
				break;
			}
		}

		assert(k * k <= n);

		int s = k;

		if(s == 0)
		{
			i = j;
			continue;
		}

		cnt.push_back({a[i], s});

		for(auto& l : cnt)
		{
			ans[__gcd(a[i], l.first)] += 2 * s * l.second;
		}

		i = j;
	}

	for(auto& i : cnt)
	{
		for(int j = 0; j < i.second; ++j)
		{
			cout << i.first << " ";
		}
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
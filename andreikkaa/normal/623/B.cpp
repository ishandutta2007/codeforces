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

vector<int> v;

void f(int x)
{
	int sq = (int) sqrt(x);
	for(int i = 2; i <= sq; ++i)
	{
		if(x % i == 0)
		{
			v.push_back(i);
			do
			{
				x /= i;
			}
			while(x % i == 0);
		}
	}
	if(x > 1)
	{
		v.push_back(x);
	}
}

const ll INF = 1000ll * 1000 * 1000 * 1000 * 1000;
const int MAX_N = 1000 * 1000 + 228;
int a[MAX_N];
ll cost[MAX_N];
ll dp[3][MAX_N];

inline void _solve()
{
	int n;
	ll aa, bb;
	cin >> n >> aa >> bb;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for(int i : {0, n - 1})
	{
		for(int j : {-1, 0, 1})
		{
			f(a[i] + j);
		}
	}

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	ll ans = (n - 1) * aa;

	for(int num : v)
	{
		bool st = false;
		for(int i = 0; i < n; ++i)
		{
			if(a[i] % num == 0)
			{
				cost[i] = 0;
			}
			else if((a[i] - 1) % num == 0 or (a[i] + 1) % num == 0)
			{
				cost[i] = bb;
			}
			else
			{
				cost[i] = INF;
			}
		}

		dp[0][0] = cost[0];
		dp[1][0] = aa;
		dp[2][0] = cost[0];

		for(int j = 1; j < n; ++j)
		{
			dp[0][j] = min((dp[0][j - 1] + cost[j]), INF);
			dp[1][j] = min(min(dp[1][j - 1], dp[0][j - 1]) + aa, INF);
			dp[2][j] = min(min(dp[2][j - 1], dp[1][j - 1]) + cost[j], INF);

			/*if(min({dp[0][j], dp[1][j], dp[2][j]}) > ans)
			{
				st = true;
				break;
			}*/
		}

		/*if(st)
			continue;*/

		/*cout << "num " << num << endl;
		for(int j = 0; j < n; ++j)
		{
			cout << dp[0][j] << " " << dp[1][j] << " " << dp[2][j] << endl;
		}
		cout << endl;*/

		ans = min({ans, dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]});
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
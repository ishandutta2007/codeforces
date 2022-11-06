#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ld double

const int maxn = 1e2 + 20;

int n;
ld c , t;

ld dp[maxn][maxn][maxn * 10] , pw[maxn];

pair<int , int> a[maxn];

void f()
{
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= n * 10; k++)
				dp[i][j][k] = 1e18;

	dp[0][0][0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= i; j++)
			for(int k = 0; k <= j * 10; k++)
			{
				dp[i][j][k] = dp[i - 1][j][k];

				if(j && k >= a[i].second)
				{
					ld tmp = dp[i - 1][j - 1][k - a[i].second] + (ld)a[i].first / pw[j];
					dp[i][j][k] = min(dp[i][j][k] , tmp);
				}
			}
}

inline ld get(ld dp , ld x)
{
	return dp / (1.0 + c * x) + x;
}

void solve()
{
	cin >> n >> c >> t;

	for(int i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second;

	sort(a + 1 , a + n + 1);
	reverse(a + 1 , a + n + 1);
	f();

	int res = 0;
	for(int k = n * 10; k >= 0; k--)
		for(int j = 0; j <= n; j++)
		{
			ld l = 0 , r = t;
			for(int i = 0; i < 30; i++)
			{
				ld m1 = (2 * l + r) / 3.0 , m2 = (l + 2 * r) / 3.0;

				if(get(dp[n][j][k] , m1) >= get(dp[n][j][k] , m2))
					l = m1;
				else
					r = m2;
			}

			if(get(dp[n][j][k] , l) + 10 * j <= t)
				res = max(res , k);
		}

	cout << res << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pw[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw[i] = pw[i - 1] * 9.0 / 10.0;

	int tc;
	cin >> tc;

	while(tc--)
		solve();
}
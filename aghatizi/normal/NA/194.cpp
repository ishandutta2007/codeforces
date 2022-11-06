#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 4e2 + 20;
const int maxm = 25e4 + 20;

int dp[2][maxn][maxn] , mn[2][maxn][maxn] , s[maxm] , t[maxm] , c[maxm] , f[maxm];

int a[maxn];

vector<int> query[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 0; i < m; i++)
	{
		cin >> s[i] >> t[i] >> c[i] >> f[i];
		query[f[i]].pb(i);
	}

	memset(dp , 63 , sizeof dp);
	ll V = 0;
	for(int step = 0; step <= n; step++)
	{
		int i = step&1;
		for(int l = 1; l <= n; l++)
		{
			int p = l;
			dp[0][l][l] = dp[1][l][l] = 0;
			for(int r = l; r <= n; r++)
			{
				while(p < r && max(dp[!i][l][p] , a[r] - a[p]) > max(dp[!i][l][p + 1] , a[r] - a[p + 1]))
					p++;
				dp[i][l][r] = max(dp[!i][l][p] , a[r] - a[p]);
			}
		}

		for(auto ind : query[step])
			V = max(V , 1LL * c[ind] * dp[i][s[ind]][t[ind]]);
	}
	cout << V << endl;
}
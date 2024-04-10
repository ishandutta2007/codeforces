#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 7e2 + 20;

int a[maxn];

vector<short> adj[maxn];

bool dp[maxn][maxn] , pd[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i != j && __gcd(a[i] , a[j]) > 1)
				adj[i].pb(j);

	for(int l = n - 1; l >= 0; l--)
		for(int r = l; r < n; r++)
		{
			if(l == r)
			{
				dp[l][r] = pd[l][r] = 1;

				continue;
			}

			for(short x : adj[l])
				if(pd[l + 1][x] && dp[x][r])
				{
					dp[l][r] = 1;
					break;
				}

			for(short x : adj[r])
				if(pd[l][x] && dp[x][r - 1])
				{
					pd[l][r] = 1;
					break;
				}
		}

	for(int i = 0; i < n; i++)
		if(pd[0][i] && dp[i][n - 1])
			return cout << "Yes" << endl , 0;
	
	cout << "No" << endl;

}
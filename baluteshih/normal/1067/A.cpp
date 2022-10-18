#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll dp[2][201][2],sum[2][201][2];
const ll MOD=998244353;

int main()
{jizz
	ll n,x;
	cin >> n >> x;
	if(x==-1)
		for(int i=1;i<=200;++i)
			dp[0][i][0]=1,sum[0][i][0]=dp[0][i][0]+sum[0][i-1][0];
	else
	{
		dp[0][x][0]=1;
		for(int i=1;i<=200;++i)
			sum[0][i][0]=dp[0][i][0]+sum[0][i-1][0];
	}
	for(ll i=1;i<n;++i)
	{
		cin >> x;
		if(x==-1)
		{
			for(x=1;x<=200;++x)
			{
				dp[0][x][i&1]=(sum[0][x-1][i&1^1]+sum[1][x-1][i&1^1])%MOD;
				dp[1][x][i&1]=(dp[0][x][i&1^1]+sum[1][200][i&1^1]-sum[1][x-1][i&1^1]+MOD)%MOD;
			}
		}
		else
		{
			for(int j=1;j<=200;++j)
				dp[0][j][i&1]=dp[1][j][i&1]=0;
			dp[0][x][i&1]=(sum[0][x-1][i&1^1]+sum[1][x-1][i&1^1])%MOD;
			dp[1][x][i&1]=(dp[0][x][i&1^1]+sum[1][200][i&1^1]-sum[1][x-1][i&1^1]+MOD)%MOD;
		}
		for(int j=1;j<=200;++j)
			sum[0][j][i&1]=(dp[0][j][i&1]+sum[0][j-1][i&1])%MOD,sum[1][j][i&1]=(dp[1][j][i&1]+sum[1][j-1][i&1])%MOD;
	}
	cout << sum[1][200][n&1^1] << "\n";
}
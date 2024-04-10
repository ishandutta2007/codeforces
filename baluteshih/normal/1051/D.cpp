#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD=998244353;
ll dp[4][2005][1005];//type k n

ll gd(ll a,ll b,ll c)
{
	if(a<0 || b<0 || c<0) return 0;
	return dp[a][b][c];
}

ll cou(ll k,ll x)
{
	cout << (dp[0][k][x]+dp[1][k][x]+dp[2][k][x]+dp[3][k][x])%MOD << "\n";
}

int main()
{jizz
	ll n,k;
	cin >> n >> k;
	dp[0][1][1]=dp[1][2][1]=dp[2][2][1]=dp[3][1][1]=1;
	for(ll i=2;i<=n;++i)
		for(ll j=1;j<=k;++j)
		{
			dp[0][j][i]=(gd(0,j,i-1)+gd(1,j,i-1)+gd(2,j,i-1)+gd(3,j-1,i-1))%MOD;//0 0
			dp[1][j][i]=(gd(0,j-1,i-1)+gd(1,j,i-1)+gd(2,j-2,i-1)+gd(3,j-1,i-1))%MOD;//0 1
			dp[2][j][i]=(gd(0,j-1,i-1)+gd(1,j-2,i-1)+gd(2,j,i-1)+gd(3,j-1,i-1))%MOD;//1 0
			dp[3][j][i]=(gd(0,j-1,i-1)+gd(1,j,i-1)+gd(2,j,i-1)+gd(3,j,i-1))%MOD;//1 1
		}
	//for(ll i=0;i<n;++i) cou(k,i);
	cou(k,n);
}
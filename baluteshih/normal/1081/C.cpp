#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll dp[2005][2005];
const ll MOD=998244353;

ll pw(ll a,ll n)
{
	ll re=1;
	for(;n;n>>=1,a=a*a%MOD)
		if(n&1) re=re*a%MOD;
	return re;
}

int main()
{jizz
	ll n,m,k;
	cin >> n >> m >> k;
	dp[0][0]=dp[1][0]=1;
	for(ll i=1;i<=n;++i)
		for(ll j=0;j<=i;++j)
		{
			if(j)
				dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%MOD;
			else
				dp[i][j]=1;
		}
	cout << dp[n-1][n-k-1]*pw(m-1,k)%MOD*m%MOD << "\n";
}
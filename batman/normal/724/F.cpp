#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1010)
#define K ((ll)11)

ll n,d,mod,dp[N][N][K],tvn[K];

ll tavan(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		res*=(y%2)?x:1;res%=mod;
		x*=x;x%=mod;
		y/=2;
	}
	return res;
}
ll C(ll x,ll y)
{
	if(x<y)return 0;
	ll res=1;
	for(ll i=x;i>x-y;i--)res*=i,res%=mod;
	for(ll i=1;i<=y;i++)res*=tvn[i],res%=mod;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>d>>mod;
	for(int i=1;i<K;i++)tvn[i]=tavan(i,mod-2);
	if(n<=2)return cout<<"1\n",0;
	dp[1][0][d-1]=dp[1][0][0]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i-1;j++)
			for(int k=1;k<=d;k++)
			{
				dp[i][j][k]=dp[i][j-1][k];
				for(int p=1;p*j<=i-1 && p<=k;p++)
					if(i-p*j!=1 || min(j-1,i-p*j-1)!=0 || k-p!=d-1)
						dp[i][j][k]+=(dp[i-p*j][min(j-1,i-p*j-1)][k-p]*C(dp[j][j-1][d-1]+p-1,p))%mod,dp[i][j][k]%=mod;
			}
	ll res=dp[n][n/2][d];
	if(n%2==0)res-=C(dp[n/2][n/2-1][d-1],2),res%=mod,res+=mod,res%=mod;
	cout<<res<<"\n";;
	return 0;
}
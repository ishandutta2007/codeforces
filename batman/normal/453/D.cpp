#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1200*1000)
#define M ((ll)22)

ll m,n;
int dp[2][N][M];
ll t,MOD,c[M][M];
vector <ll> b;

vector <ll> merge(vector <ll> x,vector <ll> y)
{
	vector <ll> ret;
	for(ll i=0;i<=m;i++)
	{
		ll res=0;
		for(ll p=0;p<=m;p++)
			for(ll q=0;q<=m;q++)
			{
				ll ex=(p+q-i)/2;
				if(ex<0 || (p+q-i)%2 || ex>m-i || p<ex || q<ex)continue;
				ll now=x[p]*y[q];now%=MOD;
				now*=c[m-i][ex];now%=MOD;
				now*=c[i][p-ex];now%=MOD;
				res+=now;res%=MOD;
			}
		ret.push_back(res);
	}
	return ret;
}

int main()
{
	scanf("%lld%lld%lld",&m,&t,&MOD);n=(1<<m);
	for(ll i=0;i<M;i++)c[i][0]=c[i][i]=1;
	for(ll i=0;i<M;i++)for(ll j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	for(ll i=0;i<n;i++){int x;scanf("%d",&x);dp[1][i][0]=(x%MOD);}
	for(ll i=0;i<=m;i++){int x;scanf("%d",&x);b.push_back((x%MOD));}
	for(ll i=0;i<m;i++)
		for(ll j=0;j<n;j++)
			for(ll k=0;k<=m;k++)
				dp[(i&1)][j][k]=(1LL*dp[!(i&1)][j][k]+dp[!(i&1)][j^(1<<i)][k-1])%MOD;
	vector <ll> res;
	for(int i=0;i<=m;i++)res.push_back(0);res[0]=1;
	for(ll i=0;i<61;b=merge(b,b),i++)
		if((t&(1LL<<i)))
			res=merge(res,b);
	for(ll i=0;i<n;i++)
	{
		ll ans=0;
		for(ll j=0;j<=m;j++)ans+=(1LL*res[j]*dp[!(m&1)][i][j])%MOD,ans%=MOD;
		int khar=ans;
		printf("%d\n",khar);
	}
	return 0;
}
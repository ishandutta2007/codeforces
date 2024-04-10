#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=10005,MOD=1000000007;

ll n,k,f[MAXN][105],inv[105];
ll qmi(ll x,ll y)
{
	ll ans=1;
	for(;y;y>>=1,x=x*x%MOD)
		if(y&1)ans=ans*x%MOD;
	return ans;
}

int main()
{
    cin>>n>>k;
    f[0][0]=1;
    ll ans=1;
    for(int i=1;i<=100;i++)
    	inv[i]=qmi(i,MOD-2);
    for(ll i=2;i*i<=n;i++)
    {
    	if(n%i)continue;
    	ll cnt=0;
    	while(n%i==0)n/=i,++cnt;
    	memset(f[0],0,sizeof(f[0]));
    	f[0][cnt]=1;
    	for(int j=1;j<=k;j++)
    	{
    		f[j][cnt+1]=0;
    		for(int t=cnt;t>=0;t--)
    			f[j][t]=(f[j][t+1]+f[j-1][t]*inv[t+1])%MOD;
    	}
    	ll s1=0,s2=0;
    	for(int t=0;t<=cnt;t++)
    	{
    		s1=(s1+f[k][t]*qmi(i,t))%MOD;
    		s2=(s2+f[k][t])%MOD;
    		//cout<<k<<" "<<t<<" "<<cnt<<" "<<f[k][t]<<endl;
    	}
    	ans=ans*s1%MOD;
    }
    if(n>1)
    {
    	ll cnt=1;
    	memset(f[0],0,sizeof(f[0]));
    	f[0][cnt]=1;
    	for(int j=1;j<=k;j++)
    	{
    		f[j][cnt+1]=0;
    		for(int t=cnt;t>=0;t--)
    			f[j][t]=(f[j][t+1]+f[j-1][t]*inv[t+1])%MOD;
    	}
    	ll s1=0,s2=0;
    	for(int t=0;t<=cnt;t++)
    	{
    		s1=(s1+f[k][t]*qmi(n,t))%MOD;
    		s2=(s2+f[k][t])%MOD;
    		//cout<<k<<" "<<t<<" "<<cnt<<" "<<f[k][t]<<endl;
    	}
    	ans=ans*s1%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
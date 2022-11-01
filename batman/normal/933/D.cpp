#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1000*1000+10)
#define INF ((ll)2e18)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=(y%2)?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}
ll C(ll x,ll y){ll res=1;for(int i=y+1;i<=x;i++)res*=i;for(int i=1;i<=x-y;i++)res/=i;return (res%MOD);}

ll n,ans;
ll num[N],prt[4][N];
ll zarib[4][4];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(ll i=0;i<N;i++)
	{
		num[i]=i*i;
		for(int j=0;j<=3;j++)
			prt[j][i]=((i?prt[j][i-1]:0)+tavan(num[i]%MOD,j))%MOD;
	}
	for(int i=0;i<=3;i++)
	{
		ll ex=tavan(3,MOD-2);
		if(i==2)ex=(((((-n-2)%MOD)+MOD)%MOD)*tavan(2,MOD-2))%MOD;
		if(i==1)ex=((((n+1)%MOD)*tavan(2,MOD-2))%MOD+tavan(6,MOD-2))%MOD;
		if(i==0)ex=(((((((n+2)%MOD)*((n+1)%MOD))%MOD)*(n%MOD))%MOD)*tavan(6,MOD-2))%MOD;
		for(int j=0;j<=i;j++)
			zarib[j][i-j]+=(C(i,j)*ex)%MOD,zarib[j][i-j]%=MOD;
	}
	for(ll i=1;i*i<=n;i++)
	{
		ll j=upper_bound(num,num+N,n-i*i)-num-1;
		for(int j2=0;j2<=3;j2++)
		{
			ll now=0;
			for(int i2=0;i2<=3;i2++)now+=(tavan(num[i]%MOD,i2)*zarib[i2][j2])%MOD,now%=MOD;
			now*=prt[j2][j];now%=MOD;
			ans+=now;ans%=MOD;
		}
	}
	ans*=4;ans%=MOD;
	ans+=zarib[0][0];ans%=MOD;
	cout<<ans<<"\n";
	return 0;
}
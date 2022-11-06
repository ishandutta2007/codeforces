#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100010;
int n,t0,t1,s0[N],s1[N];
ll a[N],f[N],g[N],dp[70][N];
inline void srt(ll x)//sort by the value mod 2^(i+1)
{
	int cc=0;
	for(int i=1;i<=n;++i)if(!(a[f[i]]>>x&1))g[++cc]=f[i];
	for(int i=1;i<=n;++i)if(a[f[i]]>>x&1)g[++cc]=f[i];
	for(int i=1;i<=n;++i)f[i]=g[i];
}
inline void init(ll x)//calc the number of elements have 2^i
{
	for(int i=1;i<=n;++i)
	{
		s0[i]=s0[i-1];s1[i]=s1[i-1];
		if(a[f[i]]>>x&1)s1[i]++;else s0[i]++;
	}
	t1=s1[n];t0=s0[n];
}
int main()
{
	
	ll mx=0;scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),mx=max(mx,a[i]);
	for(int i=1;i<=n;++i)a[i]=mx-a[i],f[i]=i;
	memset(dp,0x3f,sizeof(dp));dp[0][0]=0;
	for(ll i=0;i<62;++i)
	{
		if(i)srt(i-1);init(i);
		for(int j=0;j<=n;++j)
		{
			int w,stt;
			w=s1[n-j]+t0-s0[n-j];stt=t1-s1[n-j];
			dp[i+1][stt]=min(dp[i+1][stt],dp[i][j]+w);
			w=s0[n-j]+t1-s1[n-j];stt=n-s0[n-j];
			dp[i+1][stt]=min(dp[i+1][stt],dp[i][j]+w);
		}
	}
	printf("%lld\n",dp[62][0]);
	return 0;
}
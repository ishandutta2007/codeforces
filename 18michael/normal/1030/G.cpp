#include<bits/stdc++.h>
#define Mx 2000000
#define LL long long
#define mod 1000000007
using namespace std;
int n,p_t=0,t;
bool o=0,o1;
LL ans=1;
int cnt[2000002],p[2000002],mx[2000002],num[2000002];
bool u[2000002];
vector<int> vec[2000002];
inline LL Pow(int a,int b)
{
	if(!b)return 1;
	LL c=Pow(a,b>>1);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!u[i])
		{
			p[++p_t]=i;
			for(int j=i;j<=Mx;j+=i)vec[j].push_back(i);
		}
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
	}
}
int main()
{
	init(),scanf("%d",&n);
	for(int i=1;i<=Mx;++i)u[i]=0;
	for(int i=1,x;i<=n;++i)scanf("%d",&x),++cnt[x];
	for(int i=Mx,i0;i;(ans*=Pow(i,mx[i]))%=mod,--i)
	{
		if(cnt[i] && !mx[i])mx[i]=num[i]=1,--cnt[i];
		if(cnt[i])
		{
			i0=i-1,u[i]=1;
			for(int j=0;j<vec[i-1].size();++j)
			{
				for(t=0;!(i0%vec[i-1][j]);i0/=vec[i-1][j])++t;
				if(mx[vec[i-1][j]]<t)mx[vec[i-1][j]]=t,num[vec[i-1][j]]=1;
				else if(mx[vec[i-1][j]]==t)++num[vec[i-1][j]];
			}
			--cnt[i];
		}
		if(cnt[i])o=1;
	}
	for(int i=1,i0;i<=Mx;++i)
		if(u[i])
		{
			i0=i-1,o1=1;
			for(int j=0;j<vec[i-1].size();++j)
			{
				for(t=0;!(i0%vec[i-1][j]);i0/=vec[i-1][j])++t;
				if(mx[vec[i-1][j]]==t && num[vec[i-1][j]]==1)
				{
					o1=0;
					break;
				}
			}
			o|=o1;
		}
	return 0&printf("%lld",(ans+o)%mod);
}
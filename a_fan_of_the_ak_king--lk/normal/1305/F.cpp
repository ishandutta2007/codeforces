#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,P=998244353;
const int N=1000005,E=262144;
#define inf 2147483647
int n,i,j,t,m,k;
long long a[N],ans,s[N],prime[N],tmp[N],ts[N];
map<long long,int> u;
mt19937 rnd(time(0));
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	long long sc=0,pa=0;
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		ans+=a[i]%2;
		sc^=a[i];
		pa+=a[i];
	}
	srand((time(0)*sc*pa%998244353+998244353)%998244353);
	random_shuffle(a+1,a+1+n);
	for(i=1;i<=30&&i<=n;++i)
	{
		long long tmp=a[i];
		for(long long j=2;j*j<=tmp;++j)
			if(tmp%j==0)
			{
				u[j]=1;
				while(tmp%j==0)
					tmp/=j;
			}
		if(tmp!=1)
			u[tmp]=1;
		tmp=a[i]-1;
		if(tmp!=0)
		{
		for(long long j=2;j*j<=tmp;++j)
			if(tmp%j==0)
			{
				u[j]=1;
				while(tmp%j==0)
					tmp/=j;
			}
		if(tmp!=1)
			u[tmp]=1;
		}
		tmp=a[i]+1;
		for(long long j=2;j*j<=tmp;++j)
			if(tmp%j==0)
			{
				u[j]=1;
				while(tmp%j==0)
					tmp/=j;
			}
		if(tmp!=1)
			u[tmp]=1;
	}
	u[2]=u[3]=u[5]=u[7]=u[11]=u[13]=u[17]=u[19]=u[23]=u[29]=u[31]=u[37]=u[41]=u[43]=u[47]=u[53]=u[59]=u[61]=u[67]=u[71]=u[73]=u[79]=u[83]=u[89]=u[97]=1;
	for(auto it:u)
		prime[++k]=it.first;
	for(i=1;i<=n;++i)
	{
		t=0;
		for(j=1;j<=k;++j)
			if(a[i]<prime[j])
				s[j]+=prime[j]-a[i];
			else
				s[j]+=min(a[i]%prime[j],prime[j]-a[i]%prime[j]);
		for(j=1;j<=k;++j)
			if(s[j]<ans)
			{
				tmp[++t]=prime[j];
				ts[t]=s[j];
			}
		for(j=1;j<=t;++j)
		{
			prime[j]=tmp[j];
			s[j]=ts[j];
		}
		k=t;
	}
	for(j=1;j<=k;++j)
		ans=min(ans,s[j]);
	cout<<ans;
		
}
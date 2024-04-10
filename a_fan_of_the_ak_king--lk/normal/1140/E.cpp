#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,a[200005],b[200005],i,k;
long long ans=1,s=1,p[200005],q[200005];
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
void cnt()
{
	int i,t,j;
	for(i=1;i<=k;++i)
		if(b[i]!=0)
		{
			t=i;
			break;
		}
	if(i>k)
	{
		ans=ans*qpow(m-1,k-1)%M*m%M;
		return;
	}
	long long s=qpow(m-1,t-1);
	for(i=t;i<=k;)
	{
		for(j=i+1;b[j]==0&&j<=k;++j);
		if(j>k)
		{
			s=s*qpow(m-1,k-i)%M;
			break;
		}
		if(b[j]==b[i])
			s=s*p[j-i]%M;
		else
			s=s*q[j-i]%M;
		i=j;
	}
	ans=ans*s%M;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]==-1)
			a[i]=0;
		if(a[i]==0)
			s=s*m%M;
	}
	p[1]=0;
	q[1]=1;
	for(i=2;i<=n;++i)
	{
		p[i]=q[i-1]*(m-1)%M;
		q[i]=(p[i-1]+q[i-1]*(m-2))%M;
	}
	for(i=1;i<=n;i+=2)
		b[++k]=a[i];
	cnt();
	k=0;
	for(i=2;i<=n;i+=2)
		b[++k]=a[i];
	cnt();
	cout<<(ans%M+M)%M;
}
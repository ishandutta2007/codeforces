#include<bits/stdc++.h>
using namespace std;
const int N=1000005,M=998244353,E=2097152;
int R[N*4];
long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%M;
		a=a*a%M;
		b>>=1;
	}
	return ans;
}
int wn[N*4],iwn[N*4];
void init()
{
	int i;
	iwn[E/2]=wn[E/2]=1;
	long long s1=qpow(3,(M-1)/E);
	long long s2=qpow(s1,M-2);
	for(i=E/2+1;i<E;++i)
	{
		wn[i]=wn[i-1]*s1%M;
		iwn[i]=iwn[i-1]*s2%M;
	}
	for(i=E/2-1;i;--i)
	{
		wn[i]=wn[i<<1];
		iwn[i]=iwn[i<<1];
	}
}
void NTT(int *f,int lim,int op)
{
	int i,j,k;
	for(i=0;i<lim;++i)
	{
		R[i]=(R[i>>1]>>1)|(i&1?lim>>1:0);
		if(R[i]<i)
			swap(f[R[i]],f[i]);
	}
	for(i=1;i<lim;i<<=1)
		for(j=0;j<lim;j+=(i<<1))
			for(k=j;k<j+i;++k)
			{
				int a=f[k],w=1ll*(op==1?wn[k-j+i]:iwn[k-j+i])*f[k+i]%M;
				f[k]=(a+w)%M;
				f[k+i]=(a-w)%M;
			}
	if(op==-1)
	{
		long long inv=qpow(lim,M-2);
		for(i=0;i<lim;++i)
			f[i]=f[i]*inv%M;
	}
}
int n,m,i,a,f[N],ans[N],k,t[N*4];
int main()
{
	init();
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&a);
		f[a]=t[a]=1;
	}
	t[0]=1;
	int lim=1;
	while(lim<=m*2)
		lim<<=1;
	NTT(t,lim,1);
	for(i=0;i<lim;++i)
		t[i]=1ll*t[i]*t[i]%M;
	NTT(t,lim,-1);
	for(i=1;i<=m;++i)
	{
		t[i]=(t[i]%M+M)%M;
		if(f[i])
		{
			if(t[i]==2)
				ans[++k]=i;
		}
		else
			if(t[i]!=0)
			{
				puts("NO");
				return 0;
			}
	}
	puts("YES");
	printf("%d\n",k);
	for(i=1;i<=k;++i)
		printf("%d ",ans[i]);
}
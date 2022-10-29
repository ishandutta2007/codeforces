#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=125005,md=998244353;
int n,m,i,j,k,x,p[N],f[N*4],g[N*4],h[6][N*4],rt[N*4],ome[N*4],rome[N*4],inv,lmt,len;
char s[N],t[N];
bool w[6][6][N];
int find(int x)
{
	if(p[x]==-1)
		return x;
	return p[x]=find(p[x]);
}
int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
void ntt(int a[N*4],bool t)
{
	for(int i=0;i<len;++i)
		if(rt[i]>i)
			swap(a[i],a[rt[i]]);
	for(int l=2;l<=len;l<<=1)
	{
		int m=l>>1;
		for(int i=0;i<len;i+=l)
			for(int j=0;j<m;++j)
			{
				int w=1ll*(t?ome[len/l*j]:rome[len/l*j])*a[i+j+m]%md;
				a[i+j+m]=(a[i+j]-w+md)%md;
				a[i+j]=(a[i+j]+w)%md;
			}
	}
	if(!t)
		for(int i=0;i<len;++i)
			a[i]=1ll*a[i]*inv%md;
}
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	if(n<=1000&&m<=1000)
	{
	for(i=1;i+m-1<=n;++i)
	{
		for(j=0;j<=5;++j)
			p[j]=-1;
		for(j=1,k=0;j<=m;++j)
			if(find(s[i+j-1]-'a')!=find(t[j]-'a'))
			{
				p[find(s[i+j-1]-'a')]=find(t[j]-'a');
				++k;
			}
		printf("%d ",k);
	}
	return 0;
	}
	lmt=0;
	while((1<<lmt)<=n+2)
		++lmt;
	len=1<<lmt;
	inv=pw(len,md-2);
	for(i=0,j=pw(3,(md-1)/len),k=pw(j,md-2);i<len;++i)
	{
		if(i==0)
			ome[i]=rome[i]=1;
		else
			ome[i]=1ll*ome[i-1]*j%md,rome[i]=1ll*rome[i-1]*k%md;
		for(x=0;x<lmt;++x)
			if((1<<x)&i)
				rt[i]|=1<<(lmt-x-1);
	}
	for(j=0;j<=5;++j)
	{
		for(k=0;k<len;++k)
			h[j][k]=0;
		for(k=1;k<=m;++k)
			if(t[k]-'a'==j)
				h[j][m-k+1]=1;
			else
				h[j][m-k+1]=0;
		ntt(h[j],true);
	}
	for(i=0;i<=5;++i)
	{
		for(k=0;k<len;++k)
			f[k]=0;
		for(k=1;k<=n;++k)
			if(s[k]-'a'==i)
				f[k]=1;
			else
				f[k]=0;
		ntt(f,true);
		for(j=0;j<=5;++j)
			if(i!=j)
			{
				for(k=0;k<len;++k)
					g[k]=1ll*f[k]*h[j][k]%md;
				ntt(g,false);
				for(k=1;k+m-1<=n;++k)
					if(g[m+k])
						w[i][j][k]=true;
			}
	}
	for(i=1;i+m-1<=n;++i)
	{
		for(j=0;j<=5;++j)
			p[j]=-1;
		x=0;
		for(j=0;j<=5;++j)
			for(k=0;k<=5;++k)
				if(w[j][k][i]&&find(j)!=find(k))
				{
					p[find(j)]=find(k);
					++x;
				}
		printf("%d ",x);
	}
	return 0;
}
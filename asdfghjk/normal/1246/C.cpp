#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int md=1000000007;
int n,m,i,j,k,f[2005][2005][2],w1[2005][2005],w2[2005][2005],c1[2005][2005],c2[2005][2005];
char s[2005][2005];
void add1(int id,int x,int y)
{
	++x;
	while(x<=m+1)
	{
		c1[id][x]=(c1[id][x]+y)%md;
		x+=x&-x;
	}
}
int sum1(int id,int x)
{
	++x;
	int rtn=0;
	while(x>=1)
	{
		rtn=(rtn+c1[id][x])%md;
		x-=x&-x;
	}
	return rtn;
}
void add2(int id,int x,int y)
{
	++x;
	while(x<=n+1)
	{
		c2[id][x]=(c2[id][x]+y)%md;
		x+=x&-x;
	}
}
int sum2(int id,int x)
{
	++x;
	int rtn=0;
	while(x>=1)
	{
		rtn=(rtn+c2[id][x])%md;
		x-=x&-x;
	}
	return rtn;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=m;++j)
			w1[i][j]=w1[i][j-1]+(s[i][j]=='R');
	}
	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			w2[j][i]=w2[j-1][i]+(s[j][i]=='R');
	if(n==1&&m==1)
	{
		printf("%d",s[1][1]=='R'?0:1);
		return 0;
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			if(i==1&&j==1)
				f[i][j][0]=f[i][j][1]=1;
			else
			{
				f[i][j][0]=(1ll*f[i][j][0]+sum1(i,m)-sum1(i,max(min(w1[i][m]-m+j-1,m),-1))+md)%md;
				f[i][j][1]=(1ll*f[i][j][1]+sum2(j,n)-sum2(j,max(min(w2[n][j]-n+i-1,n),-1))+md)%md;
				/*for(k=j-1;k>=1&&w1[i][m]-w1[i][k]<=m-j;--k)
					f[i][j][0]=(f[i][j][0]+f[i][k][1])%md;
				for(k=i-1;k>=1&&w2[n][j]-w2[k][j]<=n-i;--k)
					f[i][j][1]=(f[i][j][1]+f[k][j][0])%md;*/
			}
			add1(i,w1[i][j],f[i][j][1]);
			add2(j,w2[i][j],f[i][j][0]);
		}
	printf("%d",(f[n][m][0]+f[n][m][1])%md);
	return 0;
}
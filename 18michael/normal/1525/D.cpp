#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,v0_t,v1_t,res;
int a[5002],p[5002],v0[5002],v1[5002],ans[5002];
int f[5002][5002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
/*inline int solve(int l,int r)
{
	if(~f[l][r])return f[l][r];
	if(l==r)
	{
		if(a[l])f[l][r]=inf;
		else f[l][r]=0;
		return f[l][r];
	}
	if(l+1==r)
	{
		if(a[l] && a[r])f[l][r]=inf;
		else if(!a[l] && !a[r])f[l][r]=0;
		else f[l][r]=1;
		return f[l][r];
	}
	if((p[r]-p[l-1])*2>r-l+1)return (f[l][r]=inf);
	f[l][r]=inf;
	for(int k=l;k<r;++k)f[l][r]=min(f[l][r],solve(l,k)+solve(k+1,r));
	return f[l][r];
}*/
int main()
{
	read(n);//,memset(f,-1,sizeof(f));
	for(int i=1;i<=n;++i)read(a[i]),p[i]=p[i-1]+a[i];
	for(int i=1;i<=n;++i)
	{
		res=v0_t=v1_t=0;
		for(int j=i;j<=n;++j)
		{
			if(a[j])
			{
				if(!v0_t)v1[++v1_t]=j;
				else res+=j-v0[v0_t],--v0_t;
			}
			else
			{
				if(!v1_t)v0[++v0_t]=j;
				else res+=j-v1[v1_t],--v1_t;
			}
			if(!v0_t && !v1_t)f[i][j]=res;
			else if(p[j]-p[i-1])f[i][j]=inf;
			else f[i][j]=0;
		}
	}
	for(int i=1;i<=n;++i)
	{
		ans[i]=inf;if(p[i]*2>i)continue;
		for(int j=0;j<i;++j)ans[i]=min(ans[i],ans[j]+f[j+1][i]);
	}
	printf("%d",ans[n]);
	//printf("%d",solve(1,n));
	return 0;
}
#include<cstdio>
#include<cmath>
#define Mx 12
#define inf 0x3f3f3f3f
int n,a,b,m=300;
char s[5002];
int cnt[5002],rk[5002],sa[5002],oldrk[5002],id[5002],px[5002],f[5002]={};
int height[5002][13];
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline int max(int x,int y)
{
	return x>y? x:y;
}
inline bool cmp(int x,int y,int w)
{
	return oldrk[x]==oldrk[y] && oldrk[x+w]==oldrk[y+w];
}
int main()
{
	scanf("%d%d%d%s",&n,&a,&b,s+1);
	for(int i=0;i<=m;++i)cnt[i]=0;
	for(int i=1;i<=n;++i)++cnt[rk[i]=s[i]];
	for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
	for(int i=n;i;--i)sa[cnt[rk[i]]--]=i;
	for(int w=1,p;w<n;w<<=1,m=p)
	{
		p=0;
		for(int i=n;i>n-w;--i)id[++p]=i;
		for(int i=1;i<=n;++i)if(sa[i]>w)id[++p]=sa[i]-w;
		for(int i=0;i<=m;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)++cnt[px[i]=rk[id[i]]];
		for(int i=1;i<=m;++i)cnt[i]+=cnt[i-1];
		for(int i=n;i;--i)sa[cnt[px[i]]--]=id[i];
		for(int i=1;i<=n;++i)oldrk[i]=rk[i];
		p=0;
		for(int i=1;i<=n;++i)rk[sa[i]]=cmp(sa[i],sa[i-1],w)? p:++p;
		if(p==n)break;
	}
	for(int i=1,k=0;i<=n;++i)
	{
		if(k)--k;
		while(s[i+k]==s[sa[rk[i]-1]+k])++k;
		height[rk[i]][0]=k;
	}
	for(int i=1;i<=Mx;++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			height[j][i]=min(height[j][i-1],height[j+(1<<(i-1))][i-1]);
	for(int i=1;i<=n;++i)f[i]=inf;
	for(int i=1,x,y,z;i<=n;++i)
	{
		f[i]=min(f[i],f[i-1]+a);
		if(i==n)break;
		for(int j=1;j<=i;++j)
		{
			x=min(rk[i+1],rk[j])+1,y=max(rk[i+1],rk[j]),z=log(y-x+1)/log(2);
			z=i+min(min(height[x][z],height[y-(1<<z)+1][z]),i-j+1),f[z]=min(f[z],f[i]+b);
		}
	}
	return 0&printf("%d",f[n]);
}
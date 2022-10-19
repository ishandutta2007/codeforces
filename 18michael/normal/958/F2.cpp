#include<cstdio>
int n,m,tot=0,l=0,r=0,T,ans;
int a[200002],b[200002];
inline int min(int a,int b)
{
	return a<b? a:b;
}
int main()
{
	scanf("%d%d",&n,&m),ans=n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]),tot+=b[i];
	T=tot;while(tot && (++r)<=n)if((--b[a[r]])>=0)--tot;
	if(tot)return 0&puts("-1");
	while(r<=n)
	{
		while(!tot && (++l)<=r)if((++b[a[l]])>0)++tot;
		ans=min(ans,r-l+1);
		while(tot && (++r)<=n)if((--b[a[r]])>=0)--tot;
	}
	printf("%d",ans-T);
	return 0;
}
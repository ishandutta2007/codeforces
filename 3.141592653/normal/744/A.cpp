#include<bits/stdc++.h>
int fa[1111111],sz[1111111],vs[1111111];
int rt(int x){return fa[x]?fa[x]=rt(fa[x]):x;}
void merge(int x,int y)
{
	x=rt(x),y=rt(y);
	if(x==y)return;
	fa[x]=y,sz[y]+=sz[x],vs[y]|=vs[x]; 
}
typedef long long ll;
ll C2(int x){return(x*1ll*(x-1))/2;}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	register int i;
	for(i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		vs[x]=1;
	}
	for(i=1;i<=n;i++)sz[i]=1;
	for(i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		merge(x,y);
	}
	ll ans=0,mxt=0,S=0;
	for(i=1;i<=n;i++)if(rt(i)==i)
	{
		if(vs[i])
		{
			ans+=C2(sz[i]);
			mxt=std::max(mxt,(ll)sz[i]);
		}
		else S+=sz[i];
	}
	printf("%lld\n",ans+C2(S)+mxt*S-m);
	
}
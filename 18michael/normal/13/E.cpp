#include<cstdio>
#include<cmath>
int n,m,S,T;
int st[318],ed[318],p[100002],to[100002],tim[100002];
inline int min(int x,int y)
{
	return x<y? x:y;
}
int main()
{
	scanf("%d%d",&n,&m),S=sqrt(n),T=(n-1)/S+1;
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=T;i;--i)
	{
		st[i]=(i-1)*S+1,ed[i]=min(i*S,n);
		for(int j=ed[i];j>=st[i];--j)
		{
			if(j+p[j]>ed[i])to[j]=min(j+p[j],n+1),tim[j]=1;
			else to[j]=to[j+p[j]],tim[j]=tim[j+p[j]]+1;
		}
	}
	for(int opt,x,y,z;m--;)
	{
		scanf("%d%d",&opt,&x);
		if(opt)
		{
			for(y=0;(y+=tim[x]) && (to[x]<=n);x=to[x]);
			while(x+p[x]<=n)x+=p[x];printf("%d %d\n",x,y);
		}
		else
		{
			scanf("%d",&y),p[x]=y,z=(x-1)/S+1;
			for(int i=x;i>=st[z];--i)
			{
				if(i+p[i]>ed[z])to[i]=min(i+p[i],n+1),tim[i]=1;
				else to[i]=to[i+p[i]],tim[i]=tim[i+p[i]]+1;
			}
		}
	}
	return 0;
}
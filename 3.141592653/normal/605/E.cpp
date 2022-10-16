#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n;
int p[1111][1111];
typedef double db;
db dis[1111],poss[1111];
bool vis[1111];
void flush(int x)
{
	register int i;
	for(i=1;i<=n;i++)
		if(!vis[i])
			if(p[i][x])
				dis[i]+=dis[x]*poss[i]*(p[i][x]/100.0),poss[i]*=(100-p[i][x])/100.0;
}
int main()
{
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<=n;i++)
		for(ii=1;ii<=n;ii++)
			scanf("%d",p[i]+ii),poss[i]=1,dis[i]=(i!=n);
	vis[n]=1;
	int nw=n;
	for(i=1;i<n;i++)
	{
		db mn=2e18;int pos=1;
		flush(nw);
		for(ii=1;ii<=n;ii++)
			if(!vis[ii])mn>dis[ii]/(1-poss[ii])?(mn=dis[ii]/(1-poss[ii]),pos=ii):0;
		vis[pos]=1,nw=pos,dis[pos]/=(1-poss[pos]);
		if(pos==1)break;
	}printf("%.15lf\n",dis[1]);
}
/*
Just go for it.
*/
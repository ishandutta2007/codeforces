#include<bits/stdc++.h>
using namespace std;
int n,q,sq,t,lastans=0;bool ok;
int a[100002],nx[100002],la[100002],st[322],to[100002]={};
int cnt[322][100002]={};
inline void Build()
{
	for(int i=1,j,x=nx[0];i<=t;++i)for(to[st[i]=x]=i,j=sq;j && x<=n;--j,x=nx[x])++cnt[i][a[x]];
}
inline void Link(int x,int y)
{
	nx[x]=y,la[y]=x;
}
inline int Find(int x)
{
	//printf("Find %d ",x);
	int y=st[(x-1)/sq+1];
	for(x=(x-1)%sq;x;--x)y=nx[y];
	//printf("is ok\n");
	return y;
}
inline int Get(int x)
{
	//printf("Get %d ",x);
	while(!to[x])x=la[x];
	//printf("is ok\n");
	return to[x];
}
inline void Modify(int x,int y)
{
	//printf("MDF %d %d\n",x,y);
	to[st[x]]=0,st[x]=y,to[st[x]]=x;
	//printf(" to[5]=%d\n",to[5]);
}
int main()
{
	scanf("%d",&n),sq=sqrt(n),t=(n-1)/sq+1,Link(n,n+1);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),Link(i-1,i);
	Build(),scanf("%d",&q);
	for(int o,x,y,z,gx,gy;q--;)
	{
		scanf("%d%d%d",&o,&x,&y),x=(x+lastans-1)%n+1,y=(y+lastans-1)%n+1;
		if(x>y)swap(x,y);
		gx=Get(x=Find(x)),gy=Get(y=Find(y));
		if(o==1)
		{
			if(x==y)continue;
			if(ok=(st[gx]==x))to[x]=0;
			if(gx!=gy)
			{
				++cnt[gx][a[y]],--cnt[gy][a[y]];
				for(int i=gx;i<gy;++i)to[st[i+1]]=0;
				for(int i=gx;i<gy;++i)to[st[i+1]=la[st[i+1]]]=i+1,--cnt[i][a[st[i+1]]],++cnt[i+1][a[st[i+1]]];
			}
			if(ok)to[st[gx]=y]=gx;
			gx=la[y],gy=nx[y],Link(la[x],y),Link(y,x),Link(gx,gy);
			
			/*printf("A:");for(int i=nx[0];i<=n;i=nx[i])printf("%d ",a[i]);puts("");
			printf("st:");for(int i=1;i<=t;++i)printf("%d ",st[i]);puts("");
			printf("nx:");for(int i=0;i<=n;++i)printf("%d ",nx[i]);puts("");
			printf("la:");for(int i=0;i<=n;++i)printf("%d ",la[i]);puts("");
			printf("to:");for(int i=0;i<=n;++i)printf("%d ",to[i]);puts("");
			printf("cnt:");for(int i=1;i<=t;++i)printf("(%d,%d,%d,%d)",cnt[i][2],cnt[i][4],cnt[i][7],cnt[i][8]);puts("");
			//printf("cnt:");for(int i=1;i<=t;++i)printf("(%d,%d,%d,%d,%d)",cnt[i][2],cnt[i][4],cnt[i][5],cnt[i][6],cnt[i][7]);puts("");
			puts("==========================");*/
		}
		else
		{
			scanf("%d",&z),z=(z+lastans-1)%n+1,lastans=0;
			//printf("!! %d %d %d %d\n",x,y,gx,gy);
			if(gx==gy)
			{
				for(;;x=nx[x])
				{
					lastans+=(a[x]==z);
					if(x==y)break;
				}
			}
			else
			{
				//printf(" %d %d\n",x,y);
				for(;!to[x];x=nx[x])lastans+=(a[x]==z)/*,printf("!x %d %d\n",x,a[x])*/;
				for(;;y=la[y])
				{
					lastans+=(a[y]==z);
					//printf("!y %d %d\n",y,a[y]);
					if(to[y])break;
				}
				for(;x!=y;x=st[to[x]+1])lastans+=cnt[to[x]][z];
			}
			printf("%d\n",lastans);
			//printf("                                      ans:%d\n",lastans);
		}
	}
	return 0;
}
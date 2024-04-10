#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005;
int t,T,n,m,i,j,k,head[N],adj[N*2],nxt[N*2],l[N],r[N],w1,w2,lt[5],rt[5],p[5][N],cnt[5],bl[N],col[N];
void dfs(int x,int c)
{
	p[c][++cnt[c]]=x;
	col[x]=c;
	lt[c]=max(lt[c],l[x]),rt[c]=min(rt[c],r[x]);
	for(int y=head[x];y;y=nxt[y])
		if(!col[adj[y]])
			dfs(adj[y],c==1?2:1);
		else if(col[adj[y]]==col[x])
			j=0;
}
int main()
{
	scanf("%d%d",&t,&T);
	scanf("%d%d",&n,&m);
	w1=T,w2=0;
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",l+i,r+i);
		w1=min(w1,r[i]);
		w2=max(w2,l[i]);
	}
	if(w1+w2<t)
		w2+=t-(w1+w2);
	else if(w1+w2>T)
		w1-=w1+w2-T;
	if(w1<0||w2<0)
	{
		printf("IMPOSSIBLE");
		return 0;
	}
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	for(i=1,j=1;i<=n;++i)
		if(!col[i])
		{
			lt[1]=lt[2]=0,rt[1]=rt[2]=T;
			cnt[1]=cnt[2]=0;
			dfs(i,1);
			if(lt[1]>rt[1]||lt[2]>rt[2])
			{
				j=0;
				break;
			}
			if(rt[1]<w1||lt[1]>w1)
			{
				if(rt[1]<w2||lt[1]>w2||rt[2]<w1||lt[2]>w1)
				{
					j=0;
					break;
				}
				for(k=1;k<=cnt[1];++k)
					bl[p[1][k]]=2;
				for(k=1;k<=cnt[2];++k)
					bl[p[2][k]]=1;
			}
			else if(rt[1]<w2||lt[1]>w2)
			{
				if(rt[1]<w1||lt[1]>w1||rt[2]<w2||lt[2]>w2)
				{
					j=0;
					break;
				}
				for(k=1;k<=cnt[1];++k)
					bl[p[1][k]]=1;
				for(k=1;k<=cnt[2];++k)
					bl[p[2][k]]=2;
			}
			else if((rt[2]<w1||lt[2]>w1)&&(rt[2]<w2||lt[2]>w2))
			{
				j=0;
				break;
			}
			else if(lt[2]<=w2&&rt[2]>=w2)
			{
				for(k=1;k<=cnt[1];++k)
					bl[p[1][k]]=1;
				for(k=1;k<=cnt[2];++k)
					bl[p[2][k]]=2;
			}
			else
			{
				for(k=1;k<=cnt[1];++k)
					bl[p[1][k]]=2;
				for(k=1;k<=cnt[2];++k)
					bl[p[2][k]]=1;
			}
		}
	if(!j)
	{
		printf("IMPOSSIBLE");
		return 0;
	}
	puts("POSSIBLE");
	printf("%d %d\n",w1,w2);
	for(i=1;i<=n;++i)
		printf("%d",bl[i]);
	return 0;
}
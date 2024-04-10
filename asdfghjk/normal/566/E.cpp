#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bitset>
using namespace std;
int n,q,K,i,j,k,x,y,head[1005],adj[2005],nxt[2005],l;
bitset<1005> b[1005],c[1005];
bool v[1005],g[1005][1005];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&K);
		while(K--)
		{
			scanf("%d",&j);
			b[i][j]=1;
		}
	}
	if(n==2)
	{
		printf("1 2");
		return 0;
	}
	for(i=1;i<=n;++i)
		if(b[i].count()!=n)
			break;
	if(i>n)
	{
		for(i=2;i<=n;++i)
			printf("1 %d\n",i);
		return 0;
	}
	for(i=1;i<=n;++i)
		for(j=i+1;j<=n;++j)
			if((b[0]=(b[i]&b[j])).count()==2)
			{
				x=b[0]._Find_first();
				y=b[0]._Find_next(x);
				if(g[x][y])
					continue;
				adj[++l]=y;
				nxt[l]=head[x];
				head[x]=l;
				adj[++l]=x;
				nxt[l]=head[y];
				head[y]=l;
				v[x]=v[y]=true;
				g[x][y]=g[y][x]=true;
				printf("%d %d\n",x,y);
			}
	if(l==2)
	{
		for(k=1;b[k].count()==n;++k);
		for(i=1;i<=n;++i)
			if(!v[i])
			{
				if(b[k][i])
					printf("%d %d\n",i,x);
				else
					printf("%d %d\n",i,y);
			}
		return 0;
	}
	for(i=1;i<=n;++i)
		if(v[i])
		{
			c[i][i]=1;
			for(j=head[i];j;j=nxt[j])
				c[i][adj[j]]=1;
		}
	b[0].reset();
	for(i=1;i<=n;++i)
		if(v[i])
			b[0][i]=1;
	for(i=1;i<=n;++i)
		if(!v[i])
		{
			for(j=1,k=0;j<=n;++j)
				if(b[j][i]&&(k==0||b[j].count()<b[k].count()))
					k=j;
			for(j=1;j<=n;++j)
				if(v[j]&&b[k][j]&&((b[k]&b[0])^c[j]).count()==0)
				{
					printf("%d %d\n",i,j);
					break;
				}
		}
	return 0;
}
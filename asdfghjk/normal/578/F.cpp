#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,md,id[105][105],cnt,tot,dg,pg,i,j,k,x,y,g[2005][2005],pt[20005],p[20005];
char s[105][105];
int find(int x)
{
	return !p[x]?x:p[x]=find(p[x]);
}
int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
int main()
{
	scanf("%d%d%d",&n,&m,&md);
	for(i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	cnt=0;
	for(i=0;i<=n;++i)
		for(j=0;j<=m;++j)
			if((i+j)%2==0)
				id[i][j]=++cnt;
	for(i=1;i<=cnt;++i)
		p[i]=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(s[i][j]=='\\')
			{
				if(id[i][j])
				{
					if(find(id[i][j])==find(id[i-1][j-1]))
						dg=-1;
					else
						p[find(id[i][j])]=find(id[i-1][j-1]);
				}
			}
			else if(s[i][j]=='/')
			{
				if(id[i][j-1])
				{
					if(find(id[i][j-1])==find(id[i-1][j]))
						dg=-1;
					else
						p[find(id[i][j-1])]=find(id[i-1][j]);
				}
			}
	tot=0;
	for(i=1;i<=cnt;++i)
		if(find(i)==i)
			pt[i]=++tot;
	if(tot>201||dg==-1)
		dg=0;
	else
	{
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(s[i][j]=='*')
			{
				if((i+j)%2==0)
					x=pt[find(id[i][j])],y=pt[find(id[i-1][j-1])];
				else
					x=pt[find(id[i][j-1])],y=pt[find(id[i-1][j])];
				g[x][x]++,g[y][y]++,g[x][y]--,g[y][x]--;
			}
	for(i=1;i<=tot;++i)
		for(j=1;j<=tot;++j)
			g[i][j]=(g[i][j]%md+md)%md;
	dg=1;
	for(i=1;i<tot;++i)
	{
		for(j=i+1;j<tot;++j)
			while(g[j][i])
			{
				x=1ll*g[i][i]*pw(g[j][i],md-2)%md;
				for(k=i;k<tot;++k)
					g[i][k]=(g[i][k]-1ll*g[j][k]*x%md+md)%md;
				for(k=i;k<tot;++k)
					swap(g[i][k],g[j][k]);
				dg=(md-dg)%md;
			}
		dg=1ll*dg*g[i][i]%md;
	}
	}
	cnt=0;
	for(i=0;i<=n;++i)
		for(j=0;j<=m;++j)
			id[i][j]=0;
	for(i=0;i<=n;++i)
		for(j=0;j<=m;++j)
			if((i+j)%2==1)
				id[i][j]=++cnt;
	for(i=1;i<=cnt;++i)
		p[i]=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(s[i][j]=='\\')
			{
				if(id[i][j])
				{
					if(find(id[i][j])==find(id[i-1][j-1]))
						pg=-1;
					else
						p[find(id[i][j])]=find(id[i-1][j-1]);
				}
			}
			else if(s[i][j]=='/')
			{
				if(id[i][j-1])
				{
					if(find(id[i][j-1])==find(id[i-1][j]))
						pg=-1;
					else
						p[find(id[i][j-1])]=find(id[i-1][j]);
				}
			}
	tot=0;
	for(i=1;i<=cnt;++i)
		if(find(i)==i)
			pt[i]=++tot;
	if(tot>201||pg==-1)
		pg=0;
	else
	{
	for(i=1;i<=tot;++i)
		for(j=1;j<=tot;++j)
			g[i][j]=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(s[i][j]=='*')
			{
				if((i+j)%2==1)
					x=pt[find(id[i][j])],y=pt[find(id[i-1][j-1])];
				else
					x=pt[find(id[i][j-1])],y=pt[find(id[i-1][j])];
				g[x][x]++,g[y][y]++,g[x][y]--,g[y][x]--;
			}
	for(i=1;i<=tot;++i)
		for(j=1;j<=tot;++j)
			g[i][j]=(g[i][j]%md+md)%md;
	pg=1;
	for(i=1;i<tot;++i)
	{
		for(j=i+1;j<tot;++j)
			while(g[j][i])
			{
				x=1ll*g[i][i]*pw(g[j][i],md-2)%md;
				for(k=i;k<tot;++k)
					g[i][k]=(g[i][k]-1ll*g[j][k]*x%md+md)%md;
				for(k=i;k<tot;++k)
					swap(g[i][k],g[j][k]);
				pg=(md-pg)%md;
			}
		pg=1ll*pg*g[i][i]%md;
	}
	}
	printf("%d",(dg+pg)%md);
	return 0;
}
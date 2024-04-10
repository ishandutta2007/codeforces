#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
struct bbian
{
	int u,v,nex;
}a[800004];
int head[200005],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int dep[200005];
vector<int>v[2];
int siz[2];
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	v[dep[x]%2].push_back(x);
	siz[dep[x]%2]++;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		dfs(a[i].v,x);
	}
}
int p[200005];
int logg[200005];
int main()
{
	logg[1]=0;
	for(int i=2;i<=200000;i++)logg[i]=logg[i>>1]+1;
	int t,n,x,y,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		for(int i=1;i<=n-1;i++)
		{
			x=read();
			y=read();
			addb(x,y);
			addb(y,x);
		}
		dfs(1,0);
		k=(1<<(logg[n]));
		//for(int i=0;i<siz[0];i++)printf("%d ",v[0][i]);
		//printf("\n");
	//	for(int i=0;i<siz[1];i++)printf("%d ",v[1][i]);
		//printf("\n");
		if(siz[0]>=siz[1])
		{
			for(int j=n;j>=k;j--)
			{
				p[v[0][siz[0]-1]]=j;
				siz[0]--;
			}
		}
		else
		{
			for(int j=n;j>=k;j--)
			{
				p[v[1][siz[1]-1]]=j;
				siz[1]--;
			}
		}
		k=logg[n];
		for(int i=k-1;i>=0;i--)
		{
			if(siz[0]&(1<<i))
			{
				for(int j=(1<<(i+1))-1;j>=(1<<i);j--)
				{
					p[v[0][siz[0]-1]]=j;
					siz[0]--;
				}
			}
			else
			{
				for(int j=(1<<(i+1))-1;j>=(1<<i);j--)
				{
					p[v[1][siz[1]-1]]=j;
					siz[1]--;
				}
			}
		}
		for(int i=1;i<=n;i++)printf("%d ",p[i]);
		printf("\n");
		v[0].clear();
		v[1].clear();
		siz[0]=siz[1]=0;
		for(int i=1;i<=n;i++)
		{
			head[i]=0;
			dep[i]=0;
			p[i]=0;
		}
		tmp=0;
	}
	return 0;
}
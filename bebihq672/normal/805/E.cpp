#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct Edge{
	int to,next;
}e[606060];
int head[303030],cnt=0;
void add(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
vector<int> ice[303030];
int num[303030],s[303030];
bool vis[303030];
void dfs(int x,int fa)
{
	for(int i=1;i<=s[x];i++)
		vis[i]=0;
	for(int i=0;i<s[x];i++)
	if(num[ice[x][i]]!=0)
		vis[num[ice[x][i]]]=1;
	int j=1;
	for(int i=0;i<s[x];i++)
	if(num[ice[x][i]]==0)
	{
		while(vis[j])
			j++;
		num[ice[x][i]]=j;
		vis[j]=1;
	}
	for(int i=head[x];i!=0;i=e[i].next)
	{
		int to=e[i].to;
		if(to!=fa)
			dfs(to,x);
	}
}
inline int read()
{
    int data=0,w=1; char ch=0;
    while(ch!='-' && (ch<'0' || ch>'9')) ch=getchar();
    if(ch=='-') w=-1,ch=getchar();
    while(ch>='0' && ch<='9') data=data*10+ch-'0',ch=getchar();
    return data*w;
}
int main()
{
	int n,m;
	n=read();
	m=read();
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		s[i]=read();
		ans=max(ans,s[i]);
		for(int j=1;j<=s[i];j++)
			ice[i].push_back(read());
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		u=read();
		v=read();
		add(u,v);
		add(v,u);
	}
	printf("%d\n",ans);
	dfs(1,1);
	for(int i=1;i<=m;i++)
	if(num[i]==0)
		num[i]=1;
	for(int i=1;i<=m;i++)
		printf("%d ",num[i]);
	printf("\n");
	return 0;
}
/*
3 100
0
0
0
1 2
2 3
*/
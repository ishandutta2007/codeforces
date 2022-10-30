#include<bits/stdc++.h>
using namespace std;
int fa[100005],head[100005],Next[100005],adj[100005],k,sta[100005],top,root[100005];
int qhead[100005],qNext[100005],qadj[100005],qnum[100005],dep[100005];
int q2head[100005],q2Next[100005],q2adj[100005],q2num[100005];
int ans[100005],v,e,n,m,i;
vector<int> a[100005];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void qPush(int u,int v,int w)
{
	qNext[++k]=qhead[u];
	qhead[u]=k;
	qadj[k]=v;
	qnum[k]=w;
}
void q2Push(int u,int v,int w)
{
	q2Next[++k]=q2head[u];
	q2head[u]=k;
	q2adj[k]=v;
	q2num[k]=w;
}
void dfs(int i)
{
	int j;
	sta[++top]=i;
	for(j=qhead[i];j!=0;j=qNext[j])
		if(qadj[j]<top)
			q2Push(sta[top-qadj[j]],qadj[j],qnum[j]);
	for(j=head[i];j!=0;j=Next[j])
	 	dfs(adj[j]);
	top--;
}
void dfs2(int i)
{
	int j,u=n+1;
	dep[i]=1;
	for(j=head[i];j!=0;j=Next[j])
	{
		dfs2(adj[j]);
		if(dep[adj[j]]>dep[u])
			u=adj[j];
		dep[i]=max(dep[i],dep[adj[j]]+1);
	}
	if(u==n+1)
		root[i]=i;
	else
		root[i]=root[u];
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=u)
		{
			int p=a[root[adj[j]]].size()-1;
			int q=a[root[i]].size()-1;
			for(;p>=0;p--,q--)
				a[root[i]][q]+=a[root[adj[j]]][p];
		}
	if(i!=0)
		for(j=q2head[i];j!=0;j=q2Next[j])
			ans[q2num[j]]=a[root[i]][a[root[i]].size()-q2adj[j]];
	a[root[i]].push_back(1);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&fa[i]);
		Push(fa[i],i);
	}
	scanf("%d",&m);
	k=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&v,&e);
		qPush(v,e,i);
	}
	k=0;
	dfs(0);
	dfs2(0);
	for(i=1;i<=m;i++)
		if(ans[i]!=0)
			printf("%d ",ans[i]-1);
		else
			printf("0 ");
}
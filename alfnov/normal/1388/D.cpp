#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int a;
	long long b;
	bool operator<(const apple &other)const
	{
		return b<other.b;
	}
	apple(int a=0,long long b=0):a(a),b(b){}
};
vector<int>g[200005];
long long ans=0,a[200005],c[200005];
int b[200005],deg[200005],q[200005],q2[200005],hs[200005],tot=0;
priority_queue<apple>pq[200005];
queue<int>qq[200005];
void dfs(int x)
{
	if(hs[x])return;
	while(qq[x].size())
	{
		int r=qq[x].front();
		qq[x].pop();
		if(r!=x)dfs(r);
		else q2[++tot]=x;
	}
	hs[x]=1;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]!=-1)g[i].push_back(b[i]);
		deg[b[i]]++;
	}
	int head=0,tail=0;
	for(int i=1;i<=n;i++)if(!deg[i])q[++tail]=i;
	for(int i=1;i<=n;i++)pq[i].push(apple(i,a[i]));
	while(head<tail)
	{
		int pp=q[++head];
		while(pq[pp].size())
		{
			int s=pq[pp].top().a;
			long long ss=pq[pp].top().b;
			if(ss<=0)break;
			if(s!=pp)qq[pp].push(s);
			pq[pp].pop();
			if(s!=pp)a[pp]+=ss;
		}
		qq[pp].push(pp);
		c[pp]=a[pp];
		while(pq[pp].size())
		{
			int s=pq[pp].top().a;
			long long ss=pq[pp].top().b;
			if(s!=pp)qq[pp].push(s);
			pq[pp].pop();
			if(s!=pp)a[pp]+=ss;
		}
		for(int i=0;i<g[pp].size();i++)
		{
			int cu=g[pp][i];
			deg[cu]--;
			pq[cu].push(apple(pp,c[pp]));
			if(!deg[cu])q[++tail]=cu;
		}
	}
	for(int i=1;i<=n;i++)if(b[i]==-1)dfs(i);
	long long anss=0;
	for(int i=1;i<=n;i++)anss+=c[i];
	cout<<anss<<endl;
	for(int i=1;i<=n;i++)cout<<q2[i]<<" ";
	return 0;
}
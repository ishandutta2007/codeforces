#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN=1005;

int n;
vector<int> G[MAXN];

int root,size[MAXN],weight[MAXN];
void findw(int u,int pa)
{
	size[u]=1;
	for(auto v:G[u])
	{
		if(v==pa)continue;
		findw(v,u);
		size[u]+=size[v];
		weight[u]=max(weight[u],size[v]);
	}
	weight[u]=max(weight[u],n-size[u]);
	if(!root || weight[u]<weight[root])root=u;
}

ll val[MAXN],f[MAXN];
void dfs(int u,int pa,int mul)
{
	f[u]=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==pa)continue;
		dfs(v,u,mul);
		val[v]=(f[u]+1)*mul;
		f[u]+=f[v]+1;
	}
}
void print(int u,int pa)
{
	for(auto v:G[u])
	{
		if(v==pa)continue;
		printf("%d %d %d\n",u,v,(int)min(1000000ll,val[v]));
		print(v,u);
	}
}

bool cmp(int x,int y){return size[x]<size[y];}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int u,v;
    scanf("%d",&n);
    if(n==1)return 0;
    for(int i=1;i<n;i++)
    {
    	scanf("%d%d",&u,&v);
    	G[u].push_back(v);
    	G[v].push_back(u);
    }
    findw(1,-1);
    findw(root,-1);
    sort(G[root].begin(),G[root].end(),cmp);
    ll sum=0,best=n,pos=0;
    for(int i=0;i<G[root].size();i++)
    {
    	sum+=size[G[root][i]];
    	if(abs(sum-n/2)<best)pos=i,best=abs(sum-n/2);
    }
    sum=0;
    for(int i=0;i<=pos;i++)
    {
    	val[G[root][i]]=(sum+1);
    	dfs(G[root][i],root,1);
    	sum+=f[G[root][i]]+1;
    }
    ll mul=sum+1;
    sum=0;
    for(int i=pos+1;i<G[root].size();i++)
    {
    	val[G[root][i]]=(sum+1)*mul;
    	dfs(G[root][i],root,mul);
    	sum+=f[G[root][i]]+1;
    }
    print(root,-1);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N=200005;
vector<int> v[N];
vector<int> tree[N];
vector<int> depth(N,-1);
vector<bool> d(N,0);
vector<long long> w(N,0);
vector<long long> path(N,0);
long long best=0;

void dfs(int a,int p=-1)
{
    depth[a]=(p==-1?0:(depth[p]+1));
    for(int to:v[a])
    {
        if(to==p) continue;
        if(depth[to]==-1)
        {
            dfs(to,a);
            tree[a].push_back(to);
            if(d[to]) d[a]=1;
        }
        else d[a]=1;
    }
}

void solve(int a)
{
    for(int to:tree[a])
    {
        solve(to);
        path[a]=max(path[a],path[to]);
    }
    path[a]+=w[a];
}

void check(int a)
{
    if(d[a]==0) best=max(best,path[a]);
    else
    {
        for(int to:tree[a]) check(to);
    }
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%I64d",&w[i]);
	for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int s;
    scanf("%d",&s);
    dfs(s);
    long long res=0;
    for(int i=1;i<=n;i++) if(d[i]) res+=w[i];
    solve(s);
    check(s);
    printf("%I64d\n",res+best);
	return 0;
}
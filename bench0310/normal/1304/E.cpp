#include <bits/stdc++.h>

using namespace std;

const int N=100005;
vector<int> v[N];
vector<int> depth(N,0);
vector<vector<int>> p(N,vector<int>(18,0));

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<=17;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
    }
}

int lca(int a,int b)
{
    if(depth[a]<depth[b]) swap(a,b);
    for(int i=17;i>=0;i--)
    {
        if(depth[p[a][i]]>=depth[b]) a=p[a][i];
    }
    if(a==b) return a;
    for(int i=17;i>=0;i--)
    {
        if(p[a][i]!=p[b][i])
        {
            a=p[a][i];
            b=p[b][i];
        }
    }
    return p[a][0];
}

int dist(int a,int b)
{
    return depth[a]+depth[b]-2*depth[lca(a,b)];
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y,a,b,k;
        scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
        bool res=0;
        int d=dist(a,b);
        if(((d-k)%2)==0&&d<=k) res=1;
        d=dist(a,x)+1+dist(y,b);
        if(((d-k)%2)==0&&d<=k) res=1;
        d=dist(a,y)+1+dist(x,b);
        if(((d-k)%2)==0&&d<=k) res=1;
        if(res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
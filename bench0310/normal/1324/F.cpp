#include <bits/stdc++.h>

using namespace std;

const int N=200005;
vector<int> v[N];
vector<int> col(N,0);
vector<int> best(N,0);
vector<int> res(N,0);

void dfs(int a,int p=-1)
{
    best[a]=col[a];
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
        if(best[to]>0) best[a]+=best[to];
    }
}

void reroot(int a,int b) //b becomes root
{
    if(best[b]>0) best[a]-=best[b];
    if(best[a]>0) best[b]+=best[a];
    res[b]=best[b];
}

void solve(int a,int p=-1)
{
    for(int to:v[a])
    {
        if(to==p) continue;
        reroot(a,to);
        solve(to,a);
    }
    if(p!=-1) reroot(a,p);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&col[i]);
        if(col[i]==0) col[i]=-1;
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    solve(1);
    for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
    return 0;
}
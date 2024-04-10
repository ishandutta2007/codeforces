#include <bits/stdc++.h>

using namespace std;

const int N=100000;
set<int> v[N];
vector<int> depth(N,0);

void dfs(int a)
{
    for(int to:v[a])
    {
        depth[to]=depth[a]+1;
        dfs(to);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> p(n,-1);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&p[i]);
        v[p[i]].insert(i);
    }
    dfs(0);
    int idx=0;
    for(int i=1;i<n;i++) if(depth[i]>depth[idx]) idx=i;
    while(idx)
    {
        if(idx&&v[p[idx]].size()>=2) break;
        idx=p[idx];
    }
    vector<int> res;
    while(idx)
    {
        while(idx&&v[p[idx]].size()<2) idx=p[idx];
        if(idx==0) break;
        int a=(*v[p[idx]].begin());
        if(a==idx) a=(*v[p[idx]].rbegin());
        v[p[idx]].erase(idx);
        v[a].insert(idx);
        p[idx]=a;
        res.push_back(idx);
    }
    vector<int> vis(n,0);
    for(int i=1;i<n;i++) vis[p[i]]=1;
    int a=0;
    for(int i=0;i<n;i++) if(vis[i]==0) a=i;
    vector<int> id(n);
    for(int i=n-1;i>=0;i--)
    {
        id[i]=a;
        a=p[a];
    }
    for(int i=0;i<n;i++) printf("%d%c",id[i]," \n"[i==n-1]);
    reverse(res.begin(),res.end());
    printf("%d\n",(int)res.size());
    for(int a:res) printf("%d ",a);
    printf("\n");
    return 0;
}
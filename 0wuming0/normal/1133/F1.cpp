#include"bits/stdc++.h"
using namespace std;
int vis[200005];
vector<int>v[200005];
int best,besti;
void solve(int i)
{
    for(vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
    {
        if(vis[*it]==0)
        {
            printf("%d %d\n",*it,i);
            vis[*it]=1;
            solve(*it);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()>best)
        {
            best=v[i].size();
            besti=i;
        }
    }
    vis[besti]=1;
    for(vector<int>::iterator it=v[besti].begin();it!=v[besti].end();++it)
    {
        printf("%d %d\n",*it,besti);
        vis[*it]=1;
    }
    for(vector<int>::iterator it=v[besti].begin();it!=v[besti].end();++it)
    {
        solve(*it);
    }
    return 0;
}
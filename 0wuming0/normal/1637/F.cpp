#include"bits/stdc++.h"
using namespace std;
#define ll long long
int h[200005];
int vis[200005];
ll ans;
int bg;
vector<int>v[200005];
void dfs(int i)
{
    vis[i]=1;
    if(v[i].size()==1&&i!=bg)return;
    int mx=0;
    for(auto j:v[i])if(vis[j]==0)
    {
        dfs(j);
        mx=max(mx,h[j]);
    }
    if(mx>=h[i])h[i]=mx;
    else ans+=h[i]-mx;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",h+i);
    }
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        if(h[i]>mx)
        {
            mx=h[i];
            bg=i;
        }
        if(v[i].size()==1)
        {
            ans+=h[i];
        }
    }
    dfs(bg);
    if(v[bg].size()!=1)
    {
        int mx1=0,mx2=0;
        for(auto j:v[bg])
        {
            if(mx1<h[j])swap(mx1,h[j]);
            if(mx2<h[j])swap(mx2,h[j]);
        }
        ans+=h[bg]-mx2;
    }
    cout<<ans<<endl;
    return 0;
}
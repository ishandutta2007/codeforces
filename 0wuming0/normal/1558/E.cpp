#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[1005],b[1005];
int vis[1005];
int ok[1005];
vector<int>v[1005];
void clr(int x)
{
    while(1)
    {
        x=vis[x];
        if(ok[x])break;
        else ok[x]=1;
    }
}
int n,m;
void dfs(int i,int last,ll ans)
{//cout<<"<<<"<<i<<" "<<last<<" "<<ans<<endl;
    for(auto j:v[i])if(ans>a[j])
    {
        if(vis[j]==0)
        {
            vis[j]=i;
            dfs(j,i,ans+b[j]);
        }
        else if(j!=last)
        {
            ok[i]=1;
            ok[j]=1;
        }
    }
}
bool solve(int ans)
{//cout<<"!!!"<<ans<<endl;
    for(int i=2;i<=n;i++)ok[i]=0;
    ok[1]=1;
    vector<int>p;
    ll now=ans;
    int ln=0;
    while(1)
    {
        p.clear();now=ans;
        for(int i=1;i<=n;i++)
        {
            vis[i]=ok[i];
            if(ok[i])
            {
                p.push_back(i);
                now+=b[i];
            }
        }
        if(p.size()==n)return true;
        if(p.size()==ln)return false;
        ln=p.size();
        for(auto i:p)dfs(i,i,now);
        for(int i=2;i<=n;i++)if(ok[i])clr(i);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=2;i<=n;i++)cin>>a[i];
        for(int i=2;i<=n;i++)cin>>b[i];
        vis[1]=ok[1]=1;
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int l=0,r=1e9+1;
        while(l+1!=r)
        {
            int x=l+r>>1;
            if(solve(x))r=x;
            else l=x;
        }
        cout<<r<<endl;
        for(int i=0;i<=n;i++)
        {
            vis[i]=ok[i]=0;
            v[i].clear();
        }
    }
    return 0;
}
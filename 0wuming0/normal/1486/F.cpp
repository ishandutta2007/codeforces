#include"bits/stdc++.h"
using namespace std;
#define ll long long
int vis[300005];
vector<int>v[300005];
int save[300005],nn;
int fa[21][300005];
int deep[300005];
void dfs(int i)
{
    vis[i]=1;
    save[nn++]=i;
    deep[i]=nn;
    for(auto j:v[i])if(vis[j]==0)dfs(j);
    nn--;
    for(int j=1,cnt=0;j<=nn;j<<=1)
    {
        fa[cnt++][i]=save[nn-j];
    }
}
vector<pair<int,int> >savepr[300005];
ll dp[300005];
ll ans;
void lca(int a,int b)
{
    dp[a]++;
    dp[b]++;
    if(deep[a]!=deep[b])
    {
        if(deep[a]<deep[b])swap(a,b);
        while(deep[a]-1!=deep[b])
        {
            int k=0;
            while(deep[fa[k][a]]>deep[b])k++;
            k--;
            a=fa[k][a];
        }
        if(fa[0][a]==b)
        {
            savepr[b].push_back(make_pair(a,b));
            dp[b]-=2;
            return;
        }
        a=fa[0][a];
    }
    if(a==b)savepr[b].push_back(make_pair(a,b));
    else
    {
        while(fa[0][a]!=fa[0][b])
        {
            int k=0;
            while(fa[k][a]!=fa[k][b])k++;
            k--;
            a=fa[k][a];
            b=fa[k][b];
        }
        savepr[fa[0][b]].push_back(make_pair(a,b));
        b=fa[0][b];
    }
    dp[b]-=2;
}
void solve(int i)
{
    vis[i]=1;
    ll sum=0;
    for(auto j:v[i])if(vis[j]==0)
    {
        solve(j);
        sum+=dp[j];
    }
    dp[i]+=sum;
    for(auto pr:savepr[i])
    {
        if(pr.first!=i)dp[pr.first]--,sum--;
        if(pr.second!=i)dp[pr.second]--,sum--;
    }
    for(auto pr:savepr[i])
    {
        ll k=dp[i];
        if(pr.first!=i)k-=dp[pr.first];
        if(pr.second!=i)k-=dp[pr.second];
        ans+=k;
    }
    ans+=savepr[i].size()*(savepr[i].size()-1ll)/2;
    map<int,int>mp;
    map<pair<int,int>,int>mp2;
    for(auto pr:savepr[i])
    {
        if(pr.first!=i&&pr.second!=i)
        {
            if(pr.first>pr.second)swap(pr.first,pr.second);
            if(mp2.find(pr)==mp2.end())mp2[pr]=1;
            else mp2[pr]++;
        }
        if(pr.first!=i)
        {
            if(mp.find(pr.first)==mp.end())mp[pr.first]=1;
            else mp[pr.first]++;
        }
        if(pr.second!=i)
        {
            if(mp.find(pr.second)==mp.end())mp[pr.second]=1;
            else mp[pr.second]++;
        }
    }
    for(auto pr:mp)ans-=pr.second*(pr.second-1ll)/2;
    for(auto pr:mp2)ans+=pr.second*(pr.second-1ll)/2;
}
int main()
{
    int n,m;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        lca(a,b);
    }
    for(int i=1;i<=n;i++)vis[i]=0;
    solve(1);
    cout<<ans<<endl;
    return 0;
}
/*
3
1 2
2 3
10
1 1
2 2
3 3
1 2
2 3
1 3
1 3
2 3
1 2
3 3
*/
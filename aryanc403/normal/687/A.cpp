//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
#define MOD 1000000007
    LLI T,n,in,i,m,j,k,x,y,l,sz[100005],setno[100005],cnt[2];
    vector < LLI > ed[100005];
    vector <LLI> ans[2];
    bool poss;
    bool vis[100005];

bool cmp(const pair<LLI,LLI> &a,const pair<LLI,LLI> &b)
{
    return a.Y<b.Y;
}

bool bs(vector <LLI> &a, LLI n,LLI x)
{
    LLI l,m,r;
    l=0;
    r=n-1;
    while(l<=r)
    {
        m=l+(r-l)/2;
        if(a[m]==x)
        {
            return true;
        }
        else if(a[m]<x)
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    return false;
}

void dfs(LLI u,LLI c)
{
    //cout<<u<<"u c"<<c<<endl;
    if(setno[u])
    {
        if(setno[u]!=c+1)
        {
            poss=false;
        }
        return;
    }
    //vector < LLI > :: iterator it;
    vis[u]=true;
    setno[u]=c+1;
    cnt[c]++;
    ans[c].pb(u);
    for(LLI i=0;i<sz[u]&&poss;++i)
    {
        dfs(ed[u][i],(c+1)%2);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
        //a.clear();
        //a.reserve(n);
        
        fo(i,m)
        {
            cin>>x>>y;
            ed[x].pb(y);
            ed[y].pb(x);
            sz[x]++;
            sz[y]++;
        }
    poss=true;
    
    for(i=1;i<=n;++i)
    {
        if(vis[i])
        {
            continue;
        }
        dfs(i,0);
    }
    
    if(poss==false)
    {
        cout<<-1;
        return 0;
    }
    
    cout<<cnt[0]<<endl;
    fo(i,cnt[0])
        cout<<ans[0][i]<<" ";
    cout<<endl;
    
    cout<<cnt[1]<<endl;
    fo(i,cnt[1])
        cout<<ans[1][i]<<" ";
    cout<<endl;
    return 0;
}
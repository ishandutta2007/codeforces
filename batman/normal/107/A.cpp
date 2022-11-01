//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.1 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;

ll n,m,minim=INF,now,p;
pair <ll,ll> e[N];
struct mehrdad
{
    ll a,b,c;
};
queue <ll> q;
bool vo[N];
mehrdad ans[N];

void dfs(int x)
{
    if(vo[x]==1 && e[x].first==0)
    {
        ans[p].a=now;
        ans[p].b=x;
        ans[p].c=minim;
        minim=INF;
        p++;
        return ;
    }
    if(e[x].second<minim)
        minim=e[x].second;
    dfs(e[x].first);    
    
}

int main()
{ 
    IB
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        e[a]={b,c};
        vo[b]=true;
    }
    for(int i=1;i<=n;i++)
        if(e[i].first!=0 && vo[i]==0)
            q.push(i);
    while(!q.empty())
    {
        now=q.front();
        dfs(now);
        q.pop();
    }
    cout<<p<<endl;
    for(int i=0;i<p;i++)
        cout<<ans[i].a<<" "<<ans[i].b<<" "<<ans[i].c<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (201*1000)
#define INF ((ll)1e9)

ll n,m,k,s,a[N],b[N],mini[2][N],id[2][N];
vector <ll> p[2];
vector <pair<ll,ll> > q[2];

bool check(ll x)
{
    ll res=-1;
    for(int i=0;i<=k;i++)
    {
        if(p[0].size()<=i || p[1].size()<=k-i)
            continue;
        if(res==-1 || p[0][i]*mini[0][x]+p[1][k-i]*mini[1][x]<res)
            res=p[0][i]*mini[0][x]+p[1][k-i]*mini[1][x]; 
    }
    if(res==-1)return 0;
    return res<=s;  
}

int main()
{
    cin>>n>>m>>k>>s;
    mini[0][0]=mini[1][0]=INF;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<mini[0][i-1])
            mini[0][i]=a[i],id[0][i]=i;
        else mini[0][i]=mini[0][i-1],id[0][i]=id[0][i-1];   
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]<mini[1][i-1])
            mini[1][i]=b[i],id[1][i]=i;
        else mini[1][i]=mini[1][i-1],id[1][i]=id[1][i-1];   
    }
    for(int i=1;i<=m;i++)
    {
        ll x,y;
        cin>>x>>y;
        q[x-1].push_back({y,i});
    }
    sort(q[0].begin(),q[0].end());
    sort(q[1].begin(),q[1].end());
    p[0].push_back(0),p[1].push_back(0);
    for(ll i=0,sum=0;i<q[0].size();i++)
    {
        sum+=q[0][i].first;
        sum=min(sum,INF);
        p[0].push_back(sum);
    }
        
    for(ll i=0,sum=0;i<q[1].size();i++)
    {
        sum+=q[1][i].first;
        sum=min(sum,INF);
        p[1].push_back(sum);
    }
        
    
    ll l=0,r=n+1;
    while(l<r-1)
    {
        ll mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid;  
    }
    if(r==n+1)
        return cout<<-1,0;
    cout<<r<<"\n";
    for(int i=0;i<=k;i++)
    {
        if(p[0].size()<=i || p[1].size()<=k-i)
            continue;
        if((p[0][i]*mini[0][r]+p[1][k-i]*mini[1][r])<=s)
        {
            for(int j=0;j<i;j++)
                cout<<q[0][j].second<<" "<<id[0][r]<<"\n";
            for(int j=0;j<k-i;j++)
                cout<<q[1][j].second<<" "<<id[1][r]<<"\n";  
            return 0;       
        }   
        
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (4444)
#define MOD ((ll)1e9+7)

ll x,y,x2,y2,n;
map <pair<ll,ll>,ll> dis;

int main()
{
    cin>>x>>y>>x2>>y2>>n;
    for(int i=0;i<n;i++)
    {
        ll r,a,b;
        cin>>r>>a>>b;
        for(int j=a;j<=b;j++)
            dis[{r,j}]=-1;
    }
    queue <pair<ll,ll> > q;
    q.push({x,y});
    dis[{x,y}]=0;
    while(q.size())
    {
        pair <ll,ll> p=q.front();
        q.pop();
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++)
                if(dis[{p.first+i,p.second+j}]==-1)
                    dis[{p.first+i,p.second+j}]=dis[p]+1,q.push({p.first+i,p.second+j});
    }
    cout<<dis[{x2,y2}];
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define N (101*1000)
#define ll int
#define INF ((ll)1e9)

ll n,m,k,s,t,d[N];
bool blue[N];
vector <ll> e[N];

bool check(ll q)
{
    set <pair<ll,ll> > st;
    for(int i=0;i<N;i++)d[i]=INF;
    d[s]=0;
    st.insert({d[s],s});
    while(st.size())
    {
        ll x=st.begin()->second;st.erase(st.begin());
        if(x==t)
            return 1;
        for(int i=0;i<e[x].size();i++)
            if((d[e[x][i]]>d[x]+1|| (blue[e[x][i]] && d[e[x][i]])) && d[x]+1<=q)
                st.erase({d[e[x][i]],e[x][i]}),d[e[x][i]]=((blue[e[x][i]])?0:d[x]+1),st.insert({d[e[x][i]],e[x][i]});
                
    }
    return 0;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        ll v;
        scanf("%d",&v);
        blue[v]=1;
    }
    for(int i=0;i<m;i++)
    {
        ll v,u;
        scanf("%d%d",&v,&u);
        e[v].push_back(u);
        e[u].push_back(v);
    }
    scanf("%d%d",&s,&t);
    ll l=0,r=N;
    while(l<r-1)
    {
        ll mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid;  
    }
    printf("%d",((r==N)?-1:r));
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e9)
#define N (301*1000)

ll n,m;
vector <ll> e[N];
bool mark[N];

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        ll v,u;
        scanf("%d%d",&v,&u);
        e[v].push_back(u);
        e[u].push_back(v);
    }
    for(int i=1;i<=n/2;i++)mark[i]=1;
    
    queue <ll> q;
    for(int i=1;i<=n;i++)
    {
        ll cnt=0;
        for(int j=0;j<e[i].size();j++)
            if(mark[i]==mark[e[i][j]])
                cnt++;
        if(cnt>1)
            q.push(i);      
    }
    while(q.size())
    {
        ll x=q.front();
        q.pop();
        ll cnt=0;
        for(int j=0;j<e[x].size();j++)
            if(mark[x]==mark[e[x][j]])
                cnt++;
        if(cnt<2)continue;
        mark[x]=!mark[x];
        for(int i=0;i<e[x].size();i++)
        {
            ll v=e[x][i];
            cnt=0;
            for(int j=0;j<e[v].size();j++)
                if(mark[v]==mark[e[v][j]])
                    cnt++;
            if(cnt>1)
                q.push(v);          
        }
    }
    for(int i=1;i<=n;i++)printf("%d",mark[i]);
    return 0;
}
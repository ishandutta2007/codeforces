#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (111)
#define INF ((ll)1e9)

ll n,m,num[N][N],d[N],cnt[N];
vector <ll> e[N];


int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll v,u;
        cin>>v>>u;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    queue <ll> q;
    q.push(1);
    num[1][1]=d[1]=cnt[1]=1;
    while(q.size())
    {
        ll x=q.front();
        q.pop();
        num[x][x]=cnt[x];
        for(int i=0;i<e[x].size();i++)
        {
            if(!d[e[x][i]] || d[e[x][i]]==d[x]+1)
            {
                cnt[e[x][i]]+=cnt[x];
                for(int j=1;j<=n;j++)num[e[x][i]][j]+=num[x][j];
            }
            if(!d[e[x][i]])d[e[x][i]]=d[x]+1,q.push(e[x][i]);
        }
    }
    ll maxi=0;
    for(int i=2;i<n;i++)maxi=max(maxi,num[n][i]);
    maxi=max(cnt[n],maxi*2);
    cout<<fixed<<setprecision(12)<<(long double)maxi/cnt[n];
    return 0;
}
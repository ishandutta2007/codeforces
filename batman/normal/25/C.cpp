#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (303)

ll n,k,d[N][N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>d[i][j];
    cin>>k;
    while(k--)
    {
        ll v,u,w,ans=0;
        cin>>v>>u>>w;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],min(d[i][v]+w+d[u][j],d[i][u]+w+d[v][j])),ans+=d[i][j]; 
        cout<<ans/2<<" ";
    }
    return 0;
}
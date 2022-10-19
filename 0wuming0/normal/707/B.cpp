#include"bits/stdc++.h"
using namespace std;
int a[100005],b[100005],c[100005];
int vis[100005];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int ans=2e9;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",a+i,b+i,c+i);
    }
    while(k--)
    {
        int t;
        scanf("%d",&t);
        vis[t]=1;
    }
    for(int i=0;i<m;i++)
    {
        if(vis[a[i]]^vis[b[i]])ans=min(ans,c[i]);
    }
    if(ans==2e9)ans=-1;
    cout<<ans<<endl;
    return 0;
}
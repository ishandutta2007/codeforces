#include"bits/stdc++.h"
using namespace std;
int n,m;
int a[15],b[15];
int vis[15];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        vis[b[i]]=1;
    }
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[a[i]])
        {
            if(flag)cout<<" ";
            else flag=1;
            cout<<a[i];
        }
    }
    return 0;
}
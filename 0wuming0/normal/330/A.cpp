#include"bits/stdc++.h"
using namespace std;
char a[100][100];
int r[100];
int c[100];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        if(a[i][j]=='S')
        {
            r[i]=1;
            c[j]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(r[i]==0)
        {
            for(int j=0;j<m;j++)a[i][j]=1;
        }
    }
    for(int j=0;j<m;j++)
    {
        if(c[j]==0)
        {
            for(int i=0;i<n;i++)a[i][j]=1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]==1)ans++;
    cout<<ans<<endl;
    return 0;
}
#include"bits/stdc++.h"
using namespace std;
int a[105][105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        {
            if((i&1)^(j&1))a[i][j]=1;
            else a[i][j]=0;
        }
        for(int i=1;i<=n/2;i++)for(int j=1;j<=m/2;j++)
        {
            if((i&1)^(j&1))
            {
                a[i*2][j*2]^=1;
                a[i*2-1][j*2]^=1;
                a[i*2][j*2-1]^=1;
                a[i*2-1][j*2-1]^=1;
            }
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
            printf("%d%c",a[i][j]," \n"[j==m]);
    }
    return 0;
}
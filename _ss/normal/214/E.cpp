#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=3e2+5;
int a[maxn][maxn],f[2*maxn][maxn][maxn],n;
int main()
{
    //freopen("ss.inp","r",stdin);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) cin>>a[i][j];
    f[1][1][1]=a[1][1];
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
            for (int t=1;t<=i;t++)
            {
                f[i][j][t]=-1e9;
                for (int u=j-1;u<=j;u++)
                    for (int v=t-1;v<=t;v++)
                    if (u>0 && u<i && v>0 && v<i) f[i][j][t]=max(f[i][j][t],f[i-1][u][v]);
                if (t==j) f[i][j][t]+=a[i-j+1][j]; else f[i][j][t]+=a[i-j+1][j]+a[i-t+1][t];
            }
    }
    for (int i=n+1;i<=2*n-1;i++)
    {
        for (int j=1;j<=2*n-i;j++)
            for (int t=1;t<=2*n-i;t++)
            {
                f[i][j][t]=-1e9;
                for (int u=j;u<=j+1;u++)
                    for (int v=t;v<=t+1;v++) f[i][j][t]=max(f[i][j][t],f[i-1][u][v]);
                if (t==j) f[i][j][t]+=a[n-j+1][j+i-n]; else f[i][j][t]+=a[n-j+1][j+i-n]+a[n-t+1][i+t-n];
            }
    }
    cout<<f[2*n-1][1][1];
    return 0;
}
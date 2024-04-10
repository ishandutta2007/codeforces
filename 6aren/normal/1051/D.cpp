#include <bits/stdc++.h>
using namespace std;
long long tt[2005][1005],td[2005][1005];
int main()
{
    int n,k,i,j;
    cin >> n >>k;
    for (i=0;i<=k;i++)
    {
        for (j=0;j<=n;j++)
        {
            tt[i][j]=0;
            td[i][j]=0;
        }
    }
    for (i=1;i<=n;i++)
    {
        tt[1][i]=1;
        td[1][i]=0;
    }
    for (i=2;i<=k;i++)
    {
        for (j=1;j<=n;j++)
        {
            tt[i][j]=(tt[i][j-1]+tt[i-1][j-1])%998244353;
            tt[i][j]+=td[i][j-1];
            tt[i][j]=tt[i][j]%998244353;
            tt[i][j]+=td[i][j-1];
            tt[i][j]=tt[i][j]%998244353;
            //td[i][j]=2*tt[i-1][j-1]+td[i][j-1]+td[i-2][j-1];
            td[i][j]=(td[i][j-1]+td[i-2][j-1])%998244353;
            td[i][j]+=tt[i-1][j-1];
            td[i][j]=td[i][j]%998244353;
            td[i][j]+=tt[i-1][j-1];
            td[i][j]=td[i][j]%998244353;
            //if (td[i][j]<0 || tt[i][j]<0) cout << "dmm" << endl;
            if (i==2 && j==1) td[i][j]=1;
        }
    }
    cout << (2*tt[k][n]%998244353+2*td[k][n]%998244353)%998244353;
}
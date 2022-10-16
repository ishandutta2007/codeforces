#include <bits/stdc++.h>

#define int long long int
using namespace std;

int a[15][15];

signed main()
{
    int n;
    cin>>n;

    for(int i=1;i<=10;i++)
        a[i][1]=a[1][i]=1;

    int maxim=1;
    for(int i=2;i<=10;i++)
        for(int j=2;j<=10;j++) {
            a[i][j]=a[i][j-1]+a[i-1][j];
            if(i<=n && j<=n && a[i][j]>maxim)
                maxim=a[i][j];
        }

    cout<<maxim<<'\n';
    return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
using namespace std;
typedef long long ll;
typedef long double ld;

char a[300][300];

signed main()
{
    int aa,b,c,d;
    cin>>aa>>b>>c>>d;

    int n=50;
    int m=50;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
    {
        if (i<=n/2 && j<=m/2)
            a[i][j]='A'; else
        if (i<=n/2)
            a[i][j]='B'; else
        if (j<=m/2)
            a[i][j]='C'; else
            a[i][j]='D';
    }

    aa--;
    b--;
    c--;
    d--;

    for (int i=n/2+1;i<=n;i++)
        for (int j=m/2+1;j<=m;j++)
        if (a[i][j]!='A' && a[i-1][j]!='A' && a[i][j-1]!='A' && aa && a[i-1][j-1]!='A' && i%2==0)
        {
            aa--;
            a[i][j]='A';
        }

    for (int i=1;i<=n/2;i++)
        for (int j=1;j<=m/2;j++)
        if (a[i][j]!='D' && a[i-1][j]!='D' && a[i][j-1]!='D' && d && a[i-1][j-1]!='D' && i%2==1)
        {
            d--;
            a[i][j]='D';
        }

    for (int i=n/2+1;i<=n;i++)
        for (int j=1;j<=m/2;j++)
        if (a[i][j]!='B' && a[i-1][j]!='B' && a[i][j-1]!='B' && b && a[i-1][j-1]!='B' && i%2==0)
        {
            b--;
            a[i][j]='B';
        }


    for (int i=1;i<=n/2;i++)
        for (int j=m/2+1;j<=m;j++)
        if (a[i][j]!='C' && a[i-1][j]!='C' && a[i][j-1]!='C' && c && a[i-1][j-1]!='C' && i%2==1)
        {
            c--;
            a[i][j]='C';
        }

    cout<<n<<' '<<m<<'\n';
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            cout<<a[i][j];
        cout<<'\n';
    }
}
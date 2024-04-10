#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long ull;
typedef long double ld;

int aa[100][100],a[100][100],b[100][100];
int n;

bool check()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (a[i][j]!=b[i][j])
        return(0);
    return(1);
}

void rotate_()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            aa[j][n-i+1]=a[i][j];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=aa[i][j];
}

signed main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        for (int j=1;j<=n;j++)
            if (st[j-1]=='X')
            a[i][j]=1;
    }
    for (int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        for (int j=1;j<=n;j++)
            if (st[j-1]=='X')
            b[i][j]=1;
    }

    if (check())
    {
        cout<<"Yes";
        return(0);
    }
    rotate_();
    if (check())
    {
        cout<<"Yes";
        return(0);
    }
    rotate_();
    if (check())
    {
        cout<<"Yes";
        return(0);
    }
    rotate_();
    if (check())
    {
        cout<<"Yes";
        return(0);
    }

    for (int i=1;i<=n;i++)
        for (int j=1;j*2<=n;j++)
        swap(a[i][j],a[i][n-j+1]);

    if (check())
    {
        cout<<"Yes";
        return(0);
    }
    rotate_();
    if (check())
    {
        cout<<"Yes";
        return(0);
    }
    rotate_();
    if (check())
    {
        cout<<"Yes";
        return(0);
    }
    rotate_();
    if (check())
    {
        cout<<"Yes";
        return(0);
    }

    for (int i=1;i<=n;i++)
        for (int j=1;j*2<=n;j++)
        swap(a[i][j],a[i][n-j+1]);

    for (int i=1;i*2<=n;i++)
        for (int j=1;j<=n;j++)
        swap(a[i][j],a[n-i+1][j]);

    if (check())
    {
        cout<<"Yes";
        return(0);
    }
    rotate_();
    if (check())
    {
        cout<<"Yes";
        return(0);
    }
    rotate_();
    if (check())
    {
        cout<<"Yes";
        return(0);
    }
    rotate_();
    if (check())
    {
        cout<<"Yes";
        return(0);
    }

    cout<<"No";
}
/*
*/
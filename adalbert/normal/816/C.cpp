#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define pb push_back
typedef long long ll;
typedef long double ld;
const int arr=300000+10;

int a[200][200],b[200][200];
int n,m;
int check(int u)
{
    int ans=0;
    ans+=u;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            b[i][j]=a[i][j];
    for (int i=1;i<=n;i++)
        b[i][1]-=u;
    for (int i=1;i<=n;i++)
    {
        int k=b[i][1];
        ans+=k;
        for (int j=1;j<=m;j++)
        {
            if (b[i][j]<0) return(1e9);
            b[i][j]-=k;
            if (b[i][j]<0) return(1e9);
        }
    }
    for (int j=1;j<=m;j++)
    {
        int k=b[1][j];
        ans+=k;
        for (int i=1;i<=n;i++)
            if (b[i][j]!=k) return(1e9);
    }

    return(ans);
}

void vuvod (int u)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            b[i][j]=a[i][j];
    for (int i=1;i<=n;i++)
        b[i][1]-=u;
    while (u--)
    {
        cout<<"col"<<' '<<1<<'\n';
    }

    for (int i=1;i<=n;i++)
        for (int j=1;j<=b[i][1];j++)
            cout<<"row"<<' '<<i<<'\n';
    for (int i=1;i<=n;i++)
    {
        int k=b[i][1];
        for (int j=1;j<=m;j++)
        {
            b[i][j]-=k;
        }
    }
    for (int i=2;i<=m;i++)
        while (b[1][i]--)
            cout<<"col"<<' '<<i<<'\n';
}

signed main()
{

    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        cin>>a[i][j];
    int mn=1e9;
    int imn=0;
    for (int i=0;i<=500;i++)
        if (check(i)<mn)
        {
            mn=check(i);
            imn=i;
        }
    if (mn==1e9)
        cout<<-1; else
        {
            cout<<mn<<'\n';
            vuvod(imn);
        }

}
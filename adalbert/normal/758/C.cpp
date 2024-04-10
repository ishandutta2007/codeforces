#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
int n,m,k,a[1000][1000];
signed main()
{
    int x,y;
    cin>>n>>m>>k>>x>>y;
    if (n==1)
    {
        int mx=k/m+(k%m!=0);
        int mn=k/m;
        int ans=k/m+(k%m>=y);
        cout<<mx<<' '<<mn<<' '<<ans;
    } else
    {
        int l=k/((2*n-2)*m);
        for (int i=1;i<=m;i++)
        {
            a[1][i]=l;
            a[n][i]=l;
        }
        for (int i=2;i<n;i++)
            for (int j=1;j<=m;j++)
                a[i][j]=(2*l);
        k%=((2*n-2)*m);
        int np=1;
        int ii=1;
        int jj=1;
        while (k--)
        {
            a[ii][jj]++;
            jj++;
            if (jj>=m+1)
            {
                jj=1;
                ii+=np;
                if (ii>=n+1)
                {
                    ii=n-1;
                    np=-1;
                }
            }
        }
        int mx=0,mn=1e18;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
        {
            mx=max(mx,a[i][j]);
            mn=min(mn,a[i][j]);
        }
        cout<<mx<<' '<<mn<<' '<<a[x][y];
    }
}
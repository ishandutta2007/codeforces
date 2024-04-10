#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
int a[2000][2000],kilkv[2000][2000],kilkb[2000][2000];
///-----------------------------------------------------------------------///
int  main()
{
    fast;
    int n,m;
    ll ans=0;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
    {
        cin>>a[i][j];
        kilkv[i][j]=kilkv[i][j-1]+a[i][j];
        kilkb[i][j]=kilkb[i-1][j]+a[i][j];
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        if (a[i][j]==0)
        {
            if (kilkv[i][j]!=0) ans++;
            if (kilkv[i][m]!=kilkv[i][j]) ans++;
            if (kilkb[i][j]!=0) ans++;
            if (kilkb[n][j]!=kilkb[i][j]) ans++;
            //cout<<i<<' '<<j<<' '<<ans<<'\n';
        }
    cout<<ans;
}
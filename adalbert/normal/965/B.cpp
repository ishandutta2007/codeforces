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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int arr=3e5+100;
const int base=31;

int a[300][300],cnt[300][300];

signed main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        for (int j=1;j<=n;j++)
            if (st[j-1]=='#')
            a[i][j]=1;
    }


    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];

    for (int i=1;i<=n;i++)
        for (int j=k;j<=n;j++)
            if (a[i][j]-a[i-1][j]-a[i][j-k]+a[i-1][j-k]==0)
            {
                for (int l=0;l<k;l++)
                    cnt[i][j-l]++;
            }

    for (int i=k;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (a[i][j]-a[i-k][j]-a[i][j-1]+a[i-k][j-1]==0)
        {
            for (int l=0;l<k;l++)
                cnt[i-l][j]++;
        }

    int mx=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        mx=max(mx,cnt[i][j]);

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (cnt[i][j]==mx)
    {
        cout<<i<<' '<<j;
        return(0);
    }
}
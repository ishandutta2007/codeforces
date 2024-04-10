#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int base=3;
const ll INF=1e18;
const int md=1e9+9;
const int arr=1e5+10;

int dp[5100][5100],pref[5100][5100];
int ans[5100],a[5100];

int get(int a, int b)
{
    if (a>b)
        return(0);
    return(b-a+1);
}

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    a[0]=-1e18;
    a[n+1]=-1e18;

    int k=(n+1)/2;

    for (int i=0;i<=n;i++)
        for (int j=0;j<=k;j++)
        dp[i][j]=1e18,pref[i][j]=1e18;

    for (int i=0;i<=k;i++)
        ans[i]=1e18;

    for (int i=0;i<=n;i++)
    {
        dp[i][0]=0;
        pref[i][0]=0;
        ans[0]=0;
    }


    for (int j=1;j<=k;j++)
        for (int i=1;i<=n;i++)
        {
            if (i==1 && j==1)
            {
                dp[i][j]=0;
            } else
            if (j==1)
            {
                dp[i][j]=get(a[i],a[i-1]);
            } else
            {
                if (i>=2)
                    dp[i][j]=min(dp[i][j],dp[i-2][j-1]+max(get(a[i-2],a[i-1]),get(a[i],a[i-1])));
                if (i>=3)
                    dp[i][j]=min(dp[i][j],pref[i-3][j-1]+get(a[i],a[i-1]));
            }

            pref[i][j]=min(pref[i-1][j],dp[i][j]+get(a[i],a[i+1]));
            ans[j]=min(ans[j],pref[i][j]);
        }

    for (int i=1;i<=k;i++)
        cout<<ans[i]<<' ';
}
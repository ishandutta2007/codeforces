#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int a[10000],dp[2100][2100],sum1[2100],sum2[2100];

int get1(int l, int r)
{
    if (l>r)
        return(0);
    return(sum1[r]-sum1[l-1]);
}

int get2(int l, int r)
{
    if (l>r)
        return(0);
    return(sum2[r]-sum2[l-1]);
}

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for (int i=1;i<=n;i++)
    {
        sum1[i]+=sum1[i-1];
        sum2[i]+=sum2[i-1];
        if (a[i]==1)
            sum1[i]++; else
            sum2[i]++;
    }

    int ans=0;

    for (int i=1;i<=n;i++)
    {
        ans=max(ans,get1(1,i-1)+get2(i,n));
    }
    for (int i=1;i<=n;i++)
    {
        dp[i][i]=1;
        for (int j=i+1;j<=n;j++)
        {
            dp[i][j]=dp[i][j-1];
            if (a[j]==1)
                dp[i][j]=dp[i][j-1]+1; else
                dp[i][j]=max(dp[i][j],get2(i,j));
        }
    }

    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
        {
            //  cout<<i<<' '<<j<<' '<<dp[i][j]+get1(1,i-1)+get2(j+1,n)<<'\n';
            ans=max(ans,dp[i][j]+get1(1,i-1)+get2(j+1,n));
        }


    cout<<ans;
}
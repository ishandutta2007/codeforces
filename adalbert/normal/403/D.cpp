#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
using namespace std;
typedef double ld;
typedef long long ll;
const int arr=5e5;
#define int ll
const int md=1e9+7;

int dp[1005][2][1005],sum[1005][65],c[65][2005],fac[2005];

signed main()
{
    dp[0][0][1]=1;
    for (int j=0;j<=45;j++)
    {
        for (int i=0;i<=1000;i++)
            for (int last=1;i+last<=1000;last++)
            {
                if (i+last<=1000)
                {
                    dp[i+last][(j+1)%2][last+1]+=dp[i][(j)%2][last];
                    dp[i+last][(j+1)%2][last+1]%=md;
                    sum[i+last][j+1]+=dp[i][j%2][last];
                    sum[i+last][j+1]%=md;
                }
                dp[i][j%2][last+1]+=dp[i][j%2][last];
                dp[i][j%2][last+1]%=md;
            }
        for (int i=0;i<=1000;i++)
            for (int last=1;i+last<=1000;last++)
            dp[i][j%2][last]=0;
    }
    fac[0]=1;
    for (int i=1;i<=1000;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=md;
    }
    
    for (int i=0;i<=1000;i++)
        for (int j=0;j<=60;j++)
        {
            sum[i][j]*=fac[j];
            sum[i][j]%=md;
        }
    c[0][0]=1;
    c[0][1]=1;
    c[1][1]=1;
    for (int i=2;i<=2000;i++)
        for (int j=0;j<=min(ll(60),i);j++)
        {
            c[j][i]=c[j-1][i-1]*(j!=0)+c[j][i-1];
            c[j][i]%=md;
        }
    int m;
   // cout<<sum[60][1]<<'\n';
    cin>>m;
    while (m--)
    {
        int n,k;
        cin>>n>>k;
        if (k>50)
        {
            cout<<0<<'\n';
        } else 
        {
            int ans=0;
            for (int i=0;i<=n;i++)
            {
                ans+=(sum[i][k]*c[k][n-i+k])%md;
                ans%=md;
                //cout<<(sum[i][k]*c[k][n-i+k])%md<<'\n';
            }
            //if (ans==1829) cout<<n<<k<<'\n'; else 
            cout<<ans<<'\n';
        }
    }
}
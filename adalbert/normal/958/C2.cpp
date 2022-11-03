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

const int arr=3e5;
const int base=257;

int dp[20010][52][102];
int a[arr];
signed main()
{
    int n,k,p;
    cin>>n>>k>>p;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    int ans=0;

    for (int i=0;i<=n;i++)
        for (int j=0;j<=k;j++)
        for (int ost=0;ost<=p;ost++)
        dp[i][j][ost]=-1e18;
    dp[0][0][0]=0;

    for (int i=0;i<n;i++)
        for (int j=0;j<k;j++)
            for (int ost=0;ost<p;ost++)
            {
                dp[i+1][j][(ost+a[i+1])%p]=max(dp[i+1][j][(ost+a[i+1])%p],dp[i][j][ost]);
                dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][ost]+(ost+a[i+1])%p);
                if (i+1==n && j+1==k)
                {
                    ans=max(ans,dp[i][j][ost]+(ost+a[i+1])%p);
                }
            }


    cout<<ans;
}
/*
*/
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
#pragma GCC optimize ("O2")
#define int ll
typedef long long ll;
typedef unsigned long long ull;

bool use[10000];
int dp[5010][600];
int c[6000],f[600],h[600];

signed main()
{
    int n,k;
    cin>>n>>k;

    for (int i=1;i<=n*k;i++)
        cin>>c[i];

    for (int i=1;i<=n;i++)
        cin>>f[i];

    for (int i=1;i<=k;i++)
        cin>>h[i];


    for (int j=1;j<=n;j++)
        for (int i=1;i<=n*k;i++)
        {
            for (int pred=i;pred>=max(ll(0),i-k);pred--)
                dp[i][j]=max(dp[i][j],dp[pred][j-1]+h[i-pred]);
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }

    int ans=0;

    for (int i=1;i<=n;i++)
        if (!use[i])
        {
            int cnt1=0;
            int cnt2=0;

            for (int j=1;j<=n;j++)
                if (f[j]==f[i])
            {
                use[j]=1;
                cnt1++;
            }

            for (int j=1;j<=n*k;j++)
                if (c[j]==f[i])
                cnt2++;

            ans+=dp[cnt2][cnt1];
        }

    cout<<ans;
}
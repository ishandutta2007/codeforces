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
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=2e5;

int n,k;
int a[100];
bool dp[60][60];

bool check(int u)
{
    for (int i=0;i<=n;i++)
        for (int j=0;j<=k;j++)
        dp[i][j]=0;

    dp[0][0]=1;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=k;j++)
    {
        int now=0;
        for (int pred=i;pred>0;pred--)
        {
            now+=a[pred];
            if ((now&u)==u && dp[pred-1][j-1])
                dp[i][j]=1;
        }
    }

    return(dp[n][k]);
}

signed main()
{
    cin>>n>>k;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    int ans=0;
    for (int i=56;i>=0;i--)
        if (check(ans+(1ll<<i)))
            ans+=(1ll<<i);

    cout<<ans;
}
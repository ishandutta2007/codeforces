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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

const ll md=1e9+7;

ll pow_(ll a, ll s)
{
    if (s==0)
        return(1);
    if (s%2)
        return(pow_(a,s-1)*a%md); else
        return(pow_(a*a%md,s/2));
}

int dp[5010][5010];

signed main()
{
    int n,k;
    cin>>n>>k;

    dp[0][0]=1;
    for (int i=0;i<=k;i++)
        for (int j=0;j<=k;j++)
        {
            dp[i+1][j+1]+=ll(dp[i][j])*(n-i)%md;
            dp[i+1][j+1]%=md;
            dp[i][j+1]+=ll(dp[i][j])*i%md;
            dp[i][j+1]%=md;
        }
    ll res=0;

    for (int i=0;i<=k;i++)
    {
        if (n-i>=0)
        res+=ll(dp[i][k])*pow_(2,n-i)%md;
        res%=md;
    }


    cout<<res;
}
/*

*/
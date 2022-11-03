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
#define y eth
#pragma GCC optimize ("O3")
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int md=998244353;
const int base=3;
const int arr=2e5+100;

int dp[2][510][510];
int cnt[510];

signed main()
{
    int n,k;
    cin >> n >> k;

    dp[1][1][1]=1;

    for (int i=1;i<n;i++)
    {
        for (int mx=1;mx<n;mx++)
        for (int last=1;last<n;last++)
        {
            dp[(i+1)%2][max(mx,last+1)][last+1]+=dp[i%2][mx][last];
            dp[(i+1)%2][max(mx,last+1)][last+1]%=md;
            dp[(i+1)%2][max(mx,int(1))][1]+=dp[i%2][mx][last];
            dp[(i+1)%2][max(mx,int(1))][1]%=md;
        }

        for (int mx=1;mx<n;mx++)
            for (int last=1;last<n;last++)
                dp[i%2][mx][last]=0;
    }


    for (int i=1;i<=n;i++)
        for (int last=1;last<=n;last++)
        {
            cnt[i]+=dp[n%2][i][last];
            cnt[i]%=md;
        }
    int ans=0;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (i*j<k)
        {
            ans+=ll(cnt[i])*cnt[j]%md;
            ans%=md;
        }
    cout<<ans*2%md;
}
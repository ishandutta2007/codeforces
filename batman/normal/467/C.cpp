//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2 ///////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (5555)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(int x){for(int i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,m,k,a[N],dp[N][N],sum[N];

int Sa1378
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i)
            sum[i]=sum[i-1]+a[i];
        else
            sum[i]=a[i];            
    }
    dp[1][m-1]=sum[m-1];
    for(ll i=m;i<n;i++)
        for(ll j=1;j<=k;j++)
            dp[j][i]=max(dp[j][i-1],sum[i]-sum[i-m]+dp[j-1][i-m]);
    cout<<dp[k][n-1];
    return 0;
}
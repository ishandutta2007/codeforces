//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.1 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] > a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,dp[1001*1000];
int Sa1378
{ 
    IB
    cin>>n;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=INF;
        ll j=i;
        while(j)
        {
            ll ex=j%10;
            if(i-ex>=0)
                dp[i]=min(dp[i],dp[i-ex]+1);
            j/=10;  
        }
    }   
    cout<<dp[n];
    return 0;
}
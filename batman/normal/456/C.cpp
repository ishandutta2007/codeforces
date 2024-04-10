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
ll n,ex,a[200*1000],dp[200*1000];
int Sa1378
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ex;
        a[ex]++;
    }   
    dp[1]=a[1];
    for(int i=2;i<=100*1000;i++)
        dp[i]=max(a[i]*i+dp[i-2],dp[i-1]);
    cout<<dp[100*1000]; 
    return 0;
}
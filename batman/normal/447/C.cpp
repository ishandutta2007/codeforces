//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.8 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define N (101*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI ((ld)3.1415926535897932384626433832795028841971)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define HASH ((ll)1e16+7)
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
ld tavan(ld a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p_,x)-tavan(1-p_,x))/sqr5;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i*i<=x;i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,a[N],dp[N],ans;
int Sa1378
{ 
    IB
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i],dp[i]=((a[i]>a[i-1])?dp[i-1]:0)+1;
    for(int i=1;i<=n;i++)	
    {
    	ll ex=i-dp[i];
    	if(ex>1 && a[ex-1]+1<a[ex+1])
    		ans=max(ans,dp[ex-1]+dp[i]+1);
    	if(ex>0 && a[ex]+1<a[ex+2])
			ans=max(ans,dp[ex]+dp[i]);	
    	ans=max(ans,dp[i]+1);
    }					
    cout<<min(ans,n);	
    return 0;
}
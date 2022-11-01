//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.7 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define N (2200)
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
const ld sqr5=sqrt(5),p=(1+sqr5)/2;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p,x)-tavan(1-p,x))/sqr5;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,k,dp[N][N];
vector <ll> v[N];
int Sa1378
{ 
    cin>>n>>k;
  	for(int i=1;i<=n;i++)
	  	dp[i][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			v[j].PB(i);
			
	for(int k2=2;k2<=k;k2++)
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<v[i].size();j++)
				dp[i][k2]+=dp[v[i][j]][k2-1];
			dp[i][k2]%=MOD;
		}
				
	ll ans=0;			
	for(int i=1;i<=n;i++)
		ans+=dp[i][k],ans%=MOD;
	cout<<ans;			
	return 0;
}
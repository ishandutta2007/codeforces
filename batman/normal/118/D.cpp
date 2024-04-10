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
#define MOD ((ll)1e8)
#define HASH ((ll)1e16+7)
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
const ll L=100;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p_,x)-tavan(1-p_,x))/sqr5;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("output.txt");

ll n1,n2,k1,k2,dp[2][220][220][22];
int Sa1378
{
	IB
	cin>>n1>>n2>>k1>>k2;
	dp[0][0][0][0]=dp[1][0][0][0]=dp[1][0][1][1]=dp[0][1][0][1]=1;
	for(int i=1;i<=n1+n2;i++)
	{
		for(int j1=0;j1<i;j1++)
		{
			ll j2=i-j1-1;
				for(int k=1;k<=k1;k++)
					dp[0][j1+1][j2][k+1]+=dp[0][j1][j2][k],dp[0][j1+1][j2][k+1]%=MOD;
				for(int k=1;k<=k2;k++)
					dp[0][j1+1][j2][1]+=dp[1][j1][j2][k],dp[0][j1+1][j2][1]%=MOD;	
		}
		for(int j2=0;j2<i;j2++)
		{
			ll j1=i-j2-1;	
				for(int k=1;k<=k2;k++)
					dp[1][j1][j2+1][k+1]+=dp[1][j1][j2][k],dp[1][j1][j2+1][k+1]%=MOD;
				for(int k=1;k<=k1;k++)
					dp[1][j1][j2+1][1]+=dp[0][j1][j2][k],dp[1][j1][j2+1][1]%=MOD;	
		}
	}
	//cout<<dp[1][0][1][1]<<endl;
	ll ans=0;
	for(int i=1;i<=k1;i++)
		ans+=dp[0][n1][n2][i];
	for(int i=1;i<=k2;i++)
		ans+=dp[1][n1][n2][i];	
		
	cout<<ans%MOD;	
	return 0;
}
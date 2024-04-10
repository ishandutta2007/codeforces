//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.3 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (100*1001)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
const ll HASH=1e16+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,x[N],h[N],dp[2][N],dp2[N];// left or right...not choosed...
int Sa1378
{ 
    IB
   	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>h[i];
	dp2[0]=0;	
	dp[0][0]=1;
	if(x[0]+h[0]<x[1])
		dp[1][0]=1;
	for(int i=1;i<n;i++)
	{
		dp2[i]=max(dp2[i-1],max(dp[0][i-1],dp[1][i-1]));
		if(x[i-1]<x[i]-h[i])
			dp[0][i]=max(dp[0][i-1],dp2[i-1])+1;
		if(x[i-1]+h[i-1]<x[i]-h[i])
			dp[0][i]=max(dp[0][i],dp[1][i-1]+1);			
		if(x[i]+h[i]<x[i+1] || i==n-1)	
			dp[1][i]=max(dp[0][i-1],max(dp[1][i-1],dp2[i-1]))+1;	
	}		
	cout<<max(dp2[n-1],max(dp[0][n-1],dp[1][n-1]));   		
    return 0;
}
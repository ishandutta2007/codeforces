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
#define N ((ll)1e7+100)
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
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll m,n,a[51000][5],dp[51000][5];
int Sa1378
{ 
	IB
	cin>>m>>n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	dp[0][0]=a[0][0];
	for(int i=1;i<n;i++)
		dp[0][i]=dp[0][i-1]+a[0][i];
	for(int i=1;i<m;i++)
		dp[i][0]=dp[i-1][0]+a[i][0];
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			dp[j][i]=max(dp[j-1][i],dp[j][i-1])+a[j][i];
	for(int i=0;i<m;i++)
		cout<<dp[i][n-1]<<" ";
		
	
	return 0;
}
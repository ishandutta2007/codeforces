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

ll n,k,a[3];
int Sa1378
{ 
	IB
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		ll ex;
		cin>>ex;
		if(ex<k)
			a[0]++;
		else if(ex==k)
			a[1]++;	
		else
			a[2]++;	
	}
	if(a[0]>=ceil((ld)n/2))
	{
		cout<<((a[1])?a[0]-(a[2]+a[1]-1):1+a[0]-a[2]);
		return 0;
	}
	if(a[0]+a[1]>=ceil((ld)n/2))
	{
		cout<<0;
		return 0;
	}	
	cout<<a[2]-a[1]-a[0];
	return 0;
}
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
#define N (201*1000)
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
ll n,w,a[N];
int Sa1378
{ 
    IB
    cin>>n>>w;
    for(int i=0;i<2*n;i++)
    	cin>>a[i];
    sort(a,a+2*n);
	ld l=0.0,r=min((ld)a[0]*3*n,min((ld)a[n]/2*3*n,(ld)w));	
	while(l<r)
	{
		ld mid=(double)(l+r)/2;
		if(mid/(ld)(3*n)<=a[0] && mid/(3*n)<=(ld)a[n]/2)
			l=mid;
		else
			r=mid-0.0000000001;	
	}
	cout<<ST(10)<<fixed<<l;
    return 0;
}
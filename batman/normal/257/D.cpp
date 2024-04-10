/*
ID: sa.13781
PROG: prefix
LANG: C++
*/

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
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI 3.1415926535897932384626433832795028841971
const ll MOD=1e9+7;
const ll HASH=1e16+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("prefix.in");
ofstream fout("prefix.out");
ll n,a[101*1000],now;
int Sa1378
{
    IB
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    now=a[n-1];
    a[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
    	if(now>=0)
    		now-=a[i],a[i]=0;
    	else
			now+=a[i],a[i]=1;	
    }
    if(now<0)
    	for(int i=0;i<n;i++)
    		cout<<((a[i]==0)?'+':'-');
    else
		for(int i=0;i<n;i++)
    		cout<<((a[i]==1)?'+':'-');		
    return 0;
}
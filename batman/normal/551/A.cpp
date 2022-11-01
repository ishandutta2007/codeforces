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
#define N (2200)
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

int n,a,res[N];
pair <int,int> p[N];
int Sa1378
{ 
    IB
   	cin>>n;
   	for(int i=0;i<n;i++)
   	{
   		cin>>a;
   		p[i].first=a;
   		p[i].second=i;
   	}
   	sort(p,p+n);
	res[p[n-1].second]=1; 		
   	for(int i=n-2;i>=0;i--)
   	{
   		if(p[i].first==p[i+1].first)
   			res[p[i].second]=res[p[i+1].second];
   		else
		   res[p[i].second]=n-i;	
   	}
   	for(int i=0;i<n;i++)
   		cout<<res[i]<<" ";
    return 0;
}
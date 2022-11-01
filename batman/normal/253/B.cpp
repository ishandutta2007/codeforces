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
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,a[N],ans=INF;
set <pair <ll,int> > s;
int Sa1378
{ 
	IB
	fin>>n;
	for(int i=0;i<n;i++)
		fin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
		s.insert({a[i],i});
	for(ll i=0;i<n-1;i++)
	{
		set <pair <ll,int> >::iterator it=s.upper_bound({2*a[i],n});
		if(it==s.end())
			ans=min(ans,i);
		else
			ans=min(ans,i+n-it->second);		
	}	
	fout<<ans;
	return 0;
}
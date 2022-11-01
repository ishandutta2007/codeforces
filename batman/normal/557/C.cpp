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
#define N (101*1000)
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
ll n,sum,num[220],ans=INF;
pair <ll,ll> p[N];
int Sa1378
{ 
    IB
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>p[i].first;
    for(int i=0;i<n;i++)
	{
		cin>>p[i].second;
		sum+=p[i].second;
	}	
	sort(p,p+n);
	for(ll i=0;i<n;)
	{
		ll j=i+1,ex=sum;
		ex-=p[i].second;
		while(p[j].first==p[j-1].first)
		{
			ex-=p[j].second;
			j++;
		}
		ll rem=min(i,j-i-1);
		for(int k=200;k>0;k--)
		{
			ex-=min(rem,num[k])*k;
			rem-=min(rem,num[k]);
		}
		ans=min(ans,ex);
		for(int k=i;k<j;k++)
			num[p[k].second]++;
		i=j;	
	}
	cout<<ans;
    return 0;
}
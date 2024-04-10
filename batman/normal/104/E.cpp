//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.6 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define N (301*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI 3.1415926535897932384626433832795028841971
#define INF 1e9
#define MOD 1e9+7
#define HASH 1e16+7
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
ld tavan(ld a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p_,x)-tavan(1-p_,x))/sqr5;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,cow[N],p,dp[N],ans[N];
pair <pair <ll,ll>,ll> pir[N];
const ll sqr=sqrt(N);
int Sa1378
{ 
	IB
    cin>>n;
    for(int i=0;i<n;i++)cin>>cow[i];
    cin>>p;
    for(int i=0;i<p;i++)
    {
    	ll a,b;
    	cin>>a>>b;
    	a--;
    	pir[i].first.second=a;
    	pir[i].first.first=b;
    	pir[i].second=i;
    }
    sort(pir,pir+p);
    for(int i=0;i<p;i++)
    {
    	ll a=pir[i].first.second,b=pir[i].first.first,j=pir[i].second;
    	if(b>=sqr)
    		for(int k=a;k<n;k+=b)
    			ans[j]+=cow[k];
    	else
    	{
    		if(i==0 || b!=pir[i-1].first.first)
    			for(int k=n-1;k>=0;k--)
    			{
    				if(b+k>=n)
    					dp[k]=cow[k];
    				else
						dp[k]=cow[k]+dp[b+k];	
    			}
    		ans[j]=dp[a];	
    	}
    }
    for(int i=0;i<p;i++)
    	cout<<ans[i]<<"\n";
    return 0;
}
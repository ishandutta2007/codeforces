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
#define N (201*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI (ld)(3.1415926535897932384626433832795028841971)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define HASH ((ll)1e16+7)
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
ld tavan(ll a,ll b){return b?(tavan(a%MOD*a%MOD,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p_,x)-tavan(1-p_,x))/sqr5;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,q,a[N],cnt[N],ans;
int Sa1378
{ 
	IB
   	cin>>n>>q;
   	for(int i=0;i<n;i++)
   		cin>>a[i];
   	for(int i=0;i<q;i++)
	{
		ll a,b;
		cin>>a>>b;
		cnt[a-1]++;
		cnt[b]--;
	}
	for(int i=1;i<n;i++)
		cnt[i]+=cnt[i-1];
	sort(cnt,cnt+n);
	sort(a,a+n);
	for(int i=0;i<n;i++)
		ans+=cnt[i]*a[i];
	cout<<ans;			
    return 0;
}
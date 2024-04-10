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
#define N (1001*1000)
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
ll A,B,n,sum[N];
int Sa1378
{ 
	IB
    cin>>A>>B>>n;
    for(int i=1;i<=1e6;i++)
    	sum[i]=sum[i-1]+(A+B*(i-1));
    for(int i=0;i<n;i++)
    {
    	ll l_,t,m;
    	cin>>l_>>t>>m;
    	if(A+B*(l_-1)>t)
    	{
    		cout<<-1<<"\n";
    		continue;
    	}
    	ll l=l_,r=1e7;
    	while(l+1<r)
    	{
    		ll mid=(l+r)/2;
    		if(t>=(A+B*(mid-1)) && sum[mid]-sum[l_-1]<=m*t)
    			l=mid;
    		else
				r=mid-1;	
    	}
    	if(A+B*(r-1)<=t && sum[r]-sum[l_-1]<=m*t)
    		cout<<r<<"\n";
    	else
			cout<<l<<"\n";	
    }
    return 0;
}
  ////////////////////////////////////////////////////////////////
 //~~~~~~~~~~~~~~~ Sa1378 Platform Vesion 1.3.5 ~~~~~~~~~~~~~~~//
////////////////////////////////////////////////////////////////


// Don't push me
	// Cause I'm close to the edge
		// I'm trying not to lose my head


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cout << #x << " is " << x << endl;
#define N (220)
#define ll long long
#define ld long double
#define ST(a,b) cout<<fixed<<setprecision((b))<<((ld)a)<<"\n";
#define sin(a) sin(a*PI/180)
#define cos(a) cos(a*PI/180)
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
const ld PI=((ld)2*asin(1));
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll DELTA=((ll)965551);
const ll BIG_HSH=((ll)9999999900000001);
const ll SML_HSH=((ll)100030001);
ll tavan(ll a,ll b){return (b)?(tavan((a)*(a),(b)>>1) * ((b) & 1?(a):1)):1;}
ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
ld fib(ll x){return (tavan(p_,x)-tavan(1-p_,x))/(sqr5);}
ld fib(ll x,ll mod){return (tavan(p_,x,mod)-tavan(1-p_,x,mod))/(sqr5);}
ll gcd(ll a,ll b){while(b ^= a ^= b ^= a = a % b);return a;}
bool isprime(ll x){for(ll i=2;i*i<=(x);i++)if(!((x)%(i)))return false;return true;}
template <class T>  inline void smx(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smn(T &x,T y){ x = min((x), (y));}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,a[N],ans=-INF,k;
int Sa1378
{
	IB
 	cin>>n>>k;
 	
 	for(int i=0;i<n;i++)cin>>a[i];
 	for(int i=0;i<n;i++)for(int j=i;j<n;j++)
 	{
 		ll now=0;
 		vector <ll> p,q;
 		for(int i2=i;i2<=j;i2++)p.PB(a[i2]),now+=a[i2];
 		for(int i2=0;i2<i;i2++)q.PB(a[i2]);
 		for(int i2=j+1;i2<n;i2++)q.PB(a[i2]);
 		sort(p.begin(),p.end());
 		sort(q.begin(),q.end());
 		reverse(q.begin(),q.end());
 		for(int i2=0;i2<min(k,min((ll)p.size(),(ll)q.size()));i2++)
 			if(p[i2]<q[i2])
 				now+=q[i2]-p[i2];
 		smx(ans,now);
	}
	cout<<ans;
 	return 0;
}
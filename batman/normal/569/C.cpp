  ////////////////////////////////////////////////////////////////
 //~~~~~~~~~~~~~~~ Sa1378 Platform Vesion 1.3.2 ~~~~~~~~~~~~~~~//
////////////////////////////////////////////////////////////////


// Don't push me
	// Cause I'm close to the edge
		// I'm trying not to lose my head


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define N (5001*1000)
#define ll long long
#define ld long double
#define ST(a,b) cout<<fixed<<setprecision((b))<<(a)<<"\n";
#define sin(a) sin(a*PI/180)
#define cos(a) cos(a*PI/180)
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI ((ld)2*asin(1))
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define BIG_HSH ((ll)9999999900000001)
#define SML_HSH ((ll)100030001)
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
ll tavan(ll a,ll b){return (b)?(tavan((a)*(a),(b)>>1) * ((b) & 1?(a):1)):1;}
ll tavan(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
ld fib(ll x){return (tavan(p_,x)-tavan(1-p_,x))/(sqr5);}
ll gcd(ll a, ll b){return ((a) < (b)) ? gcd((b), (a)) : (((a) % (b) == 0) ? (b) : gcd((b), (a) % (b)));}
bool isprime(ll x){for(ll i=2;i*i<=(x);i++)if(!((x)%(i)))return false;return true;}
bool chckmd(ll a,ll mod,ll b){if((a-b)>=0 && !((a-b)%(mod)))return 1;return 0;}
template <class T>  inline void smx(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smn(T &x,T y){ x = min((x), (y));}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,prime[N],pali[N],p,q;
bool mark[N];

bool palind(ll x)
{
	ll v[10],tmp=0;
	while(x)
	{
		v[tmp++]=x%10;
		x/=10;
	}
	for(int i=0;i<tmp/2;i++)
		if(v[i]!=v[tmp-i-1])
			return 0;
	return 1;		
}

int Sa1378
{ 
    IB
    cin>>p>>q;
    for(int i=2;i<N;i++)
    {
    	if(!mark[i])
    	{
    		for(int j=i*2;j<N;j+=i)
    			mark[j]=1;
    		prime[i]++;	
    	}
    	prime[i]+=prime[i-1];	
    }
    for(int i=1;i<N;i++)
		pali[i]=pali[i-1]+(palind(i));	
	
	for(int i=N-1;i>=1;i--)
		if((ld)prime[i]*q<=p*(ld)pali[i])
			return cout<<i,0;		
	
	cout<<"Palindromic tree is better than splay tree";	
	//cout<<pali[172]<<" "<<prime[172]<<endl;		
    return 0;
}
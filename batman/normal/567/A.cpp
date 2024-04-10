  ////////////////////////////////////////////////////////////////
 //~~~~~~~~~~~~~~~~ Sa1378 Platform Vesion 1.3 ~~~~~~~~~~~~~~~~//
////////////////////////////////////////////////////////////////


// Don't push me
	// Cause I'm close to the edge
		// I'm trying not to lose my head


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define N (201*1000)
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
#define HASH ((ll)1e16+7)
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
ld tavan(ld a,ll b){return (b)?(tavan((a)*(a),(b)>>1) * ((b) & 1?(a):1)):1;}
ld fib(ll x){return (tavan(p_,x)-tavan(1-p_,x))/(sqr5);}
ll gcd(ll a, ll b){return ((a) < (b)) ? gcd((b), (a)) : (((a) % (b) == 0) ? (b) : gcd((b), (a) % (b)));}
bool isprime(ll x){for(ll i=2;i*i<=(x);i++)if(!((x)%(i)))return false;return true;}
bool chckmd(ll a,ll mod,ll b){if((a-b)>=0 && !((a-b)%(mod)))return 1;return 0;}
template <class T>  inline void smx(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smn(T &x,T y){ x = min((x), (y));}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,a[N];
int Sa1378
{ 
    IB
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>a[i];
    sort(a,a+n);
	cout<<abs(a[0]-a[1])<<" "<<abs(a[0]-a[n-1])<<"\n";	
    for(int i=1;i<n-1;i++)
    {
    	cout<<min(abs(a[i]-a[i-1]),abs(a[i+1]-a[i]))<<" "<<max(abs(a[i]-a[0]),abs(a[i]-a[n-1]))<<"\n";
    }
    cout<<abs(a[n-2]-a[n-1])<<" "<<abs(a[0]-a[n-1])<<"\n";
    return 0;
}
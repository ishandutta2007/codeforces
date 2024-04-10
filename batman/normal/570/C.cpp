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
#define N (101*1000)
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
ll n,m,dp[301*1000],last[301*1000],ans;
string s;

int Sa1378
{ 
    IB
	cin>>n>>m>>s;
	for(int i=0;i<n-1;i++)
	{
			ll p=0;
			if(s[i]=='.' && s[i+1]=='.')
			{
				while(p+i<n && s[p+i]=='.')
				p++,ans++;		
			ans--;
			i+=p-1;
			dp[i]=p;
			last[i]=i-p+1;
			dp[i-p+1]=p;
			}
				
	}
	
	for(int i=0;i<m;i++)
	{
		ll a;
		char c;
		cin>>a>>c;
		a--;
		if(a>0 && a<n-1)
		{
			if(c=='.' && s[a]!='.')
			{
				if(s[a-1]=='.')
					ans++;
				if(s[a+1]=='.')
					ans++;	
			}
			else if(c!='.' && s[a]=='.')
			{
				if(s[a-1]=='.')
					ans--;
				if(s[a+1]=='.')
					ans--;
			}			
		}
		else if(a==n-1)
		{
			if(c=='.' && s[a]!='.' && s[a-1]=='.')
				ans+=1;
			else if(c!='.' && s[a]=='.' && s[a-1]=='.')
				ans-=1;
		}
		else
		{
			if(c=='.' && s[a]!='.' && s[a+1]=='.')
				ans+=1;
			else if(c!='.' && s[a]=='.' && s[a+1]=='.')
				ans-=1;
		}
		s[a]=c;	
		cout<<ans<<"\n";
	}		
	
					
    return 0;
}
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
#define N (2200)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI ((ld)3.1415926535897932384626433832795028841971)
#define INF ((ll)1e9)
#define MOD ((ll)12391)
#define HASH ((ll)1e16+7)
const ld sqr5=sqrt(5),p=(1+sqr5)/2;
ld tavan(ld a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p,x)-tavan(1-p,x))/sqr5;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,m;
string s[110];

bool check(ll x)
{
	while(x>1)
	{
		if(x%2)
			return 0;
		x/=2;	
	}
	return 1;
}

int Sa1378
{ 
    IB
    cin>>n>>m;
	if(n%2)
	{
		cout<<n;
		return 0;
	}			 
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			char c;
			cin>>c;
			s[i]+=c;
		}
	for(int p=1;p<=n;p++)
	{
		if(n%p)
			continue;
		bool mark=1;
		for(int i=p,tmp=0;i<n;i+=p,tmp++)
		{
			if(tmp%2==0)
			{
				for(int j=i+p-1,j2=0;j>=i;j2++,j--)
					if(s[j]!=s[j2])
					{
						mark=0;
						break;
					}	
			}
			else
			{
				for(int j=i;j<i+p;j++)
					if(s[j]!=s[j-i])
					{
						mark=0;
						break;
					}	
			}
			if(mark==0)
				break;
		}
		if(mark==1 && check(n/p))
		{
			cout<<p<<endl;
			return 0;
		}
	}		
			           
    return 0;
}
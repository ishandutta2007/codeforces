//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.8 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define N (1100)
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
const ld sqr5=sqrt(5),p_=(1+sqr5)/2;
ld tavan(ld a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p_,x)-tavan(1-p_,x))/sqr5;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
char s1[200100],s2[200100];

bool check(char* s1,char* s2,int n)
{
	if(strncmp(s1,s2,n)==0)
		return 1;
	if(n&1)
		return 0;		
	n>>=1;	
	if((check(s1,s2+n,n) && check(s1+n,s2,n)) || (check(s1,s2,n) && check(s1+n,s2+n,n)))
		return 1;
	return 0;				 
}

int Sa1378
{
    cin>>s1>>s2;
    if(check(s1,s2,strlen(s1)))
    	cout<<"YES";
    else
		cout<<"NO";	
	return 0;
}
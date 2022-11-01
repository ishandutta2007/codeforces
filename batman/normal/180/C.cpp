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

ll ans=MOD,a[N],m;
string s;
int Sa1378
{ 
    IB
   	cin>>s;
   	if('A'<=s[0] && s[0]<='Z')
   		a[0]++,m++;
   	for(int i=1;i<s.size();i++)
   		a[i]=a[i-1]+('A'<=s[i] && s[i]<='Z'),m+=('A'<=s[i] && s[i]<='Z');
   	
   	for(int i=0;i<s.size();i++)
	   	ans=min(ans,(i+1-a[i])+(m-a[i]));
	cout<<min(ans,min(m,s.size()-m));	   	
   	
    return 0;
}
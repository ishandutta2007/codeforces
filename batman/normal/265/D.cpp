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
#define N (101*1000)
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
int n,a[N],dp[N],dp2[N];
bool mark[N];
vector <int> divi[N];
int Sa1378
{ 
    IB
    for(int i=2;i<N;i++)
    	for(int j=i;j<N;j+=i)
    		divi[j].PB(i);		
    cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(mark[a[i]]==1)
			i--,n--;
		mark[a[i]]=1;	
	}
		
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<divi[a[i]].size();j++)
			dp[a[i]]=max(dp[a[i]],dp2[divi[a[i]][j]]+1);
		for(int j=0;j<divi[a[i]].size();j++)
			dp2[divi[a[i]][j]]=max(dp2[divi[a[i]][j]],dp[a[i]]);		
	}
	int ans=0;
	for(int i=0;i<N;i++)
		ans=max(ans,dp[i]);
	cout<<max(ans,1);					
    return 0;
}
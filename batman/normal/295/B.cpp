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
#define N ((ll)1e6+1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI ((ld)3.1415926535897932384626433832795028841971)
#define INF ((ll)1e9)
#define MOD ((ll)10937)
#define HASH ((ll)1e16+7)
const ld sqr5=sqrt(5),p=(1+sqr5)/2;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p,x)-tavan(1-p,x))/sqr5;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,a[550][550],x[550],ans[550];
bool mark[550];
int Sa1378
{ 
    
    //cout<<(1<<1);
    cin>>n;
    for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
    for(int i=0;i<n;i++)
		cin>>x[i],x[i]--;
    for(int t=n-1;t>=0;t--)
	{
		mark[x[t]]=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=min(a[i][j],a[i][x[t]]+a[x[t]][j]);
		/*		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<a[i][j]<<" ";	
			cout<<"\n";	
		}
		cout<<"\n";	
		*/	
		for(int i=n-1;i>=0;i--)
			for(int j=n-1;j>=0;j--)
				if(mark[i] && mark[j])
					ans[t]+=a[i][j];	
	}	
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
    return 0;
}
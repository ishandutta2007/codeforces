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
#define N (200)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
const ll HASH=1e16+7;
const ll INF=1e9;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll k,a,n,ans=1,tarkib[1101][1101];

ll tarkibb()
{
	for(int i=0;i<=1001;i++)
	{
		tarkib[0][i]=1;
		tarkib[i][0]=1;
		tarkib[i][i]=1;
	}
	for(int i=1;i<=1001;i++)
		for(int j=1;j<=1001;j++)
			if(!tarkib[i][j])
				tarkib[i][j]=tarkib[i-1][j-1]+tarkib[i-1][j],tarkib[i][j]%=MOD;	
}
int Sa1378
{
	IB
	tarkibb();
	cin>>k;
	for(ll i=0;i<k;i++)
	{
		cin>>a;
		if(a==0)
			continue;
		ans*=tarkib[n+a-1][a-1];
		ans%=MOD;
		n+=a;	
	}
	cout<<ans%MOD;
			
	return 0;
}
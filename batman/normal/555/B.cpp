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
#define N (201*1000)
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
bool sortt(pair <pair<ll,ll>,ll> x,pair <pair<ll,ll>,ll> y)
{ 
	if(x.first.second!=y.first.second)
		return x.first.second<y.first.second;
	if(x.first.first!=y.first.first)
		return x.first.first<y.first.first;
	return x.second<y.second;		
}
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,m,a[2][2],ans[N];
pair <pair<ll,ll>,ll> lnd[N];
pair <ll,ll> brg[N];
int Sa1378
{ 
    IB
    cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		a[0][0]=a[1][0],a[0][1]=a[1][1];
		cin>>a[1][0]>>a[1][1];
		if(i==0)
			continue;
		lnd[i-1].first.first=a[1][0]-a[0][1];
		lnd[i-1].first.second=a[1][1]-a[0][0];	
		lnd[i-1].second=i-1;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>brg[i-1].first;
		brg[i-1].second=i;
	}
	sort(lnd,lnd+n-1,sortt);
	sort(brg,brg+m);
	set <pair<ll,ll> > brgs;
	ll point=0;
	for(int i=0;i<n-1;i++)
	{
		for(;point<m && brg[point].first<=lnd[i].first.second;point++)
			brgs.insert({brg[point].first,brg[point].second});
		set <pair<ll,ll> >::iterator it=brgs.lower_bound({lnd[i].first.first,0});
		if(it==brgs.end())
		{
			cout<<"No";
			return 0;
		}
		ans[lnd[i].second]=it->second;
		brgs.erase(*it);
	}
	cout<<"Yes\n";
	for(int i=0;i<n-1;i++)
		cout<<ans[i]<< " ";
    return 0;
}
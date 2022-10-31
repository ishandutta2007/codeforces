//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2 ///////////////////
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
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(int x){for(int i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}

ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,ans,index[N];
pair <ll,ll> p[N];
bool sortt(ll x,ll y){ return abs(p[x].first)+abs(p[x].second) < abs(p[y].first)+abs(p[y].second);}
int Sa1378
{ 
	IB
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>p[i].first>>p[i].second;
    	ans+=(2+2*(p[i].first!=0)+2*(p[i].second!=0));
    	index[i]=i;
    }
    cout<<ans<<"\n";	
    sort(index,index+n,sortt);
    for(int i=0;i<n;i++)
    {
    	if(p[index[i]].first>0)
    		cout<<"1 "<<p[index[i]].first<<" R\n";
    	if(p[index[i]].first<0)
			cout<<"1 "<<(-1)*p[index[i]].first<<" L\n";
		if(p[index[i]].second>0)
			cout<<"1 "<<p[index[i]].second<<" U\n";
		if(p[index[i]].second<0)
			cout<<"1 "<<(-1)*p[index[i]].second<<" D\n";
		cout<<"2\n";
		if(p[index[i]].first>0)
    		cout<<"1 "<<p[index[i]].first<<" L\n";
    	if(p[index[i]].first<0)
			cout<<"1 "<<(-1)*p[index[i]].first<<" R\n";
		if(p[index[i]].second>0)
			cout<<"1 "<<p[index[i]].second<<" D\n";
		if(p[index[i]].second<0)
			cout<<"1 "<<(-1)*p[index[i]].second<<" U\n";
		cout<<"3\n";					
    }
    return 0;
}
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
#define N (2100)
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
const ld sqr5=sqrt(5),p=(1+sqr5)/2;
ld tavan(ld a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p,x)-tavan(1-p,x))/sqr5;}
ll gcd(ll a, ll b){ll tmp;while(b){tmp=b,b=a%b,a=tmp;}return b;}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,x[2],ans[2];
set <pair<pair<ll,ll>,int> > s[2];
bool mark[2][N];
int Sa1378
{ 
    IB
    cin>>n>>x[0];
    x[1]=x[0];
    for(int i=0;i<n;i++)
    {
    	ll t,h,m;
    	cin>>t>>h>>m;
    	s[t].insert({{h,m},i});
    }
    for(int i=0;;i++)
    {
    	set <pair<pair<ll,ll>,int> >::iterator it=s[i%2].upper_bound({{x[0],INF},0}),it3;
		ll max=-1,index=0;
		for(set <pair<pair<ll,ll>,int> >::iterator it2=s[i%2].begin();it2!=it;it2++)
			if(it2->first.second>max && !mark[0][it2->second])
				max=it2->first.second,index=it2->second,it3=it2;
		mark[0][index]=1;	
		if(max==-1)
			break;
		ans[0]++;
		x[0]+=it3->first.second;		
    }
	for(int i=1;;i++)
    {
    	set <pair<pair<ll,ll>,int> >::iterator it=s[i%2].upper_bound({{x[1],INF},0}),it3;
		ll max=-1,index=0;
		for(set <pair<pair<ll,ll>,int> >::iterator it2=s[i%2].begin();it2!=it;it2++)
			if(it2->first.second>max && !mark[1][it2->second])
				max=it2->first.second,index=it2->second,it3=it2;
		mark[1][index]=1;	
		if(max==-1)
			break;
		ans[1]++;
		x[1]+=it3->first.second;		
    }
	cout<<max(ans[0],ans[1])<<endl; 
    return 0;
}
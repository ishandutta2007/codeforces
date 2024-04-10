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
#define N (1100)
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

ll w,n;
vector <ll> v;
int Sa1378
{ 
    IB
    cin>>w>>n;
    ll p=n;
    while(p)
    {
    	v.push_back(p%w);
    	p/=w;
    }
    v.push_back(0);
    v.push_back(0);
    for(int i=0;i<v.size();i++)
    {
    	if(v[i]==1 || v[i]==0)
    		continue;
    	if(v[i]==w-1)
    	{
    		for(int j=i+1;j<=v.size();j++)
    		{
    			v[j]++;
    			if(v[j]!=w)
    				break;
    			v[j]=0;	
    		}
    	}
			
		else
		{
			cout<<"NO";
			return 0;
		}		
    }
	cout<<"YES";	
    return 0;
}
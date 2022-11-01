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
#define N (5000*1000+5)
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

int n,a;
vector <int> v;
int Sa1378
{ 
    IB
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	bool mark=0;
    	for(int j=0;j<n;j++)
    	{
    		cin>>a;
    		if(a==1 || a==3)
    		{
    			mark=1;
    		}
    	}
    	if(!mark)
    		v.PB(i+1);
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    	cout<<v[i]<<" ";
    return 0;
}
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
#define N (1001*1000)
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
ll a,b,k;
bool mark[N];
void erat()
{
	mark[1]=1;
	for(int i=2;i<N;i++)
		if(!mark[i])
			for(int j=2*i;j<N;j+=i)
				mark[j]=1;			
}

bool check(int x)
{
	int ex=0;
	for(int i=a;i<a+x;i++)
		ex+=(!mark[i]);
	if(ex<k)
		return 0;
	for(int i=a+1;i<=b-x+1;i++)
	{
		ex-=(!mark[i-1]);
		ex+=(!mark[i+x-1]);
		if(ex<k)
			return 0;
	}		
	return 1;
}

int Sa1378
{ 
    IB
    cin>>a>>b>>k;
    erat();
    //cerr<<check(2)<<endl;
    int l=k,r=b-a+1;
    while(l<r)
    {
    	int mid=(r+l)/2;
    	if(check(mid))
    		r=mid;
    	else
			l=mid+1;		
    }
    
	if(check(l))
		cout<<l;
	else
		cout<<-1;	
   	
    return 0;
}
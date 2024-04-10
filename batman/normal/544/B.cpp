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
#define N (100*1001)
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

ll n,k;
char s[500][500];
int Sa1378
{ 
    IB
   	cin>>n>>k;
   	if((n%2==0 && k>n*n/2) || (n%2==1 && k>(n*(n-1)/2)+(n/2)+1))
   	{
   		cout<<"NO";
   		return 0;
   	}
   	for(int i=0;i<n;i++)
   		for(int j=0;j<n;j++)
   			s[i][j]='S';
   	for(int i=0;i<n;i++)
	{
		if(i%2==0)
			for(int j=0;j<n;j+=2)
			{
				if(k==0)
					break;
				s[i][j]='L';
				k--;
			}
		else
			for(int j=1;j<n;j+=2)
			{
				if(k==0)
					break;
				s[i][j]='L';
				k--;
			}
		if(k==0)
			break;		
	}		
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<s[i][j];
		cout<<endl;	
	}
		
   	
    return 0;
}
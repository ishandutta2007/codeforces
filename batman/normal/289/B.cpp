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
#define N ((ll)1e7+100)
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
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,m,d,a[110][110],p=-1,ans=INF;
int Sa1378
{ 
	cin>>n>>m>>d;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(p==-1)
				p=a[i][j]%d;
			else if((a[i][j]%d)!=p)
			{
				cout<<-1;
				return 0;
			}	
			a[i][j]/=d;	
		}
	for(int k=0;k<10000;k++)
	{
		ll now=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				now+=abs((ll)k-a[i][j]);
		ans=min(ans,now);		
	}		
	cout<<ans;
	return 0;
}
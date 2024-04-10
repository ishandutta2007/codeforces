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
#define N ((ll)1e6+100)
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

ll k,a[2][N],tmp;
string s;
int Sa1378
{ 
	IB
	cin>>k>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
			tmp++;
		else
			a[1][tmp]++,a[0][tmp+1]++;	
	}
	ll ans=0;
	if(!k)
	{
		for(int i=0;i<=tmp;i++)
			ans+=(a[1][i]+1)*a[1][i]/2;
		cout<<ans;
		return 0;	
	}
	for(int i=k;i<=tmp;i++)
		ans+=(a[1][i]+1)*(a[0][i-k+1]+1);	
	cout<<ans;
	return 0;
}
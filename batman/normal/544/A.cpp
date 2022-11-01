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

ll n,p;
string s;
bool mark[26];
int Sa1378
{ 
    IB
   	cin>>n>>s;
   	for(int i=0;i<s.size();i++)
   		mark[s[i]-'a']=1;
   	for(int i=0;i<26;i++)
		if(mark[i])
			p++,mark[i]=0;
	if(p<n)
	{
		cout<<"NO";
		return 0;
	}		
	cout<<"YES";
	for(int i=0;i<s.size();i++)
	{
		if(n && mark[s[i]-'a']==0)
		{
			cout<<endl;
			n--;
			mark[s[i]-'a']=1;
		}
		cout<<s[i];
	}
    return 0;
}
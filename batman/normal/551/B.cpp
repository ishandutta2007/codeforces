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
#define N (2200)
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

string a,b,c;
ll num[3][26],mini=MOD,maxi,index[2];
int Sa1378
{ 
    IB
   	cin>>a>>b>>c;
   	for(int i=0;i<a.size();i++)
   		num[0][a[i]-'a']++;
	for(int i=0;i<b.size();i++)
		num[1][b[i]-'a']++;
	for(int i=0;i<c.size();i++)
		num[2][c[i]-'a']++;
	for(int i=0;i<b.size();i++)
		mini=min(mini,num[0][b[i]-'a']/num[1][b[i]-'a']);
	
	for(int i=0;i<=mini;i++)
	{
		ll ex[26],mini2=MOD;
		for(int j=0;j<26;j++)
			ex[j]=max(0ll,num[0][j]-i*num[1][j]);
		for(int j=0;j<c.size();j++)
			mini2=min(mini2,ex[c[j]-'a']/num[2][c[j]-'a']);
		if(i+mini2>maxi)
		{
			maxi=i+mini2;
			index[0]=i;
			index[1]=mini2;	
		}	
	}			 	
	for(int i=0;i<index[0];i++)
		cout<<b;
	for(int i=0;i<index[1];i++)
		cout<<c;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<num[0][i]-index[0]*num[1][i]-index[1]*num[2][i];j++)
			cout<<(char)(i+'a');
	}		
    return 0;
}
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
#define N (20)
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
string s;
vector <string> v;
int Sa1378
{ 
    IB
    v.push_back("0");
   	for(int i=1;i<1000;i++)
	{
		if(i%8==0)
		{
			int ex2=i;
			string ex="";
			while(ex2)
				ex+=(ex2%10+'0'),ex2/=10;
			v.PB(ex);	
			
		}
	}  
	cin>>s;
	for(int i=0;i<v.size();i++)
	{
		int p=0;
		for(int j=s.size()-1;j>=0;j--)
		{
			if(s[j]==v[i][p])
				p++;
		}
		if(p==v[i].size())
		{
			cout<<"YES\n";
			for(int q=v[i].size()-1;q>=0;q--)
				cout<<v[i][q];
			return 0;
		}
	}		
	cout<<"NO";
    return 0;
}
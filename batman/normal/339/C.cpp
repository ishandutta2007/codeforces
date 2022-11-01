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
#define N (101*1000)
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
bool mark;
int m,ans[1100],l,r;
vector <int> v;
int Sa1378
{ 
    IB
   	cin>>s>>m;
   	for(int i=0;i<10;i++)
   		if(s[i]=='1')
   			v.PB(i+1);
   	if(!v.size())
	{
		cout<<"NO";
		return 0;
	}
	
	for(int k=0;k<v.size();k++)
	{
		mark=1;
		for(int i=0;i<1100;i++)
			ans[i]=0;	
		l=0;
		r=0;	
		ans[0]=v[k];
		l+=v[k];
		for(int i=1;i<m;i++)
   		{
   			for(int j=0;j<v.size();j++)
   			{
   				if((v[j]!=ans[i-1]) && (((i%2)?r:l)+v[j])>((i%2)?l:r))
   				{
   					((i%2)?r:l)+=v[j];
   					ans[i]=v[j];
   					break;
   				}
   			}
   			
   			if(!ans[i])
   			{
   				mark=0;
   				break;
   			}
   		}
   		if(mark)
   			break;
	}
	if(!mark)
	{
		cout<<"NO";
		return 0;
	}
   	cout<<"YES\n";
   	for(int i=0;i<m;i++)
   		cout<<ans[i]<<" ";
    return 0;
}
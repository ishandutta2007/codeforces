//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2 ///////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (200*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(int x){for(int i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(int x,int y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,m,s1,s2,ex2=-1;
map <ll,pair<ll,ll> > step;
char ex;
int Sa1378
{ 
    cin>>n>>m>>s1>>s2;
    if(s1<s2)
    	ex='R',ex2=1;
    else if(s1>s2)
		ex='L';
	else
		return 0;
	for(int i=0;i<m;i++)
	{
		int t,l,r;
		cin>>t>>l>>r;
		step[t]={l,r};
	}
	for(int i=1;s1!=s2;i++)
	{
		if((s1>=step[i].first && s1<=step[i].second) || (s1+ex2>=step[i].first && s1+ex2<=step[i].second) )
			cout<<"X";
		else
		{
			cout<<ex;
			s1+=ex2;
		}	
	}	
    
    return 0;
}
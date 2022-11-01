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
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD=1e9+7;
const ll HASH=1e16+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,m,a,b,c,d;
char s[501*500];
vector <ll> e[501*500];
ll mark[501*500];

void dfs(ll x)
{
		mark[x]=1;
		if(x==c*m+d )
		{
			ll p=0;
			for(int i=0;i<e[x].size();i++)
				if(mark[e[x][i]]!=1 && s[e[x][i]]=='.')
					p++;
			if(p>0 || s[x]=='X')
			{
				cout<<"YES";
				exit(0);
			}		
		}
		for(int i=0;i<e[x].size();i++)
			if((!mark[e[x][i]] && s[e[x][i]]=='.') || e[x][i]==c*m+d)
				dfs(e[x][i]);
		mark[x]=2;			
}

int Sa1378
{ 
    IB
    cin>>n>>m;
    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		cin>>s[i*m+j];
    
    cin>>a>>b;
	cin>>c>>d;
	a--;
	b--;
	c--;
	d--;
	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	{
    		if(i>0)
    			if(s[(i-1)*m+j]=='.' || (i-1)*m+j==c*m+d)
    				e[i*m+j].push_back((i-1)*m+j);
    		if(j>0)
    			if(s[i*m+j-1]=='.' || i*m+j-1==c*m+d)
    				e[i*m+j].push_back(i*m+j-1);
			if(i<n-1)
				if(s[(i+1)*m+j]=='.' || (i+1)*m+j==c*m+d)
    				e[i*m+j].push_back((i+1)*m+j);				
    		if(j<m-1)
    			if(s[i*m+j+1]=='.' || i*m+j+1==c*m+d)
    				e[i*m+j].push_back(i*m+j+1);	
    	}
	s[a*m+b]='.';		
    dfs(a*m+b);	
    cout<<"NO";	
    return 0;
}
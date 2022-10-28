#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<pair<ll,ll> > > vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

ll n,m;
vvll g;
int main()
{
	IOS;
	cin>>n>>m;
	g=vvll(n+1);
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	vector<bool> vis(n+1,false);
	vector<ll> level(n+1,-1);
	bool check1=true;
	for(ll i=1;i<=n;i++)
	{
		ll s=i;
		if(vis[s])
			continue;
	    queue<int> q;
	    q.push(s);
	    vis[0]=true;
	    vis[s]=true;
	    level[s]=0;
	    level[0]=0;
	    ll countnode=1;
	    ll countedge=0;
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        for(auto it:g[temp])
	        {
	        	countedge++;
	            if(vis[it]==false)
	            {
	            	countnode++;
	                q.push(it);
	                vis[it]=true;
	                level[it]=level[temp]+1;
	                if(level[it]>=2)
	                	check1=false;
	            }
	        }
	    }
	   // trace3(i,countnode,countedge);
	    if(countnode==2||countnode==1)
	    	continue;
	    ll st=countnode*(countnode-1);
	    if(countedge!=st)
	    {
	    //	trace1(i);
	    	check1=false;
		}
	    	
	}
	if(check1)
	 	cout<<"YES";
	else
		cout<<"NO";
	
		
	return 0;
}
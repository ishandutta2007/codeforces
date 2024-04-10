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
typedef long double ld;
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

ll n,t;
vvll g;
vvll par;
vll vis;
vll lvl;
ll D;
vll subtreesize;
vll vis2;

ll dfs(ll k,ll parent)
{
	if(vis2[k])
		return subtreesize[k];
	vis2[k]=1;
	for(auto it:g[k])
	{
		if(it==parent)
			continue;
		subtreesize[k]+=dfs(it,k)+1;
	}
	return subtreesize[k];
}
ll walk(ll i,ll k)
{
	for(ll j=0;j<=D && i!= -1;j++)
	{
		if((1<<j) &  k)
		{
			i=par[i][j];
		}
	}
	return i;
}

ll lca(ll i,ll j)
{
	if(lvl[j]<lvl[i])
	{
		swap(i,j);
	}
	ll diff=lvl[j]-lvl[i];
	j=walk(j,diff);
	if(i==j)
	{
		return i;
	}
	for(ll k=D;k>=0;k--)
	{
		if(par[i][k] != par[j][k])
		{
			i=par[i][k];
			j=par[j][k];
		}
	}
	return par[i][0];
}

ll lca2(ll i,ll j)
{
	if(lvl[j]<lvl[i])
	{
		swap(i,j);
	}
	ll diff=lvl[j]-lvl[i];
	j=walk(j,diff);
	if(i==j)
	{
		return i;
	}
	for(ll k=D;k>=0;k--)
	{
		if(par[i][k] != par[j][k])
		{
			i=par[i][k];
			j=par[j][k];
		}
	}
	return 2+subtreesize[i]+subtreesize[j];
}


ll dist(ll i,ll j)
{
	return lvl[i]+lvl[j] -2 * lvl[lca(i,j)];
}
int main()
{
	IOS;
	cin>>n;
	g=vvll(n+2);
	D=log2(n) + 1;
	par=vvll(n+1,vll(D+1,-1));
	subtreesize=vll(n+1,0);
	for(ll i=0;i<n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	queue<ll> q;
	q.push(1); //Rooting the tree at node 1
	vis=vll(n+1,0);
	lvl=vll(n+1,0);
	vis2=vll(n+1,0);
	vis[1]=1;
	while(!q.empty()) //To store immediate parents and level of nodes
	{
		ll k=q.front();
		q.pop();
		for(auto it:g[k])
		{
			if(!vis[it])
			{
				vis[it]=1;
				q.push(it);
				par[it][0]=k;
				lvl[it]=lvl[k]+1;
			}
		}
	}
	dfs(1,1);
	for(ll k=1;k<=D;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			ll up1=par[i][k-1];
			if(up1!=-1)
			{
				par[i][k]=par[up1][k-1];
			}
		}
	}
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		if(a==b)
		{
			cout<<n<<endl;
			continue;
		}
		if(lvl[a]<lvl[b])
		{
			swap(a,b);
		}
		ll stlca=lca(a,b);
		if(stlca==a||stlca==b)
		{
			ll diff=abs(lvl[a]-lvl[b]);
			if(diff%2)
			{
				cout<<"0"<<endl;
			}
			else
			{
				ll dist=diff/2;
				ll reqdnode=walk(a,dist);
				ll reqdnode2=walk(a,dist-1);
				cout<<subtreesize[reqdnode]-subtreesize[reqdnode2]<<endl;
			}
		}
		else
		{
			ll dista=dist(a,stlca);
			ll distb=dist(b,stlca);
			ll diff=dista-distb;
			if(diff==0)
				cout<<n-(lca2(a,b))<<endl;
			else
			{
				if(abs(diff)%2)
				{
					cout<<"0"<<endl;
					continue;
				}
				if(diff>0)
				{
					ll walk2=dista-diff/2;
					ll reqdnode=walk(a,walk2);
		  			ll reqdnode2=walk(a,walk2-1);
					cout<<subtreesize[reqdnode]-subtreesize[reqdnode2]<<endl;
				}
				else
				{	
					ll walk2=distb-diff/2;
					ll reqdnode=walk(b,walk2);
		  			ll reqdnode2=walk(b,walk2-1);
					cout<<subtreesize[reqdnode]-subtreesize[reqdnode2]<<endl;
				}
			}
				
		}
	}
	return 0;
}
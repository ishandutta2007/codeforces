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
 
const int N=1e5+5;

int n,m,a[N],b[N],x[N],y[N],k[N];
int st[4*N];
int lazy[4*N];

void propagate(int node, int L, int R)
{
	if(L!=R)
	{
		lazy[node+node]=lazy[node];
		lazy[node+node+1]=lazy[node];
	}
	st[node]=lazy[node];
	lazy[node]=-1;
}

void update(int node, int L, int R, int i, int j, int ind)
{
	if(lazy[node]!=-1)
	{
		propagate(node,L,R);
	}
	if(j<L || i>R)
	{
		return;
	}
	if(i<=L && R<=j)
	{
		st[node]=ind;
		if(L!=R)
		{
			lazy[node+node]=ind;
			lazy[node+node+1]=ind;
		}
		return;
	}
	int M=(L+R)>>1;
	update(node+node,L,M,i,j,ind);
	update(node+node+1,M+1,R,i,j,ind);
}

int query(int node, int L, int R, int pos)
{
	if(lazy[node]!=-1)
	{
		propagate(node, L, R);
	}
	if(L==R)
	{
		return st[node];
	}
	int M=(L+R)>>1;
	if(pos<=M)
		return query(node+node,L,M,pos);
	else
		return query(node+node+1,M+1,R,pos);
}
int main()
{
	IOS;
	cin>>n>>m;
	memset(lazy,-1,sizeof(lazy));
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(ll i=1;i<=m;i++)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			cin>>x[i]>>y[i]>>k[i];
			update(1,1,n,y[i],y[i]+k[i]-1,i);
		}
		else
		{
			ll ind;
			cin>>ind;
			ll store=query(1,1,n,ind);
			if(store==0)
			{
				cout<<b[ind]<<endl;
			}
			else
			{
				cout<<a[x[store]-y[store]+ind]<<endl;
			}
		}
	}
	return 0;
}